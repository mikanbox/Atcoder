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

    //dp[25][25][25][25][25] みたいなのが必要かも。dp[5][5][5][5][5]以上の空間でコスト最小のものを探せばOKか。
    //5次元だからイメージわかなかったな...
//    25^5 625 * 625 * 5 = 36000 * 5
    ll ans = LLINF;
    vector<vector<vector<vector<vector<ll>>>>> dp(p+ 2,vector<vector<vector<vector<ll>>>>(p + 2,vector<vector<vector<ll>>>(p + 2,vector<vector<ll>>(p + 2,vector<ll>(p + 2,LLINF)))));


    dp[0][0][0][0][0] = 0;
//    dp配列のうち、最大5まで確認する
    //k == 5の時
    for (int i = 0; i < n; ++i) {

        // 最大で25^5 = でかい。枝刈りしないとギリかも 625 * 625 * 25 = 36000 * 25 = 10^4 * 3.6  * 25 = 10^6.
        for (int j = p; j >= 0; --j) {
            ll next = j + a[i][0];
            if (next > p) next = p;
            if (k==1) {
                if (dp[j][0][0][0][0] < LLINF) {
                    dp[next ][0][0][0][0]
                            = min(dp[next][0][0][0][0],
                                  dp[j][0][0][0][0] + c[i]);
                }
                continue;
            }

            for (int l = p; l >= 0; --l) {
                ll next2 = l + a[i][1];
                if (next2 > p) next2 = p;
                if (k==2) {
                    if (dp[j][l][0][0][0] < LLINF) {
                        dp[next][next2][0][0][0]
                                = min(dp[next][next2][0][0][0],
                                      dp[j][l][0][0][0] + c[i]);
                    }
                    continue;
                }
                for (int m = p; m >=0 ; --m) {
                    ll next3 = m + a[i][2];
                    if (next3 > p) next3 = p;
                    if (k==3) {
                        if (dp[j][l][m][0][0] < LLINF) {
//                            cerr << "j,l,m  " << j << "," << l << "," << m << endl;
//                            cerr << "j,l,m next :  " << j + a[i][0] << "," << l + a[i][1] << "," << m + a[i][2] << endl;
                            dp[next][next2][next3][0][0]
                                    = min(dp[next][next2][next3][0][0],
                                          dp[j][l][m][0][0] + c[i]);
//                            cerr << "dp[j + a[i][0]][l + a[i][1]][m + a[i][2]][0][0] " << dp[j + a[i][0]][l + a[i][1]][m + a[i][2]][0][0] << endl;
                        }
                        continue;
                    }
                    for (int i1 = p; i1 >=0; --i1) {
                        ll next4 = i1 + a[i][3];
                        if (next4 > p) next4 = p;
                        if (k==4) {
                            if (dp[j][l][m][i1][0] < LLINF) {
                                dp[next][next2][next3][next4][0]
                                        = min(dp[next][next2][next3][next4][0],
                                              dp[j][l][m][i1][0] + c[i]);
                            }
                            continue;
                        }

                        for (int k1 = p; k1 >=0; --k1) {
                            ll next5 = k1 + a[i][4];
                            if (next5 > p) next5 = p;
                            if (dp[j][l][m][i1][k1] < LLINF) {
                                dp[next][next2][next3][next4][next5]
                                = min(dp[next][next2][next3][next4][next5],
                                      dp[j][l][m][i1][k1] + c[i]);
                            }
                        }

                    }
                }
            }


        }
        cerr <<"====Plan is finished====" <<endl;
    }

    if (k==1) {
        if (dp[p][0][0][0][0] >= 0) {
            ans = min(ans,dp[p][0][0][0][0]);
        }
    }
    if (k==2) {
        if (dp[p][p][0][0][0] >= 0) {
            ans = min(ans,dp[p][p][0][0][0]);
        }
    }
    if (k==3) { // i,k,l がp以上の場合のみ確認
        if (dp[p][p][p][0][0] >= 0) {
            ans = min(ans,dp[p][p][p][0][0]);
        }
    }
    if (k==4) {
        if (dp[p][p][p][p][0] >= 0) {
            ans = min(ans,dp[p][p][p][p][0]);
        }
    }
    if (k==5) {
        if (dp[p][p][p][p][p] >= 0) {
            ans = min(ans,dp[p][p][p][p][p]);
        }
    }

    if (ans == LLINF)
        ans = -1;

    cout << ans << endl;
    return 0;
}
