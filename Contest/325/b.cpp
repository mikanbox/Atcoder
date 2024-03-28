#include <bits/stdc++.h>

using namespace std;
#define ll long long

const ll mod = 1000000007;
const ll LINF = 1e13;
const ll LLINF = 1e18;
const ll ALPHABET = 26;


int main()
{
    ll n;
    cin >> n;

    vector<pair<ll,ll>> wx(n);


    for (int i = 0; i < n; ++i) {
        ll w,x;
        cin >> w >> x;
        wx[i] = make_pair(w,x);
    }

    ll ans = -1;
    // 9 ~ 15
    for(int i = 0; i< 24;i++) {
        ll tmp = 0;
        for (int j = 0; j < n; ++j) {
            ll curtime = (wx[j].second + i) % 24;

            if (curtime >= 9 && curtime <= 17) {
                tmp += wx[j].first;
            }
        }
        if (tmp > ans){
            ans = tmp;
        }

    }

    cout << ans << endl;

    return 0;
}
