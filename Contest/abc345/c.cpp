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


int main() {
    string s;
    cin >> s;

    vector<ll> count(26, 0);
    for (auto c: s) {
        count[c - 'a']++;
    }
//    for (auto c: "abcdefghijklmnopqrstuvwxyz") {
//        cerr << c << " : " <<  count[c - 'a'] << endl;
//    }

    string s2 = "abcdefghijklmnopqrstuvwxyz";

    ll ans = 0;
    bool isSameSwap = false;
    for (auto c: s) {
//        cerr << c << " : " <<  count[c - 'a'] << endl;
        count[c - 'a']--;

//        for (int i = 0; i < 26; i++) {
//            char c2 = s2[i];
//            if (c == c2) {
//                if (count[c2 - 'a'] > 0) {
//                    isSameSwap = true;
//                }
//                continue;
//            }
//            ans += count[c2 - 'a'];
//        }

//        auto 使った時がダメっぽい???なぜだろう。なんか違う変数になっているか iter になってるからかな.
// 埋め込みリテラルがダメな説もある。埋め込みがダメっぽい感じあるな。 string 型として定義されてないからかも。



        for (char i: s2) {
            if ((c - 'a') == (i - 'a')) {
                if (count[(i - 'a')] > 0) {
                    isSameSwap = true;
                }
                continue;
            }
            ans += count[(i - 'a')];
        }

//        for (auto c2: "abcdefghijklmnopqrstuvwxyz") {
//            if (c == c2) {
//                if (count[c2 - 'a'] > 0) {
//                    isSameSwap = true;
//                }
//                continue;
//            }
//            ans+=count[c2 - 'a'];
//        }
    }


    if (isSameSwap)
        ans++;
    cout << ans << endl;

}
