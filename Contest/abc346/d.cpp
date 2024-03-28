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


void reverse_char(int i, string &s) {
    s[i] = (s[i] == '1') ? '0' : '1';
}

int main() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> c(n);

    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    //基本 101010101010 で部分的に00 or 11 が現れる
    // 長さnの場合 2n ちょいぐらい？
    // 11で考えた後反転すればいいから 2 * (n-1)か。 長さ n-1 の文字列の (n-1 + 1)の どこかに 1 をはさむ処理をすればOK?

    // pattern はnだから、コスト計算が logn 以下でできればOK
    // 前のコストとの差分で出せるので以外と簡単説ある

    ll ans = LLINF;
    string base_head1, base_head0;

    for (int i = 0; i < n - 1; ++i) {
        base_head1 += (i % 2 == 0)?"1":"0";
        base_head0 += (i % 2 == 0)?"0":"1";
    }



    //110101 -> 100101 -> 101101 -> 101001 -> 101011
    //001010 -> 011010 -> 010010 -> 010110 -> 010100
    string base_head11 = "1" + base_head1;
    cerr << "base_head11  " << base_head11 << endl;
    string base_head00 = "0" + base_head0;
    cerr << "base_head00  " << base_head00 << endl;


    ll base_head11_initcost = 0;
    ll base_head00_initcost = 0;
    for (int i = 0; i < n; ++i) {
        if (base_head11[i] != s[i]) {
            base_head11_initcost += c[i];
        }
        if (base_head00[i] != s[i]) {
            base_head00_initcost += c[i];
        }
    }
    ans = min(ans, base_head11_initcost);
    ans = min(ans, base_head00_initcost);


    // i -1 と i を反転する
    for (int i = 1; i < n - 1; ++i) {
        reverse_char(i, base_head11);
        base_head11_initcost = ((base_head11[i] == s[i]) ? base_head11_initcost - c[i] : base_head11_initcost + c[i]);

        reverse_char(i, base_head00);
        base_head00_initcost = ((base_head00[i] == s[i]) ? base_head00_initcost - c[i] : base_head00_initcost + c[i]);

        ans = min(ans, base_head11_initcost);
        ans = min(ans, base_head00_initcost);
    }

    cout << ans << endl;

}


