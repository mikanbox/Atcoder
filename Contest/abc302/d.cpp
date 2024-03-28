#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define ALL(a)  (a) c;.begin(),(a).end()

const ll mod = 1000000007;
const ll LINF = 1e13;
const ll LLINF = 1e18;
const ll ALPHABET = 26;

template <class T>
void Swap(T& r, T& l) {
    T tmp = r;
    r = l;
    l = tmp;
}

template<typename T>
istream& operator >> (istream& is, vector<T>& vec) {
    for (T& x : vec) is >> x; //for(int i=0; i<vec.size(); i++) is >> x[i]; とかでもいい
    return is;
}


int main(){
    ll  n,m,d;
    cin >> n >> m >> d;
    vector<ll> a(n);
    vector<ll> b(m);


    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }



    ll ans =  -1;
    // nlogn
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    //n,m < 10^5
    // n * m < 10^10

    ll b_lowerboundIndex = 0;
    ll b_upperboundIndex = 0;

    // 10^5
    for (int i = 0; i < n; ++i) {
        ll _a = a[i];
        ll _lowerboundValue = _a - d;
        ll _upperboundValue = _a + d;

        for (ll j = b_lowerboundIndex; j < m; ++j) {
            if (b[j] >= _lowerboundValue) {
                b_lowerboundIndex = j;
                break;
            } else {
                b_lowerboundIndex = j;
            }
        }

        for (ll j = b_upperboundIndex; j < m; ++j) {
            if (b[j] > _upperboundValue) {
                b_upperboundIndex = j;
                break;
            } else {
                b_upperboundIndex = j;
            }
            if (j == m - 1) {
                b_upperboundIndex = j + 1;
            }
        }

        if (abs(_a - b[b_lowerboundIndex]) <= d ) {
            ans = max(ans, b[b_lowerboundIndex] + _a);
        }
        if (b_upperboundIndex > 0) {
            if (abs(b[b_upperboundIndex - 1] - _a) <= d) {
                ans = max(ans, b[b_upperboundIndex- 1] + _a);
            }
        }
    }
    cout << ans << endl;
}
