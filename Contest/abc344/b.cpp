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
    vector<ll> a;

    while(true){
        ll b;
        cin >> b;
        a.push_back(b);
        if (b == 0)
            break;
    }

    std::reverse(a.begin(), a.end());


    for (auto v:a) {
        cout << v << endl;
    }

}