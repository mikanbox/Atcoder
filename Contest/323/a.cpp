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

    bool ans = true;

    for (int i = 0; i < s.length(); ++i) {
        if ((i+1)%2 == 0) {
            if (s[i] == '1') {
                ans = false;
            }
        }
    }


    cout << (ans?"Yes":"No") << endl;

    return 0;
}
