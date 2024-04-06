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
    ll n,t;
    cin >> n >> t;
    vector<pair<ll,ll>> ab(t);

    for (ll i = 0; i < t; ++i) {
        ll a,b;
        cin >> a >> b;
        ab[i] = make_pair(a,b);
    }

    vector<ll> points(n,0);
    map<ll,ll> mp;
    mp[0] = n;



    ll ans = 1;


    for (ll i = 0; i < t; ++i) {
        ll personindex = ab[i].first - 1;
        ll plus = ab[i].second;

        mp[points[personindex]]--;
        if (mp[points[personindex]]==0){
            mp.erase(mp[points[personindex]]);
            ans--;
        }

        if (!mp.contains(points[personindex] + plus )){
            ans++;
        }
        points[personindex] += plus;
        mp[points[personindex]]++;

//        for (auto v:mp) {
//            cerr << "point : " << v.first << "     : num" << v.second << endl;
//        }cerr << "====" << endl;
//
//
        cout << ans <<endl;
    }



}
