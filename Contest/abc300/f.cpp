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



ll get_longest_length(string s2, ll k, bool isCenter) {
    cerr << s2 << endl;
    cerr << " ==== " << "get_longest_length" << endl;
    cerr << "k  " << k<< endl;

    // oxox|ooxoxoxooxoxooxxxoxxxooxoxoxoxooxoxoxooxoxoo|xxxoxxxooxox


    ll ans = 0;
    ll x_count = 0;
    ll left = 0;
    ll right = 0;

    for (ll i = 0; i < s2.size(); ++i) {
        if (s2[i] == 'x') {
            x_count++;
            if (x_count > k) {
                for (ll j = left; j < s2.size(); ++j) {
                    if (s2[j] == 'x') {
                        left = j + 1;
                        x_count--;
                        break;
                    }
                }
            }
        }

        right = i;
        // xxxxxxxxx  [0, left, right,  2n]
        if ( ans < right - left + 1) {
            if (isCenter) {
                if (right >= s2.size() / 2 - 1 && left <= s2.size() / 2 ) {
                    ans = right - left + 1;
                }
            } else {
                ans = right - left + 1;
            }
        }

//        cerr << " [left , right] " << left << " , " << right  << "  count " << x_count << "   ans :  "  <<ans<<endl;
    }
//    cerr << "len : " << ans << endl;
    return ans;
}

int main()
{

    ll n,m,k;
    cin >> n >> m >> k;
    string s;
    cin >> s;

    // s * m 連結したもの t:
    // t : 10^5 * 10^9 の長さ

    // k こだけoに変えることで、一番長くするためには

    // これそんなに難しいかな? 場合わけがだるそう.
    // ぶっちゃけ s 二つ繋げた物に対して探索すれば良さそう

    string s2 = s + s;

    // まず一つの s に含まれる x を数える 10^5
    ll x_num = 0;
    for (auto c:s) {
        if (c == 'x') {
            x_num++;
        }
    }


    ll s_num = k / x_num;
    ll k_remain = k % x_num;

    cerr << "s_num " << s_num << endl;
    cerr << "k_remain " << k_remain << endl;
    // s_num は s 何個分なのか

    // k が全部おおっちゃう場合、
    if (s_num >= m) {
        cerr << "s_num >= m" << endl;
        cout <<  (s_num * n)  << endl;
        return 0;
    }
//    s一個分あまる
    if (s_num >= m - 2) {
        cerr << "s_num >= m - 1" << endl;
        ll ans = get_longest_length(s2, k_remain,  false);
        ans += (s_num) * n;
        cout << ans << endl;
        return 0;
    }

    if (s_num <= m - 3 && s_num > 0) {
        cerr << "s_num <= m - 2 && s_num > 0" << endl;
        k_remain += x_num;
        ll ans = get_longest_length(s2, k_remain,  true);
        ans += (s_num - 1) * n;
        cout << ans << endl;
        return 0;
    }
    if (s_num == 0) {
        cerr << "s_num == 0" << endl;
        ll ans = get_longest_length(s2, k_remain,  false);
        cout << ans << endl;
        return 0;
    }


    return 0;
}
