#include <string>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define ll int64_t


bool isBlackContinued(ll y, ll x, int direction, vector<string> &s ) {
    bool ans = false;
    ll lastpos = 0;
    queue<ll> que;

    for (int i = 0; i < 2 * s.size(); i++) {
        if (s[y][x] == '.') {
            if (que.size() < 2) {
                que.push(i);
            } else {
                lastpos = que.front() + 1;
                que.pop();
                que.push(i);
            }
        }

        if (i + 1 - lastpos >= 6) {
            ans = true;
            break;
        }

        switch (direction) {
        case 1:
            x++;
            break;
        case 2:
            y++;
            break;
        case 3:
            x++;
            y++;
            break;
        }
        if (x >= s.size() || y >= s.size())
            break;

    }

 
    return ans;
}


int main(void) {
    ll n;
    cin >> n;
    vector<string> s(n,"");

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    // n^2 = 10^6
    // 全探索は高々一回のみ

    //縦、横、斜め、に探索であれば nで済むため、n^2 は余裕で回せる
    bool ans = false;
    // isBlackContinued(initx,inity, direction)
    for (int i = 0; i < n; i++) {
        ans = ans || isBlackContinued(i, 0, 1, s);
        ans = ans || isBlackContinued(0, i, 2, s);

        ans = ans || isBlackContinued(0, i, 3, s);
        ans = ans || isBlackContinued(i, 0, 3, s);
    }

    cout << (ans ? "Yes" : "No") << endl;


}