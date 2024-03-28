#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod = 1000000007;
const ll LINF = 1e13;
const ll LLINF = 1e18;
const ll ALPHABET = 26;



// dp[i, 0 ] = dp[i  - k, 0 ] + k * X + dp[i - k, 1] + k * Y + Z

//ll dpSearch(vector<vector<ll>>& dp) {
//    ll ans = 0;
//
//    for
//
//
//    return ans;
//}


int main()
{

    ll x,y,z;
    cin >> x >> y >> z;
    string s;
    cin >> s;



    // 0 : CapsOff
    ll off = 0;
    ll on  = 1;
    // 1 : CapsOn

    int index = 0;
    char c = s[0];
    vector<pair<char,ll>> shrink_s;

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] != c) {
            int len = i - index;
            shrink_s.push_back(make_pair(c,len));
            index = i;
            c = s[i];
        }
    }

    for (auto v:shrink_s) {
        cerr << "c, length :" << v.first << " " << v.second << endl;
    }


    vector<vector<ll>> dp(s.length() + 1,vector<ll>(2,0));
//    // dp (配るdp)
//    for (ll i = 0; i < shrink_s.size(); ++i) {
//        dp[i + 1][off] =
//
//    }

//    ll res = dpSearch(dp);
//    cout << res << endl;

    return 0;
}
