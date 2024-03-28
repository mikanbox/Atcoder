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


ll power (ll p, ll q) {
    ll ans = 1;
    for (int i = 0; i < q; ++i) {
        ans = ans * p;
    }
    return ans;
}


int main()
{
    vector<vector<ll>> numple(9,vector<ll>(9,0));
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> numple[i][j];
        }
    }


    bool ans = true;
//  col direction check
    for (int i = 0; i < 9; ++i) {
        vector<bool> check(10,false);
        for (int j = 0; j < 9; ++j) {
            if ( check[numple[i][j]] != true) {
                check[numple[i][j]] = true;
            } else {
                ans = false;
            }
        }
    }

//  row check
    for (int i = 0; i < 9; ++i) {
        vector<bool> check(10,false);
        for (int j = 0; j < 9; ++j) {
            if ( check[numple[j][i]] != true) {
                check[numple[j][i]] = true;
            } else {
                ans = false;
            }
        }
    }

//  box check
    for (int i = 0; i < 9; ++i) {
        ll ai,aj;
        ai = i % 3;
        aj = i / 3;

        vector<bool> check(10,false);
        for (int j = 0; j < 9; ++j) {
            ll bi,bj;
            bi = j % 3;
            bj = j / 3;

            if ( check[numple[ai * 3 + bi][aj * 3 + bj]] != true) {
                check[numple[ai * 3 + bi][aj * 3 + bj]] = true;
            } else {
                ans = false;
            }
        }
    }


    cout << (ans?"Yes":"No") << endl;
}

