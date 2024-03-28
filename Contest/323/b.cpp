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
    vector<string>s(n,string(n,'-'));
    vector<pair<ll,ll>> s_win(n);

    for (int i = 0; i < n; ++i) {
        string c;
        cin >> c;
        ll count = 0;
        for (auto cc:c) {
            if (cc == 'o') {
                count++;
            }
        }
        s_win[i] = make_pair(count,i + 1);
//        s_win[i] = make_pair(count(c.begin(),c.end(),'o'),i + 1);
    }

    sort(s_win.begin(), s_win.end(),[](pair<ll,ll> &left,pair<ll,ll> &right)
    {
        return left.first * 10000 - left.second > right.first  * 10000 - right.second;
    }
    );


//    for (int i = 0; i < s_win.size(); ++i) {
//        cerr << s_win[i].first << " : " <<s_win[i].second << endl;
//    }


    for (int i = 0; i < s_win.size(); ++i) {
        cout << s_win[i].second;
        if (i != s_win.size() - 1) {}
        cout << " ";
    }


    return 0;
}
