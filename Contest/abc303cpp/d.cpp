#include <bits/stdc++.h>

using namespace std;
#define ll long long

const ll mod = 1000000007;
const ll LINF = 1e13;
const ll LLINF = 1e18;
const ll ALPHABET = 26;

// AAaA

int main()
{

    ll x,y,z;
    cin >> x >> y >> z;
    string s;
    cin >> s;

    ll off = 0;// 0 : CapsOff
    ll on  = 1;// 1 : CapsOn


    // s そのままだと使いづらいので集約する
    int index = 0;
    char c = s[0];
    std::vector< pair<char,ll> > shrink_s;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] != c) {
            int len = i - index;
            shrink_s.push_back(make_pair(c,len));
            index = i;
            c = s[i];
        }
    }
    int len = s.length() - index;
    shrink_s.push_back(make_pair(c,len));


    // dp 用の配列
    vector<vector<ll> > dp(s.length() + 1,vector<ll>(2,0));
    dp[0][on] = LLINF; // 初期状態は　OFF で、 ONはありえないため


    // dp (配るdp)
    for (ll i = 0; i < shrink_s.size(); ++i) {
        dp[i + 1][off] = min(
                dp[i][off] + shrink_s[i].second * ((shrink_s[i].first == 'a')?x:y), // off -> off
                dp[i][on]  + shrink_s[i].second * ((shrink_s[i].first == 'a')?x:y) + z // on -> off
        );
        dp[i + 1][on] = min(
                dp[i][off] + shrink_s[i].second * ((shrink_s[i].first == 'a')?y:x) + z, // off -> on
                dp[i][on]  + shrink_s[i].second * ((shrink_s[i].first == 'a')?y:x) // on -> on
        );
    }

    ll res = min(dp[shrink_s.size()][off], dp[shrink_s.size()][on]);
    cout << res << endl;

    return 0;
}
