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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }


   ll current_m = 0;
    for (ll i = 1; i <= n; ++i) {
        ll ans = 0;
        if (a[current_m] < i) {
            current_m++;
        }

        ans = a[current_m] - i;
        cout << ans << endl;
    }

    return 0;
}
