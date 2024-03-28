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

    ll ans = n;
    for (int i = n; i < 1000; ++i) {
        ans = i;
        ll _h = i /100;
        ll _t = (i %100) / 10;
        ll _o = i %10;
        cerr << _h << " " << _t << " " << _o <<endl;

        if (_h * _t == _o)
            break;
    }


    cout << ans << endl;

}
