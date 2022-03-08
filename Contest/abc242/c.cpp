#include <iostream>
#include <string>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <iomanip>

using namespace std;
#define ll int64_t
#define ALL(a) \
    (a) c;     \
    .begin(), (a).end()

const ll mod = 1000000007;
const ll LINF = 1e13;
const ll LLINF = 1e18;
const ll ALPHABET = 26;

template <class T>
void Swap(T &r, T &l)
{
    T tmp = r;
    r = l;
    l = tmp;
}

template <typename T>
istream &operator>>(istream &is, vector<T> &vec)
{
    for (T &x : vec)
        is >> x; //for(int i=0; i<vec.size(); i++) is >> x[i]; とかでもいい
    return is;
}

ll md = 998244353;

int main()
{
    ll n;
    cin >> n;

    // dpぽい問題
    // vector<int> dp(n + 1, 0);
    vector<vector<ll>> dp(n + 1, vector<ll>(11,0));
    for (int i = 1; i <= 9; i++) {
        dp[1][i] = 1;
    }
    


    for (int i = 1; i <= n - 1; i++) {
        for (int j = 1; j <= 9; j++) {
            dp[i + 1][j + 1] += dp[i][j] % md;
            dp[i + 1][j    ] += dp[i][j] % md;
            dp[i + 1][j - 1] += dp[i][j] % md;
        }
    }

    ll ans = 0;
    for (int i = 1; i <= 9; i++) {
        ans += dp[n][i] % md;
        ans %= md;
    }
    

    cout << ans << endl;
}