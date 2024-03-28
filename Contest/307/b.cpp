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
    vector<string> s(n);

    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    bool ans = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j )continue;
            string _s = s[i] + s[j];
            string _sr= s[i] + s[j];
            reverse(_sr.begin(), _sr.end());
            if (_sr == _s) {
                cerr << i << " " << j << endl;
                ans =true;
            }
        }
    }


    cout << ((ans == true)? "Yes":"No");

}
