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
    ll n,m,l,q;
    vector<ll> a;
    vector<ll> b;
    vector<ll> c;
    vector<ll> x;

    cin >> n;
    for (ll i = 0; i < n; ++i) {
        ll tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    cin >> m;
    for (ll i = 0; i < m; ++i) {
        ll tmp;
        cin >> tmp;
        b.push_back(tmp);
    }
    cin >> l;
    for (ll i = 0; i < l; ++i) {
        ll tmp;
        cin >> tmp;
        c.push_back(tmp);
    }
    cin >> q;
    for (ll i = 0; i < q; ++i) {
        ll tmp;
        cin >> tmp;
        x.push_back(tmp);
    }

    //q
    //    N,M,L の組み合わせは 10^2 ^3

    map<ll,bool> ans;
    for(auto _a:a) {
        for(auto _b:b) {
            for(auto _c:c){
                ans[_a + _b + _c] =  true;
            }
        }
    }

    for (ll _x:x) {
        if (ans.find(_x) == ans.end()) {
            cout << "No";
        } else {
            cout << "Yes";
        }
        cout <<endl;
    }




}