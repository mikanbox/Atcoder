#include <bits/stdc++.h>


using namespace std;
#define ll long

const ll mod = 1000000007;
const ll LINF = 1e13;
const ll LLINF = 1e18;
const ll ALPHABET = 26;


int main()
{
    ll n,m;
    cin >> n >> m;

    vector<vector<ll>> edges_node(n + 1,vector<ll>());

    for (ll i = 0; i < m; ++i) {
        ll x,y;
        cin >> x >> y;
        edges_node[x].push_back(y);
        edges_node[y].push_back(x);
    }

    ll k;
    cin >> k;

    vector<pair<ll,ll>> edge_k(k);
    for (ll i = 0; i < k; ++i) {
        ll x,y;
        cin >> x >> y;
        edge_k[i] = make_pair(x,y);
    }

    ll q;
    cin >> q;

    vector<pair<ll,ll>> edge_q(q);
    for (ll i = 0; i < q; ++i) {
        ll x,y;
        cin >> x >> y;
        edge_q[i] = make_pair(x,y);
    }


    // 頂点を set に分割

    // 初期状態を探索
    // ここで Bad ならもう無理
    // ここで Good なら可能性あり

    // クエリごとに次を計算 q 回なので10^5
        // pi と qi が属する graph を求める。 u[pi] in graph_1, u[q_i] in graph_2
        // 同じ set に 条件k のいずれかがあれば Bad 、いずれもなければ Good　これは事前に求めておく


    // sepparate
    vector<bool> isVisited(n + 1,false);
    vector<ll> graphid_node(n + 1, -1);
    ll sub_graph_id = 0;
    vector<ll> queue;


    for (ll i = 1; i <= n; ++i) {
        if (isVisited[i])continue;
        queue.push_back(i);
        graphid_node[i] = sub_graph_id;
        isVisited[i] = true;

        while(!queue.empty()) {
            ll node = queue.back();
            queue.pop_back();
            for (auto v:edges_node[node]) {
                if (!isVisited[v]) {
                    isVisited[v] = true;
                    queue.push_back(v);
                    graphid_node[v] = sub_graph_id;
                }
            }
        }
        sub_graph_id++;
    }


    // -1はありえないはず
//    for (int i = 1; i < graphid_node.size(); ++i) {
//        cerr << i << " : " << graphid_node[i] << endl;
//    }

// 普通に 10GB超えちゃうのでダメ
//    vector<vector<bool>> sub_graphbased_conditions(sub_graph_id,vector<bool>(sub_graph_id, false));
    unordered_set<string> sub_graph_edge{};


    for (ll i = 0; i < k; ++i) {
        ll u = edge_k[i].first;
        ll v = edge_k[i].second;
        ll gid_u = graphid_node[u];
        ll gid_v = graphid_node[v];
        string s = to_string(gid_u) + "," + to_string(gid_v);
        sub_graph_edge.insert(s);
        string s2 = to_string(gid_v) + "," + to_string(gid_u);
        sub_graph_edge.insert(s2);
    }


    for (ll i = 0; i < q; ++i) {
        string isAns = "Yes";
        ll u = edge_q[i].first;
        ll v = edge_q[i].second;
        ll gid_u = graphid_node[u];
        ll gid_v = graphid_node[v];
        string s = to_string(gid_u) + "," + to_string(gid_v);
        if (sub_graph_edge.find(s) != sub_graph_edge.end()) {
            isAns = "No";
        }
        cout << isAns << endl;
    }


    return 0;
}
