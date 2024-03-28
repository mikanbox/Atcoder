#include <bits/stdc++.h>

using namespace std;
#define ll long long

const ll mod = 1000000007;
const ll LINF = 1e13;
const ll LLINF = 1e18;
const ll ALPHABET = 26;


bool isInEucrid(ll dist,pair<ll,ll>& src, pair<ll,ll> dst ) {

    return (dist * dist >= (src.first - dst.first)*(src.first - dst.first) + (src.second - dst.second) * (src.second - dst.second));
}

int main()
{
    ll n,d;
    cin >> n >> d;
    vector<pair<ll,ll>> p = vector<pair<ll,ll>>(n);
    for (int i = 0; i < n; ++i) {
        ll x,y;
        cin >> x >> y;
        p[i] = make_pair(x,y);
    }

    vector<bool> isInfected = vector<bool> (n,false);
    vector<ll> infections;

    infections.push_back(0);
    isInfected[0] = true;


    while(!infections.empty()) {
        vector<ll> _infections;
//        cerr << "infect p id :";
        for (auto i: infections) {
//            cerr << i << ",";
            for (int j = 0; j < n; ++j) {
                if (isInfected[j] == false) {
                    if (isInEucrid(d, p[i], p[j])) {
                        //新規感染している
                        _infections.push_back(j);
                        isInfected[j] = true;
                    }
                }
            }
        }
//        cerr << endl;
        infections = _infections;
    }

    for (int j = 0; j < n; ++j) {
        cout << ((isInfected[j])?"Yes":"No") ;
        if (j == n-1)
            break;
        cout << endl;
    }

    return 0;
}
