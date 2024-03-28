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
    string s;
    cin >> n;
    cin >> s;


    ll win = n/2 + n%2;
    ll a = 0;
    ll t = 0;

    cerr << n  <<endl;
    cerr << s <<endl;
    cerr << win <<endl;
    for (char v:s) {
        cerr << v  <<endl;
        cerr << a  <<" , " << t << endl;
        if (v == 'A') {
            a++;
            if (a >= win) {
                cout << "A";
                return 0;
            }
        }
        if (v == 'T') {
            t++;
            if (t >= win) {
                cout << "T";
                return 0;
            }
        }
    }
    cerr << a  <<" , " << t << endl;

    return 0;
}
