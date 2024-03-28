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

// 参照わたしじゃないとダメ
ll combination(vector<ll>& p, ll n, ll depth, ll start, ll sum) {
    ll ans = 0;

    if (sum > n) {
        return 0;
    }

    if (depth == 3) {
        return 1;
    }


    ll up = p.size();
    if (depth == 0) { // たかだか 10^2 とちょっと
        up = pow(n,1.0/5.0) + 1;
    }
    if (depth == 1) { // たかだか 10^4 とちょっと
        up = pow(n/sum,1.0/3.0) + 1;
    }
    if (depth == 2) { //  10^6
        up = pow(n/sum,1.0/2.0) + 1;
    }

    for(int i = start + 1;i <up;i++) {
        ll nextSum = sum;
        if (depth == 0 || depth == 2) {
            nextSum = nextSum * p[i] * p[i];
        } else if (depth == 1) {
            nextSum = nextSum * p[i];
        }

        ll tmp = combination(p, n, depth + 1, i, nextSum);
        if (tmp > 0 ) {
            ans += tmp;
        } else {
            break;
        }
    }

    return ans;
}


int main()
{
    ll n;
    cin >> n;

    // n <= 10^12
    // a^2 * b * c^2 より c < 10^6
    // a^2 * b * c^2 より a < 10^12/5

    // Sieve of Eratosthenes
    // O(n logn logn)

    ll upper_bound = pow(10,6);
    vector<bool> sieveOfErastosthenes(upper_bound,true);
    sieveOfErastosthenes[0] = false;
    sieveOfErastosthenes[1] = false;
    cerr << upper_bound << endl;

    ll p = 2;

    while( p< upper_bound) {
        for (ll i = p * 2; i < upper_bound; i+=p) {
            sieveOfErastosthenes[i] = false;
        }
        p++;
        for (; p < upper_bound; p++) {
            if (sieveOfErastosthenes[p] == true) {
                break;
            }
        }
    }


    // calc phase
    // q : primeNumbers.size
    // q C 3 のうち、N以下の数字のもの
    vector<ll> primeNumbers{};
    for (ll i = 0; i < sieveOfErastosthenes.size(); ++i) {
        if (sieveOfErastosthenes[i] == true) {
            primeNumbers.push_back(i);
        }
    }
    ll ans = 0;
    sort(primeNumbers.begin(), primeNumbers.end());

    cerr << "size primenum " << primeNumbers.size() << endl;
    cerr << "after sort" << endl;
    ans = combination(primeNumbers, n, 0, -1, 1);

    cout << ans << endl;

    return 0;
}
