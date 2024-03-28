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

    ll ans = 0;
    if (n % 5 >=3) {
        ans = n+ (5-n%5);
    } else {
        ans = n- n%5;
    }


    cout << ans <<endl;

    return 0;
}
