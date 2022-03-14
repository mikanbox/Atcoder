#include <iostream>
#include <string>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <map>

using namespace std;
#define ll int64_t

const ll mod = 1000000007;
const ll LINF = 1e13;
const ll LLINF = 1e18;
const ll ALPHABET = 26;

template <typename T>
istream &operator>>(istream &is, vector<T> &vec)
{
    for (T &x : vec)
        is >> x; // for(int i=0; i<vec.size(); i++) is >> x[i]; とかでもいい
    return is;
}

int main()
{
    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> edge(n + 1, vector<ll>(n + 1, LLINF));
    vector<tuple<ll,ll,ll>> abc;
    for (int i = 0; i < n + 1; i++) {
        edge[i][i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        edge[a][b] = c;
        edge[b][a] = c;
        abc.push_back(make_tuple(a, b, c));
    }
    

    // n < 10^2 * 3
    // m < 10^4 * 4.5

    // point
    // 全頂点対の距離はワーシャルフロイドで算出可　→ 10^6 * 27 →ギリギリ一回回せる　→毎回回すのは無理

    // 全辺について、毎回除去できるかを計算　→ TLE 10^6 * 27 * 10^4

    // 全頂点について、除去可能な辺を計算しておく　→ 10^6 * 27
    // 計算量は OK だが、網羅性は？

    // 実は、意外と全頂点対間の最短距離を求めておいて、その後それより長いへんを全部カットすればOKだったりする?
    //そんな感じがする
    // へんの長さが = の時の例外処理が必要そう
    // 最小値と = でも、経路が二つ以上ある場合は除去可能

    // algorithm
    // warshal floyd で全頂点対間の最短距離を求める
    // 全edge を調べて、最短じゃない辺をカット


    
    

    for (int k = 1; k < n + 1; k++)
    { // 経由する頂点
        for (int i = 1; i < n + 1; i++)
        { // 始点
            for (int j = 1; j < n + 1; j++)
            { // 終点
                edge[i][j] = min(edge[i][j], edge[i][k] + edge[k][j]);
            }
        }
    }
    vector<vector<ll>> edge_min_count(n + 1, vector<ll>(n + 1, 0));
    for (int k = 1; k < n + 1; k++)
    { // 経由する頂点
        for (int i = 1; i < n + 1; i++)
        { // 始点
            for (int j = 1; j < n + 1; j++)
            { // 終点
                if (edge[i][j] == edge[i][k] + edge[k][j])
                    edge_min_count[i][j]++;
            }
        }
    }



    ll ans = 0;
    for (auto v : abc) {
        if ( get<2>(v) > edge[get<0>(v)][get<1>(v)] ) {
            ans++;
            cerr << get<0>(v) << " --- " << get<1>(v) << "  : " << get<2>(v) << "  < " << edge[get<0>(v)][get<1>(v)] << endl;
        } else if ( get<2>(v) == edge[get<0>(v)][get<1>(v)] ) {
            if (edge_min_count[get<0>(v)][get<1>(v)] >= 3) {
                ans++;
                cerr << get<0>(v) << " --- " << get<1>(v) << "  : " << get<2>(v) << "  == " << edge[get<0>(v)][get<1>(v)] << endl;
            }
        }
    }

    cout << ans << endl;


}