#include <iostream>
#include <string>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;
#define ll int64_t
#define ALL(a) \
    (a) c;     \
    .begin(), (a).end()

const ll mod = 1000000007;
const ll LINF = 1e13;
const ll LLINF = 1e18;
const ll ALPHABET = 26;

template <class T>
void Swap(T &r, T &l)
{
    T tmp = r;
    r = l;
    l = tmp;
}

template <typename T>
istream &operator>>(istream &is, vector<T> &vec)
{
    for (T &x : vec)
        is >> x; //for(int i=0; i<vec.size(); i++) is >> x[i]; とかでもいい
    return is;
}

int main()
{
    string s;
    ll q;
    cin >> s;
    cin >> q;

    // vector< tuple<ll, ll, ll> > tk(q);

    // for (int i = 0; i < q; i++) {
    //     ll t,k;
    //     cin >> t >> k;

    //     tk[i] = make_tuple(i, t, k);
    // }

    // sort(tk.begin(),tk.end(),[](tuple<ll, ll, ll> const& lhs, tuple<ll, ll, ll> const& rhs) {
    //     return get<1>(lhs) < get<1>(rhs); // 左の方が大きい...というイメージ。
    // });

    // vector<string> s_(100);
    // for( int i = 0; i < 100; i++) {

    // }
    // 文字列抱えるのは無理


    vector<pair< ll,ll>> tk(q);
    for (int i = 0; i < q; i++) {
        ll t,k;
        cin >> t >> k;

        tk[i] = make_pair(t, k);
    }

    for (int i = 0; i < q; i++) {
        ll t_ = tk[i].first;
        ll k_ = tk[i].second - 1;

        ll dig = 0;
        ll two_pow = 1;
        for (int j = 1; j <= t_; j++) {
            two_pow *= 2;
            dig++;
            if (two_pow > k_) 
                break;
        }

        ll md = (k_) % two_pow;
        ll b = k_ / two_pow;

         // b番目の文字列を t 回増加させた時の md + 1 番目
        // //  一発で出せそう?
        // ll dig = 1;
        // for (dig = 1; dig <= 100; dig++ ) {
        //     if ( (1 << dig) > k_)
        //         break;
        // }

        // k は 2^digより小さい
        char ans = s[b];
        // cerr << "k_  : " << k_ << endl;
        // cerr << "md : " << md << " two_pow " << two_pow << "   : dig " << dig << endl;
        // cerr << "first ans : " << ans << endl;

        char nextans;
        for (int l = dig - 1 ; l >= 0; l--) {
            if ((md >> l) & 1) {
                if (ans == 'A')
                    nextans = 'C';
                if (ans == 'B')
                    nextans = 'A';
                if (ans == 'C')
                    nextans = 'B';
            } else {
                if (ans == 'A')
                    nextans = 'B';
                if (ans == 'B')
                    nextans = 'C';
                if (ans == 'C')
                    nextans = 'A';
            }
            ans = nextans;
        }
        cout << ans << endl;

    }


}