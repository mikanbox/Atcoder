#include <iostream>
#include <string>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <queue>


using namespace std;

#define N 410
#define ll long long
#define MOD 998244353
#define rep(i, n) for(int i = 0; i < n; ++i)

int main(void) {
	int n, m;
	int a, b;
	ll x, y, z;
	bool can[N][N];
	ll dp[N][(N / 2)];
    ll binom[N][N];
	binom[0][0] = 1;
	for (int i = 1; i < N; i++) {
		binom[i][0] = 1;
		binom[i][i] = 1;
		rep(j, i - 1) {
			binom[i][j + 1] = (binom[i - 1][j] + binom[i - 1][j + 1]) % MOD;
		}
	}

	cin >> n >> m;
	rep(i, 2 * n)rep(j, 2 * n)can[i][j] = false;
	rep(i, m) {
		cin >> a >> b;
		can[a - 1][b - 1] = true;
		can[b - 1][a - 1] = true;
	}

	rep(i, 2 * n + 1)dp[i][0] = 1;



	for (int j = 1; j <= n; j++) {
        for (int i = 0; i < 2 *(n - j); i++){
			dp[i][j] = 0;

            for(int k = 0;k < j; k++) {
                ll ipair = i + (2 * k) + 1;

				if (can[i][ipair]) {//1 と 2,4,6,8...


					x = (dp[i + 1][k] * dp[ ipair + 1 ][j - k - 1]) % MOD;// k 回ペア組んだので残りは j -k -1(-1 は　iが組むから)
					dp[i][j] = ((x*binom[j][k + 1]) + dp[i][j]) % MOD; // i と ipair の部分は組み合わせの余地なし ipair + 1 から先は組み合わせあり
                    // jCk : 全体j 回中 k 回順序決められるから
                    // 1-10　, j=4,k=3  1-6 とすると 1-6(3) 7-10(2)
                    //dp[2][2] * dp[7][1] * 4c3


				}
			}
		}
	}
	cout << dp[0][n] << endl;

	return 0;
}

