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
    ll n;
    cin >> n;
    string s;
    cin >> s;


    ll q;
    cin >> q;
    vector<char> c(q);
    vector<char> d(q);
    for (ll i = 0; i < q; ++i) {
        cin >> c[i] >> d[i];
    }

    // query は10^5あるけど、文字は27文字しかない
    map<char,vector<char>> charset;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < alphabet.length(); ++i) {
        charset[alphabet[i]] = vector<char>(1,alphabet[i]);
    }

    // charset[変換先] = {変換元文字}
    for (ll i = 0; i < q; ++i) {
//        c[i] 変換元
//        d[i] 変換先
        for (auto v : charset[c[i]]) {
            charset[d[i]].push_back(v);
        }
        charset[c[i]].clear();
    }

    for (int i = 0; i < alphabet.length(); ++i) {
        cerr <<  alphabet[i] << " :";
        for (auto v : charset[alphabet[i]]) {
            cerr << v <<",";
        }
        cerr << endl;
    }


    string ans = s;

    for (ll i = 0; i < alphabet.length(); ++i) {//27
        for (auto v : charset[alphabet[i]]) {//1~27

            for (ll j = 0; j < s.length(); ++j) {
                if (s[j] == v){
                    ans[j] = alphabet[i];
                }
            }
        }

    }
    cout << ans << endl;



}