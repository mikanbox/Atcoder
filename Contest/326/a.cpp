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
    ll x,y;
    cin >> x >> y;

    ll b = y - x;
    bool ans = true;

    if (b < 0) {
        if (b < -3) {
            ans = false;
        }
    }
    if (b > 0) {
        if (b > 2) {
            ans = false;
        }
    }

    cout << (ans? "Yes":"No") << endl;

}
