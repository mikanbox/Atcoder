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
    vector<vector<ll>> a(n,vector<ll>(n,-1));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }


    vector<vector<ll>> b(n,vector<ll>());
    for (ll i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j)continue;

            if (a[i][j] == 1) {
                b[i].push_back(j);
            }

        }
        std::sort(b[i].begin(), b[i].end());
    }

    for (ll i = 0; i < n; ++i) {
        for (auto v:b[i]) {
            cout << (v + 1) << " ";
        }
        cout << endl;
    }

}
