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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // 区間の数はn + n-1 + n-2 + ... + 1 =  n(n + 1) / 2
    // したがって区間列挙だと多分O(N)超える

    // 小さい区間を大きい区間が含む、その逆もあることから、DP (Graph 上での一方向性)が成り立ちそう
    // DP[区間長さ][開始位置] は？
    // DP[l = 1~n][i( i = 1~n)] = g(DP[l - 1][i],DP[1][i + l - 1]) + g(DP[1][i],DP[l - 1][i + 1])
    // これで全部の区間網羅可能...?可能か

    // g のチェックが O(1 or logn)であればOKだが...

    // あ、この DP は成り立たないかも。単調性が崩れるので。
    // 逆はいける？DP[L][1]から始めてDP[1][hoge]にするとか?
    // どっちも辺の数が多いので探索はダメそう


    // 回答確認
    // どうやら Ai の添字 i に対して問題を解くらしい。 i は n個あるので、解法は log N or 累積
    // Ai に対して、Ai を含む x <= L <= y, v <= R <= w となる L,R の組を求める。 (y == v)
    // 区間系は2次元平面と捉えられる。l軸、r軸平面上で考え要件を満たすところの面積(個数)を求めれば良い
        // l 軸, r 軸は長さ N, L <= Rなので逆三角っぽくなるはず
    // 片方の区間を固定してもう片方を考えるのもありっぽい

    // Lを固定した時、条件を満たす R は unique な要素を含んだタイミングとそれが次に現れるまで
    // Lを固定した時、L+1 <= i <= N において a[i] がunique な i が見つかったら 次に a[j]で現れるまでの Lからi--Lからj 区間は必ず条件を満たす
    // これを高速に探し出す感じか...

    // これ初手で見分け着く気がしないな。区間見た時に L or R で固定するという訓練が必要？




    ll ans = 0;
    vector<vector<bool>> dp(n + 1,vector<bool>(n,false));
//    vector<vector<set>> (n + 1,vector<bool>(n,false));
    vector<set<ll>> uniquenumberlist(n + 1, set<ll>());

    for (int i = 0; i < n; ++i) {
        dp[1][i] = true;
        uniquenumberlist[i].insert(a[i]);
        ans++;
    }


    for (int l = 2; l <= n; ++l) {
        for (int i = 0; i < n - (l - 1); ++i) {
//            dp[l][i] = g(dp[l - 1][i],dp[1][i + l - 1]);

            dp[l][i] = false;
//            if (!dp[l - 1][i])
//                continue;

            if (uniquenumberlist[i].find(a[i + l - 1]) != uniquenumberlist[i].end())
                continue;

            dp[l][i] = true;
            uniquenumberlist[i].insert(a[i + l - 1]);
            ans++;
        }
    }




    cout <<ans <<endl;

}
