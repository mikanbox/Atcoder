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
    string s;
    cin >> s;

    bool ans = false;

    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == 'a' && s[i + 1] == 'b') {
            ans = true;
            break;
        }
        if (s[i] == 'b' && s[i + 1] == 'a') {
            ans = true;
            break;
        }
    }

    cout << (ans? "Yes":"No") << endl;

}
