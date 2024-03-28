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
    vector<ll> a(3 * n);
    vector<vector<ll>> apos(n + 1,vector<ll>());

    for (int i = 0; i < n * 3; ++i) {
        cin >> a[i];
        apos[a[i]].push_back(i);
    }

    // apos は　数字 i がどこに現れるかを示したもの


    vector<pair<ll,ll>> i_fi(n);

    for (int i = 1; i <= n; ++i) {
        i_fi[i - 1] = make_pair(i, apos[i][1]);
    }

    sort(i_fi.begin(), i_fi.end(), [](pair<ll,ll> &left, pair<ll,ll> &right){
        return left.second < right.second;
    });

    //    1 ~ N について f[i] を求めて、f[i] をベースに 1~N を並び替え
    // f[i] O(1)でいけるはず

    for (int i = 0; i < n; ++i) {
        cout << i_fi[i].first;
        if (i == n - 1)continue;
        cout <<  " ";
    }



}
