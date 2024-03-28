#include <bits/stdc++.h>
using namespace std;
#define ll uint64_t

#define ALL(a) \
    (a) c;     \
    .begin(), (a).end()

const ll mod = 1000000007;
const ll LINF = 1e13;
const ll LLINF = 1e18;
const ll ALPHABET = 26;


int main()
{

    vector<ll> a(64);
    for (int i = 0; i < 64; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < 64; ++i) {
        cerr << a[i] << " ";
    }cerr << endl;

    ll ans = 0;
    for (int i = 0; i < 64; ++i) {
        ll b = 1;

        ans += (ll)(b << i) * a[i];
    }
    cout << ans << endl;

}
