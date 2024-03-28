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

    ll n, m;
    cin >> n >> m;
    vector<ll> a(m);

    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }

    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    vector<ll> score(n,0);
    for (int i = 0; i < n; ++i) {
        score[i] += i + 1;
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == 'o') {
                score[i] += a[j];
            }
        }
    }

    for (auto v:s) {
        cerr << v << endl;
    }
    for (auto v:score) {
        cerr << v << endl;
    }

    ll maxScore = *max_element(score.begin(), score.end());
    cerr << "maxScore : "<< maxScore << endl;

    vector<pair<ll,ll>> problem_score(m);
    for (int i = 0; i < m; ++i) {
        problem_score[i] = make_pair(a[i],i);
    }

//    for (auto v:problem_score) {
//        cerr << v.first << ":"<< v.second<< endl;
//    }

    cerr << "sort " << endl;
    sort(problem_score.begin(), problem_score.end(),[](pair<ll,ll>&left, pair<ll,ll>&right){
        return left.first > right.first;
    });

//    cerr << "to ans " << endl;

    for (int i = 0; i < n; ++i) {
        ll ans = 0;
        ll sc = score[i];
        cerr << sc << endl;
        for (auto v:problem_score) {
            if (sc >= maxScore) {
                break;
            }
            if (s[i][v.second] == 'x'){
                sc+= v.first;
                ans++;
            }
        }

        cout << ans << endl;
    }


    return 0;
}
