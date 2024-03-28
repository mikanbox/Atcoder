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
    vector<ll> a (n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<ll> a_ans (0);


    for (int i = 0; i < n - 1; ++i) {
//        a_ans.push_back(a[i]);
        if (  abs(a[i] - a[i+1]) > 1 ) {
            int d = 1;
            if (a[i] > a[i+1])d = -1;
            for (int j = a[i]; j != a[i+1]; j+=d) {
                a_ans.push_back(j);
            }
        }else {
            a_ans.push_back(a[i]);
        }
    }

    a_ans.push_back(a[n - 1]);
    for (auto v:a_ans) {
        cout << v << " ";
    }

    return 0;
}
