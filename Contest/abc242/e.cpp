#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
#define ll int64_t


const ll LINF = 1e13;
const ll LLINF = 1e18;
const ll ALPHABET = 26;


template <typename T>
istream &operator>>(istream &is, vector<T> &vec)
{
    for (T &x : vec)
        is >> x; //for(int i=0; i<vec.size(); i++) is >> x[i]; とかでもいい
    return is;
}

ll mod = 998244353;
vector <ll> pow_26_k(1000001);


ll CalcPattern(ll s_index, ll s_length, string &s) {
    ll k = (s_length + 1)/ 2 - (s_index + 1); // 中心となる添字番号からの距離(偶奇対応)

    if (k == 0) {
        string s2 = s;
        for (int j = 0; j <= s_index; j++)
            s2[s_length - 1 - j] = s2[j];
        if (s2 > s) 
            return (int)(s[s_index] - 'A' );
        return (int)(s[s_index] - 'A' + 1) ;
    }

    // 対象の char より一つ若い char については、内側の char は何でも良いため 26^kとなる
    // 対象の chat と同じ char を使う場合は、内側の結果に依存するため再帰
    return (pow_26_k[k] * (s[s_index] - 'A') + CalcPattern(s_index + 1, s_length, s)) % mod;
}


int main()
{
    ll t;
    cin >> t;

    pow_26_k[0] = 1;
    for (int i = 1; i <= 1000000; i++) 
        pow_26_k[i] = pow_26_k[i - 1] * ALPHABET % mod;
    

    for (int i = 0; i < t; i++) {
        ll n;
        string s;
        cin >> n;
        cin >> s;

        ll ans = CalcPattern(0, n, s);
        cout << ans << endl;
    }
}