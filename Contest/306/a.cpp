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
    string s;
    cin >> n;
    cin >> s;
    string ans = "";

    for (auto v:s) {
        ans+= v;
        ans+= v;
    }


    cout << ans << endl;

}
