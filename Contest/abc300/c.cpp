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
    ll h,w;
    cin >> h >> w;
    vector<vector<char>> c(h,vector<char>(w,'a'));

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> c[i][j];
        }
    }

    ll n = min(h,w);
    vector<pair<ll,ll>> p;
    for (int i = 0; i < h - 2; ++i) {
        for (int j = 0; j < w - 2; ++j) {
            if (
                c[i][j] == '#' &&
                c[i + 2][j] == '#' &&
                c[i][j + 2] == '#' &&
                c[i + 1][j + 1] == '#' &&
                c[i + 2][j + 2] == '#'
                    ) {
                p.emplace_back(i + 1,j + 1);
            }
        }
    }

//    for (auto v: p) {
//        cerr << "i,j  " << v.first << " " << v.second << endl;
//    }


    vector<ll> ans(n+1,0);
    for (auto v:p) {
        ll i = v.first;
        ll j = v.second;
//        cerr << "i,j  " << v.first << " " << v.second << endl;
        for (int k = 2; k < n; ++k) {
//            cerr << "i + k,j+k  " << i + k << " " << j + k << endl;
            if (i + k < h && j + k < w) {
                if (c[i + k][j + k] == '.') {
                    ans[k -1] = ans[k -1] + 1;
                    break;
                }
            } else {
                ans[k -1] = ans[k -1] + 1;
                break;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }cout << endl;

    return 0;
}
