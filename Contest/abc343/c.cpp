#include <bits/stdc++.h>
#include <string>

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

    ll ans = 0;

    for (ll i = 1; i < 10000000; ++i) {
        if (i* i * i > n)
            break;

        string s = to_string(i * i * i);
        string s2 = s;
        reverse(s.begin(), s.end());
        if (s2 == s) {
            ans = i * i * i;
        }
    }

    cout << ans << endl;

}
