#include <iostream>
#include <string>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

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
    ll l, q;
    cin >> l >> q;
    vector<pair<ll ,ll > > cx(q,make_pair<ll,ll>(0,0));

    for (int i = 0; i < q; i++) {
        cin >> cx[i].first >> cx[i].second;
    }

    // for (int i = 0; i < q; i++) {
    //     cerr << "err:"<< cx[i].first << " , " << cx[i].second << endl;
    // }

    set<ll> s;
    s.insert(0);
    s.insert(l);

    set<ll> sr;
    sr.insert(0);
    sr.insert(-l);

    for (int i = 0; i < q; i++) {
        if (cx[i].first == 1) { // insert
            s.insert(cx[i].second);
            sr.insert(-cx[i].second);
        } else {
            decltype(s)::iterator bigger = s.lower_bound(cx[i].second);
            decltype(s)::iterator smaller = sr.lower_bound(-cx[i].second);
            cout << (*bigger - (- *smaller) ) << endl;

        }
    }




}