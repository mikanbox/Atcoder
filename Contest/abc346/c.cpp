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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // k は 10^9 まであるので数え上げはNG
    ll sum = k * ( k + 1) / 2;

    cerr << "sum " << sum << endl;

    map<ll,bool> isused;
//    vector<bool> isused(k+1, false);
    for (int i = 0; i < n; ++i) {
        if ( isused[a[i]] == false && a[i] <= k) {
            isused[a[i]] = true;
            sum -= a[i];
        }
    }


    cout << sum << endl;

}
