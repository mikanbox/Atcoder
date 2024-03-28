#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define ALL(a)  (a) c;.begin(),(a).end()

const ll mod = 1000000007;
const ll LINF = 1e13;#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define ALL(a)  (a) c;.begin(),(a).end()

const ll mod = 1000000007;
const ll LINF = 1e13;
const ll LLINF = 1e18;
const ll ALPHABET = 26;

template <class T>
void Swap(T& r, T& l) {
    T tmp = r;
    r = l;
    l = tmp;
}

template<typename T>
istream& operator >> (istream& is, vector<T>& vec) {
    for (T& x : vec) is >> x; //for(int i=0; i<vec.size(); i++) is >> x[i]; とかでもいい
    return is;
}


int main(){
    ll  a, b;
    cin >> a >> b;


    ll ans = a /b;
    if (a%b !=0)
        ans++;


    cout << ans;
}

const ll LLINF = 1e18;
const ll ALPHABET = 26;

template <class T>
void Swap(T& r, T& l) {
  T tmp = r;
  r = l;
  l = tmp;
}



int main(){
    ll n,q;
    cin >> n >> q;
    vector<vector<ll> > query(q,vector<ll>());

    for (ll i = 0; i < q; ++i) {
        ll op, n1,n2;
        cin >> op;
        query[i].push_back(op);
        if (op == 1) {
            cin >> n1;
            cin >> n2;
            query[i].push_back(n1);
            query[i].push_back(n2);
        }
        if (op==2) {
            cin >> n1;
            query[i].push_back(n1);
        }
    }

    // no-directed graph
    // n :10^5
    // q: 10^5

    // op 1 : 辺を加える
    // op 2 : 辺を削除。　この操作が重い、、 (vector の clear は線形なので 最大 10^5かつ一回きりではあるが、相手側の削除は find して削除なので　10^5 * 10^5 がありうる)

    // hashmap 使えば良さそうか


//    vector<vector<ll> > graph(n + 1, vector<ll>());
    vector<unordered_map<ll, bool> > graph(n+1, unordered_map<ll, bool>());

    ll count = n; // 接続されたノード数
    for (int i = 0; i < q; ++i) {
        if (query[i][0] == 1) {
//            cerr << "op : add edge : " << endl;
            if (graph[query[i][1]].empty()) {
                count --;
            }
            if (graph[query[i][2]].empty()) {
                count --;
            }
            graph[query[i][1]][query[i][2]] = true;
            graph[query[i][2]][query[i][1]] = true;
        }
        if (query[i][0] == 2) {
//            cerr << "op : remove : " <<  query[i][1] << endl;
            for (auto itr = graph[query[i][1]].begin(); itr != graph[query[i][1]].end(); ++itr){
                graph[itr->first].erase(query[i][1]);
//                cerr << "remove " <<  query[i][1] << " - " << itr->first <<  endl;
                if (graph[itr->first].empty()) {
                    count ++ ;
                }
            }

            if (!graph[query[i][1]].empty()) {
                count ++ ;
                graph[query[i][1]].clear();
            }

        }

        cout << count << endl;
    }


}
