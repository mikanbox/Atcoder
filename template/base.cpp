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
    ll n, r;
    cin >> n >> r;

    ll ans = 0;
    cerr << "err:"<< "mes" << endl;


    cout << ans << endl;
    cout << (ans ? "Yes" : "No") << endl;
}