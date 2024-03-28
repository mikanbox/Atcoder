#include <bits/stdc++.h>

using namespace std;
#define ll long long

const ll mod = 1000000007;
const ll LINF = 1e13;
const ll LLINF = 1e18;
const ll ALPHABET = 26;


int main()
{
    ll n;
    cin >> n;

    if (n < pow(10,3)) {
        cout << n << endl;
        return 0;
    }

    ll digit = to_string(n).length();
    if (digit <= 3) {
        cout << n << endl;
        return 0;
    }

    ll diff = digit - 3;
    cerr << diff << endl;
    cerr << pow(10,diff) << endl;
    cerr << n << endl;


    ll z = pow(10,diff);
    ll p = (n /  z);
    cerr << p << endl;
    p = p * z;



    cout << p << endl;
    return 0;

}
