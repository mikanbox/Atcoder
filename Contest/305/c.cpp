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

    vector<string> s(h);
//    vector<vector<char>> s(h,vector<char>(w));
    for (int i = 0; i < h; ++i) {
//        for (int j = 0; j < w; ++j) {
//            cin >> s[i][j];
//        }
        cin >> s[i];
    }

    // 4点を求める
    pair<ll,ll> left_upper;
    pair<ll,ll> left_lower;
    pair<ll,ll> right_upper;
    pair<ll,ll> right_lower;


    bool isfind = false;
    // 左上から開始
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (s[i][j] == '#') {
                left_upper = make_pair(i,j);
                isfind = true;
            }
            if (isfind)break;
        }
        if (isfind)break;
    }


    isfind = false;
    // 右上から開始
    for (int i = 0; i < h; ++i) {
        for (int j = w - 1; j >= 0; --j) {
            if (s[i][j] == '#') {
                right_upper = make_pair(i,j);
                isfind = true;
            }
            if (isfind)break;
        }
        if (isfind)break;
    }

    isfind = false;
    // 右下から開始
    for (int i = h - 1; i >= 0; --i) {
        for (int j = w - 1; j >= 0; --j) {
            if (s[i][j] == '#') {
                right_lower = make_pair(i,j);
                isfind = true;
            }
            if (isfind)break;
        }
        if (isfind)break;
    }

    isfind = false;
    // 左下から開始
    for (int i = h - 1; i >= 0; --i) {
        for (int j = 0; j < w; ++j) {
            if (s[i][j] == '#') {
                left_lower = make_pair(i,j);
                isfind = true;
            }
            if (isfind)break;
        }
        if (isfind)break;
    }

    cerr << left_upper.first <<","<<left_upper.second << endl;
    cerr << left_lower.first <<","<<left_lower.second << endl;
    cerr << right_lower.first <<","<<right_lower.second << endl;
    cerr << right_upper.first <<","<<right_upper.second << endl;
    cerr << " ===== " << endl;
     // h について
    // 左上、右上
    ll minh = min(left_upper.first,right_upper.first);
    //左下、右下
    ll maxh = max(left_lower.first,right_lower.first);

    // wについて
    //左上、左下
    ll minw = min(left_lower.second,left_upper.second);
    // 右上、右下
    ll maxw = max(right_upper.second,right_lower.second);

    cerr << minh <<","<<maxh << endl;
    cerr << minw <<","<<maxw << endl;

    ll ansi,ansj;
    for (int i = minh; i <= maxh; ++i) {
        for (int j = minw; j <= maxw; ++j) {
            if (s[i][j] == '.') {
                ansi =i;
                ansj = j;
                break;
            }
        }
    }

    cout << ansi + 1 << " " << ansj + 1;


}
