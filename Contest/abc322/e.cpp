#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define ALL(a) \
    (a) c;     \
    .begin(), (a).end()

const ll mod = 1000000007;
const ll LINF = 1e13;
const ll LLINF = 1e18;
const ll ALPHABET = 26;


// これ冷静に 100^10になるからそりゃダメか...
ll _search(vector<ll>& c, vector<vector<ll>>& a, ll k, ll p,ll n ,ll selected_n,ll depth, vector<ll>& params, ll cost, ll upbound) {
//    cerr << "select development plan i :" << selected_n << "  depth "<< depth << endl;

    ll ans = upbound;
    bool isOverP = true;
    for (int i = 0; i < k; ++i) {
        if (params[i] < p) {
            isOverP = false;
            break;
        }
    }

    if (isOverP) {
//        cerr << "  []find : cost = " << cost << endl;
        return cost;
    }

    if (depth >= 10) { // 0~24 のdepth 足し合わせの25こで届かない時は基本無理と判断
        return LLINF;
    }

    for (int i = selected_n + 1; i < n; ++i) {
        if ((cost + c[i] >= ans))
            continue;

        for (int j = 0; j < k; ++j) {
            params[j] += a[i][j];
        }
//        for (int i = 0; i < k; ++i) {
//            cerr << params[i] << ", ";
//        }cerr << endl;
// この周回で、既に最小コスト以上になっちゃった場合は枝刈り. 例えば既に

        ll tmpans = _search(c,a, k, p, n, i, depth + 1, params, cost + c[i], ans);
        ans = min(tmpans,ans);

        for (int j = 0; j < k; ++j) {
            params[j] -= a[i][j];
        }
    }

    return ans;
}

ll search(vector<ll>& c, vector<vector<ll>>& a, ll k, ll p ) {
    ll ans = -1;
    vector<ll> params(k,0);
    ll tmpans = _search(c,a, k, p,c.size(), -1, 0, params, 0, LLINF);
    if (tmpans != LLINF) {
        ans = tmpans;
    }

    return ans;
}

int main()
{
    ll n, k, p;
    cin >> n >> k >> p;
    vector<ll> c(n);

    vector<vector<ll>> a(n,vector<ll>(k,0));


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            if (j == 0) {
                cin >> c[i];
                continue;
            }
            cin >> a[i][j - 1];
        }
    }
    // 0 ~ n この選択肢からいくつか選んで最小のコストで全部 P 以上にする
    // n < 100
    // k <= 5

    // 数字ちっちゃい
    // 2^100 が全部の組み合わせ -> 10^30
    // 単調性がないので、総当たりが必要そう
    // DP使う場合 1/1, 2/2, 3/4, 4/8, 5/16... って感じで線形にできそう? -> NG
/*

 - - -
     -x
   - -
     -
*/

    // 100Cn で n=1,2,3, となる場合のDPはできる？
    //100C2 は 100C1 + i で求められるが、各kパラメータの確認ができないので単調性がなくてNG

    // P = 0,1,2... となる場合のDPは可能か？
    // P[i] = p[i-1]...p[0]が必要なのできつい？？？？と思わせて、pは最大5しかないので可能か？
    // a[i]の計算がだるすぎてむずそう

    // a[i]というか、pのせいで、単調性が著しく損なわれているのが課題
    // dp 5回やる？
    // 意外と DP のみでいける? aijが全部0のものを弾けば、最大でも 2^25 回の足し算で決まるはずなので 2^20 * 2^5 -> 10^6 * 32 でギリ？

//    全然ダメ


    vector<pair<vector<ll>,ll>> aa(n,pair<vector<ll>,ll>());
    for (int i = 0; i < n; ++i) {
        aa[i] = make_pair(a[i],c[i]);
    }

    sort(aa.begin(), aa.end(),[](pair<vector<ll>,ll> &left, pair<vector<ll>,ll> &right){
        ll left_sum = 0;
        for (auto l:left.first) {
            left_sum+=l;
        }
        ll right_sum = 0;
        for (auto r:right.first) {
            right_sum+=r;
        }
        return (left_sum>right_sum);
    });

    for (int i = 0; i < n; ++i) {
//        cerr << a[i][0] << "," <<  a[i][1] <<"," <<  a[i][2]<<","  << endl;
        a[i] = aa[i].first;
        c[i] = aa[i].second;
    }

    //dp[25][25][25][25][25] みたいなのが必要かも。dp[5][5][5][5][5]以上の空間でコスト最小のものを探せばOKか。
    //5次元だからイメージわかなかったな...




    ll ans = -1;
    // s < t;
    ans = search(c,a,k,p );

    cout << ans << endl;
    return 0;
}
