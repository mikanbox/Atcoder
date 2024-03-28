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
    vector<pair<ll,ll>> td(n);
    for (int i = 0; i < n; ++i) {
        ll t,d;
        cin >> t >> d;
        td[i] = make_pair(t,t + d);
    }


    // 区間スケジューリング問題
    sort(td.begin(), td.end(), [](pair<ll,ll>&left,pair<ll,ll>&right ){
        return (left.first < right.first);
    });

    ll ans = 0;
    ll curtime = 1;

    priority_queue<
            ll,
            std::deque<ll>,
            std::greater<ll>
    > endqueue;


    ll i = 0;
    while(true) {
        if (endqueue.size() ==0 && i == td.size())break;
//        cerr << "curtime : " << curtime << " : i " << i << " "<<  td.size() << endl;
        if (i < td.size()) {
            if (td[i].first <=curtime ) { // ここの条件がおかしい
                endqueue.push(td[i].second);
                i++;
                continue;
            } else if (endqueue.empty()) {
                curtime = td[i].first;
                endqueue.push(td[i].second);
                i++;
                continue;
            }
        }
//        cerr << "====  " << endqueue.size() << endl;
        while (!endqueue.empty()) {
            ll end = endqueue.top();
            endqueue.pop();

            if (end >= curtime) {
//                cerr << "find  :" << end << endl;
                ans++;
                curtime++;
                break;
            }
        }

    }

    cout << ans << endl;
}
