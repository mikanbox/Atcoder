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
    char p,q;
    cin >> p >> q;

    map<char,ll> mp;
    mp['A'] = 0;
    mp['B'] = 3;
    mp['C'] = 4;
    mp['D'] = 8;
    mp['E'] = 9;
    mp['F'] = 14;
    mp['G'] = 23;

    cerr << p << q <<endl;

    ll _p, _q;
    _p = mp[p];
    _q = mp[q];
    cerr << _p << _q <<endl;

    ll ans = 0;

    ans = max(_q,_p) - min(_q,_p);
    cout << ans <<endl;

}
