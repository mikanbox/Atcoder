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

bool check(ll ipos, ll jpos, vector<vector<char>> a_ex, vector<vector<char>> b) {
    bool res = true;
    for (int i = 0; i < b.size(); ++i) {
        for (int j = 0; j < b[0].size(); ++j) {
            if (b[i][j] != a_ex[i + ipos][j + jpos]) {
                res= false;
            }
        }
    }
    return res;
}

int main()
{
    ll h,w;
    cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));
    vector<vector<char>> b(h, vector<char>(w));

    // w * h = 1000

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> b[i][j];
        }
    }

    // 4倍マップを用意すればいけそう
    vector<vector<char>> a_ex(h * 2, vector<char>(w * 2));

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            a_ex[i][j] = a[i][j];
            a_ex[i + h][j] = a[i][j];
            a_ex[i][j + w] = a[i][j];
            a_ex[i + h][j + w] = a[i][j];
        }
    }

    bool ans = false;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            ans = check(i,j,a_ex,b);
            if (ans == true) {
                break;
            }
        }
        if (ans == true) {
            break;
        }
    }

    cout << ((ans)?"Yes":"No") << endl;


    return 0;
}

