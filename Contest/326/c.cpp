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


// 配列 a を先頭からみていき、最大数になったものを返す
ll solv(vector<ll> &a, ll m) {
    ll ans = 0;

    cerr << m << endl;

    ll right_idnex = 0;
    ll left_index = 0;
    ll count = 0;

    for (right_idnex = 0; right_idnex < a.size(); ++right_idnex) {
        count++;
//        cerr << count <<" loop : " <<a[left_index] <<" - "<< a[right_idnex] << endl;

        for(;left_index < right_idnex; left_index++){
            if (abs(a[right_idnex] - a[left_index]) >= m) {
                count--;
            } else {
                break;
            }
        }
        if (count > ans) {
            ans = count;
        }
    }

    return ans;
}



int main()
{
    ll n,m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // これ問題の言い換えできる
    // 右半開区間と、左半開区間 で調べればいいのでは？
    // n は 10^5

    // 尺取式にやれば良さそう

    ll ans = 0;

    sort(a.begin(), a.end());
    ans = max(solv(a,m), ans);
    reverse(a.begin(), a.end());

    ans = max(solv(a,m), ans);

    cout << ans << endl;

}
