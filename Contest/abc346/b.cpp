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
    ll w;
    ll b;
    cin >> w >> b;

    string basekey = "wbwbwwbwbwbw"; // w は 7 こ、b は 5 こ
    string basekeydouble = "wbwbwwbwbwbwwbwbwwbwbwbw"; // w は 7 こ、b は 5 こ
    // (_w,_b) = (7 * w + 5 * b) * k + max(7), max(5)

    for (int i = 0; i < 200; ++i) {
        if (w > 7 && b > 5) {
            w -= 7;
            b -= 5;
        } else {
            break;
        }
    }

    if (w==0 && b==0) {
        cout << "Yes" << endl;
        return 0;
    }

    // 残りのペアが  basekeydouble の部分文字列で実現できればOK
    for (int i = 0; i < basekeydouble.length(); ++i) {
        for (int j = i; j < basekeydouble.length(); ++j) {
            string tmp = basekeydouble.substr(i, (j-i + 1));
            int _w = count(tmp.begin(),tmp.end(),'w');
            int _b= count(tmp.begin(),tmp.end(),'b');
            if (b == _b && w == _w) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;

}
