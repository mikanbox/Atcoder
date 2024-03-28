#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
const ll LLINF = 1e18;


int main(){
    ll  n , m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<vector<ll> > s(n,vector<ll>());

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < a[i]; ++j) {
            ll tmp;
            cin >> tmp;
            s[i].push_back(tmp);
        }
    }

    // 要素の first の小さいじゅんに並び替え
    sort(s.begin(), s.end(),[](vector<ll>& a, vector<ll>& b){
        return a[0] < b[0];
    });


    //複数ありうる

    vector<ll> si_including_m = vector<ll>();
    vector<ll> si_including_1 = vector<ll>();

    vector<vector<ll> > node_including_si(m + 1,vector<ll>());
    for (int i = 0; i < n; ++i) {
        for (auto p: s[i]) {
            node_including_si[ p ].push_back(i);
            if (p == 1) {
                si_including_1.push_back(i);
            }
            if (p == m) {
                si_including_m.push_back(i);
            }
            if (p == i)continue;
        }
    }
//    cerr << "===" << endl;

// ここで全部の辺を検索しないといけないから TLE になる
    vector<unordered_set<ll>> si_graph2(n,unordered_set<ll>());
// si_graph は si から移動可能な sj の集合を包含する二次元 vector
    for (ll i = 0; i < n; ++i) {
        for (const auto& sij:s[i]) { // s[i] の各要素
            for (const auto& sx:node_including_si[sij]) {
                si_graph2[i].insert(sx);
            }
        }
    }

//    for (int i = 1; i < m + 1; ++i) {
//        if (!node_including_si[i].empty()) {
//            for (auto sx:node_including_si[i]) {
//                if (sx == i)continue;
//                si_graph[i].push_back(sx);
//            }
//        }
//    }


    //    si_graph を使ってDPを行う
//    cerr << "===" << endl;
//
//    for (int i = 0; i < n; ++i) {
//        cerr << "s[" << i << "]  ";
//        for (auto sj: si_graph[i]) {
//            cerr << sj << ", ";
//        }
//        cerr << endl;
//    }



    vector<ll> dp(n,LLINF);
    vector<ll> q2;

    for (auto v:si_including_1) {
        dp[v] = 0;
        q2.push_back(v);
    }


    while(!q2.empty())
    {
//        set<ll> _q;
        vector<ll> _q2;
        for (auto i: q2) {
            // 対象 si
//            cerr << " dp["<<i<<"]:"<< dp[i] << ",";
            // 処理する si 集合と被っているsjに対して処理
            for (auto sj:si_graph2[i]) {
//                cerr << " - sj " << sj << " ,";
                if (dp[sj] > dp[i] + 1) {
                    _q2.push_back(sj);
//                    _q.insert(sj);
                    dp[sj] = dp[i] + 1;
                }
            }
        }

        q2 = _q2;
    }

    // 1 を含む添字番号を探索
    // M を含む添字番号を探索
    ll ans = LLINF;
    for (auto v :si_including_m) {
        ans = min(ans, dp[v]);
    }

    if (ans == LLINF)
        ans = -1;

    cout << ans;
}
