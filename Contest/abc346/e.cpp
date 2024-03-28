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


int main()
{
    ll h,w,m;
    cin >> h >> w >> m;
    vector<tuple<ll,ll,ll>> query;
    for (ll i = 0; i < m; ++i) {
        ll t,a,x;
        cin >> t >> a >> x;
        a--;
        query.push_back(make_tuple(t,a,x));
    }


    // qeury が 10^5あるので、いちいちシミュレートしていたら追いつかない
    // ある query が意味をなさなくなるのは、その後に別の query がどれくらいくるか
    // 行x を塗った後、その後全ての列が塗られて初めて行xの色が消滅する'

    // これ query を後ろからやった方がいいのでは...?

//    vector<bool> isReaminBlankRow(h,true);
//    vector<bool> isReaminBlankColumn(w,true);
//    vector<vector<ll>> world(h,vector<ll>(w,-1));

//    vector<ll> ReaminBlankBlocksperRow(h,w); // xx 行目の残りブロック数
//    vector<ll> ReaminBlanklocksperColumn(w,h); // xx 列目の残りブロック数
//    map<ll,ll> BlocksperColor;

    ll remainRows = h;
    ll remainColumns = w;

    vector<bool> isPaintedRow(h,false);
    vector<bool> isPaintedColumn(w,false);
    map<ll,ll> BlocksperColor;


    for (int i = m -1 ; i >= 0 ; --i) {
        int type = get<0>(query[i]);
        ll a = get<1>(query[i]);
        ll x = get<2>(query[i]);
//        cerr << "type :" << type << "  pos :"<<a << " color :" << x << endl;

        // 実際塗りつぶしすると 計算量的に NG
        // そもそもマス目をカウントすると NG
        // 0で塗るパターンもある

        if (type == 1) {
            if (isPaintedRow[a] == true)
                continue;
            isPaintedRow[a] = true;
            if (BlocksperColor.find(x) != BlocksperColor.end()) {
                BlocksperColor[x] += remainColumns;
            } else {
                BlocksperColor[x] = remainColumns;
            }
            remainRows--;

        } else {
            if (isPaintedColumn[a] == true)
                continue;
            isPaintedColumn[a] = true;
            if (BlocksperColor.find(x) != BlocksperColor.end()) {
                BlocksperColor[x] += remainRows;
            } else {
                BlocksperColor[x] = remainRows;
            }
            remainColumns--;
        }

//        cerr << "===== " << BlocksperColor.size() << endl;
//        for (auto v:BlocksperColor) {
//            cerr << v.first << " " << v.second << endl;
//        }
        if (remainRows ==0 || remainColumns ==0)
            break;

    }


    // sort + 0 を追加
    ll sum = h * w;
    for (auto v:BlocksperColor) {
        if (v.first != 0) {
            sum-= v.second;
        }
    }
    if (sum > 0)
        BlocksperColor[0] = sum;

    vector<pair<ll,ll>> ans;
    for (auto v:BlocksperColor) {
        if (v.second > 0) {
            ans.push_back(make_pair(v.first,v.second));
        }
    }
    std::sort(ans.begin(), ans.end(),[]( pair<ll,ll> &left,pair<ll,ll> &right ){
        return left.first < right.first;
    });



    cout << ans.size() << endl;
    for (auto v:ans) {
        cout << v.first << " " << v.second << endl;
    }

}
