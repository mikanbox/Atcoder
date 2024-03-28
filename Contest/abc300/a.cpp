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
    ll n, a, b;
    cin >> n >> a >> b;

    vector<ll> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        if (c[i] == a+b) {
            cout << i + 1 << endl;
        }
    }



    return 0;
}
