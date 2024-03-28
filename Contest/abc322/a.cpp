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
    string s;
    cin >> s;
    string t;
    cin >> t;

    ll ans = -1;
    // s < t;

    bool isSetoji = true;
    bool isSetsubiji = true;

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] != t[i]) {
            isSetoji = false;
            break;
        }
    }

    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] != t[i]) {
            isSetsubiji = false;
            break;
        }
    }

    cerr << "isSetoji  " << isSetoji << endl;
    cerr << "isSetsubiji  " << isSetsubiji << endl;

    if (isSetsubiji && isSetoji) {
        ans = 0;
    }
    if (!isSetsubiji && isSetoji) {
        ans = 1;
    }
    if (isSetsubiji && !isSetoji) {
        ans = 2;
    }
    if (!isSetsubiji && !isSetoji) {
        ans = 3;
    }

    cout << ans << endl;
    return 0;
}
