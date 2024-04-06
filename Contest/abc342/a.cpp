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
    string s;
    cin >> s;

    map<char,ll> c;
    ll ans = 0;

    for (int i = 0; i < s.length(); ++i) {
        c[s[i]] = 0;
    }

    for (int i = 0; i < s.length(); ++i) {
        c[s[i]]++;
    }

    char oc;
    for (auto cc: c) {
        if (cc.second == 1) {
            oc = cc.first;
        }
    }

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == oc) {
            ans = i + 1;
            break;
        }
    }


    cout << ans << endl;

}