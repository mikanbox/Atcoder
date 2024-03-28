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
    vector<ll> a(7 * n);

    ll ans = 0;
    for (int i = 0; i < 7 * n; ++i) {
        if (i %7 ==0)ans =0;
        cin >>a[i];
        ans+=a[i];
        if (i %7 == 6) {
            cout << ans ;
            cout << " ";
        }

    }

}
