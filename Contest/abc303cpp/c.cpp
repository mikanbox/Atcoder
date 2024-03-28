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
    string s;
    string t;
    cin >> s >> t;
//    std::sort(s.begin(), s.end());
//    std::sort(t.begin(), t.end());
    map<char,int> sc;
    map<char,int> tc;
    string alph = "abcdefghijklmnopqrstuvwxyz";
    for (auto c:alph) {
        sc[c] = 0;
        tc[c] = 0;
    }
    sc['@'] = 0;
    tc['@'] = 0;
    for (auto c:s) {
        sc[c]+=1;
    }
    for (auto c:t) {
        tc[c]+=1;
    }

    string atcoder = "atcoder";
    bool ans = true;

    // 違うものを数えて、@が足りるか計算
    int snum = 0;
    int tnum = 0;
    for (auto c:alph) {
        if (sc[c] > tc[c]) {
            cerr << "s: " << c<< endl;
            snum+= sc[c] - tc[c];
            if (atcoder.find(c) == string::npos)
                ans = false;
        }
        if (sc[c] < tc[c]) {
            cerr << "t: " << c<< endl;
            tnum+= tc[c] - sc[c];
            if (atcoder.find(c) == string::npos)
                ans = false;
        }
    }

    if (snum > 0) {
        if (tc['@']  < snum) {
            ans = false;
        }
    }
    if (tnum > 0) {
        if (sc['@'] < tnum) {
            ans = false;
        }
    }

    cout << ((ans)?"Yes":"No") <<endl;
    return 0;
}
