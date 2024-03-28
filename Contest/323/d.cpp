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

    vector<ll> s(n);
    vector<ll> c(n);

    vector<pair<ll,ll>> s_index(n);
    unordered_map<ll,ll> s_hashmap;
    unordered_map<ll,ll> s_index_hashmap;
    map<ll,ll> s_map;

    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        cin >> c[i];
        s_index[i] = make_pair(s[i],i);
        s_hashmap[s[i]] = c[i];
        s_index_hashmap[s[i]] = i;
        s_map[s[i]] = c[i];
    }
    sort(s_index.begin(), s_index.end(), [](pair<ll,ll>&left,pair<ll,ll>&right){
        return left.first < right.first;
    });


    ll ans2 = 0;
    // 基本的には最終的に map は 1 だけになる

    // n + 追加分 (最大 10^5 になるかも)
    for (auto sc:s_map) {
//        cerr << "for key : " << sc.first << endl;
        if (sc.second < 2) {
            ans2 += sc.second;
            continue;
        }
        ll t_val = sc.second / 2;
        ll t_key = sc.first * 2;
        if (s_map.find(t_key) != s_map.end()) {
            s_map[t_key] += t_val;
        } else {
            s_map.insert(make_pair(t_key,t_val));
        }
        ans2 += sc.second % 2;
    }

    ll ans = 0;
//    for (auto sc:s_map) {
////        cerr << "key,value  : " << sc.first << " , " << sc.second << endl;
//        ans+= sc.second;
//    }
    cout << ans2 << endl;



    return 0;
}
