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


ll llpow(ll x, ll y) {
    ll res = 1;
    for (int i = 0; i < y; ++i) {
        res *= 2;
    }
    return res;
}

ll getNumFromString(string s) {
    ll ans = 0;
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '1') {
            ans += llpow(2, (i ));
        }
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    ll n;
    cin >> n;
    string _n = "";
    vector<ll> q_index;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '?')
            q_index.push_back(i);
    }


    // ? を消していくことで、値を探索
    // s の中から、 key(n) より一つ大きいものを探す
    // key以上を返す

    vector<pair<ll,char>> ans_index;


    for (auto q:q_index) {
        string _s = s;

        // 未確定部分のうち、2^n =1 として　n-1 は 0 とした値を出す
        _s.replace(q,1,"1");
        replace(_s.begin(), _s.end(), '?', '0');
        ll num = getNumFromString(_s);
        cerr << "num : " << num << endl;

        // n より大きいなら、0にする。なぜなら 2^ n-1 の和は 2^n に届かないから
        if (num > n) {
            s.replace(q,1,"0");
//            ans_index.push_back(make_pair(q,'1'));
        } else {
            s.replace(q,1,"1");
//            ans_index.push_back(make_pair(q,'0'));
        }
    }

    cerr << s <<endl;

    ll ans = getNumFromString(s);
    if (ans > n) {
        ans = -1;
    }
    cout << ans << endl;



    return 0;
}
