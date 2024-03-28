#include <bits/stdc++.h>

using namespace std;
#define ll long long

const ll mod = 1000000007;
const ll LINF = 1e13;
const ll LLINF = 1e18;
const ll ALPHABET = 26;


int main()
{
    ll n;
    cin >> n;
    vector<pair<string,ll>> p = vector<pair<string,ll>>(n);
    for (int i = 0; i < n; ++i) {
        string s;
        ll a;
        cin >> s;
        cin >> a;
        p[i] = make_pair(s,a);
    }

    for (auto v: p) {
        cerr << v.first << " "<< v.second << endl;
    }

    ll minindex = 0;
    ll minvalue = LLINF;
    for (int i = 0; i < n; ++i) {
        if (minvalue > p[i].second) {
            minindex = i;
            minvalue = p[i].second;
        }
    }


    for (int i = 0; i < n; ++i) {
        cout << p[ (i + minindex) % n ].first << endl;
    }


    return 0;
}
