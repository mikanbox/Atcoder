#include <iostream>
#include <string>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <queue>

using namespace std;
#define ll int64_t
#define ALL(a) \
    (a) c;     \
    .begin(), (a).end()

const ll mod = 1000000007;
const ll LINF = 1e13;
const ll LLINF = 1e18;
const ll ALPHABET = 26;

template <class T>
void Swap(T &r, T &l)
{
    T tmp = r;
    r = l;
    l = tmp;
}

template <typename T>
istream &operator>>(istream &is, vector<T> &vec)
{
    for (T &x : vec)
        is >> x; //for(int i=0; i<vec.size(); i++) is >> x[i]; とかでもいい
    return is;
}

int main()
{
    ll q;
    cin >> q;

    vector <vector<ll> > query(q,vector<ll>(2,0));

    for(int i = 0; i < q; i++) {
        cin >> query[i][0];
        if (query[i][0] == 1) 
            cin >> query[i][1];
    }

    list<ll> l;
    multiset<ll> s;
    queue<ll> qe;
    // priority_queue<ll>qep;
    priority_queue<
      ll,                // 要素の型はint
      std::vector<ll>,   // 内部コンテナはstd::vector (デフォルトのまま)
      std::greater<ll>   // 昇順 (デフォルトはstd::less<T>)
    > qep;


    for (int i = 0; i < q; i++ ){
        if (query[i][0] == 1){
            qe.push(query[i][1]);
        }

        if (query[i][0] == 2){
            // if (qep.size() > 0) {
            //     // set<ll> :: iterator itr = s.begin();
            //     // cout << *(itr) << endl;
            //     // s.erase(itr);
            //     cout << qep.top() << endl;
            //     qep.pop();
            // }
            if (s.size() > 0){
                set<ll> :: iterator itr = s.begin();
                cout << *(itr) << endl;
                s.erase(itr);
            }
            
             else {
                cout << qe.front() << endl;
                qe.pop();
            }
        }

        if (query[i][0] == 3){
            if (qe.size() == 0) continue;

            while(qe.size() > 0) {
                s.insert(qe.front());
                // qep.push(qe.front());
                qe.pop();
            }

        }
    }
}