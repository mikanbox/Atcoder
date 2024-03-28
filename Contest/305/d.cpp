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
    vector<ll> _a(n); // 累積和
    vector<ll> a(n);
    _a[0] = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i == 0 )continue;
        _a[i] = _a[i - 1] + (a[i] - a[i - 1]) * ( (i + 1) %2 );
    }
    ll q;
    cin >> q;
    vector<pair<ll,ll>> lr(q);
    for (int i = 0; i < q; ++i) {
        ll l,r;
        cin >> l >> r;
        lr[i] = make_pair(l,r);
    }


    //起きたら true
    map<ll,pair<bool,ll>> timeline;
    for (int i = 0; i < n; ++i) {
        //        i + 1 が奇数の時起きる
        timeline[a[i]] = make_pair( ((i+1)%2 == 1) , i );
    }

    // 与えられた値より小さくない要素へのイテレータを返す
    // timeline.lower_bound()

    for (int i = 0; i < q; ++i) {
        ll ans = 0;
        ll l,r;
        l = lr[i].first;
        r = lr[i].second;
//        与えられた値より小さくない要素へのイテレータを返す (= も含む)
        auto litr = timeline.lower_bound(l);
        auto ritr = timeline.lower_bound(r);
        ll l_w = litr->first - l;
        ll lp = 0;
        // 左端より右の値が起床時刻の場合
        if (litr->second.first == true) {
            lp = l_w;
        }
        ll r_w = ritr->first - r;
        ll rp = 0;
        // 右端より右の値が起床時刻の場合
        if (ritr->second.first == true) {
            rp = -r_w;
        }

//        cerr << litr->first << " : " << ritr->first << endl;

        ans = _a[ritr->second.second] - _a[litr->second.second] + lp + rp;
        cout << ans << endl;
    }


}
