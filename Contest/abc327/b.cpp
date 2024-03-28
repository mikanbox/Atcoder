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


ll power (ll p, ll q) {
    ll ans = 1;
    for (int i = 0; i < q; ++i) {
        ans = ans * p;
    }
    return ans;
}


int main()
{
    ll b;
    cin >> b;

    ll ans = -1;
    for (int i = 1; i < 20; ++i) {
        ll p  = power(i,i);
        if (p == b) {
            ans = i;
            break;
        }
    }


    cout << ans << endl;
}

