#include <iostream>
#include <string>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <map>

using namespace std;
#define ll int64_t

const ll mod = 1000000007;
const ll LINF = 1e13;
const ll LLINF = 1e18;
const ll ALPHABET = 26;

template <typename T>
istream &operator>>(istream &is, vector<T> &vec)
{
    for (T &x : vec)
        is >> x; // for(int i=0; i<vec.size(); i++) is >> x[i]; とかでもいい
    return is;
}

int main()
{
    ll n, x;
    cin >> n >> x;
    string s;
    cin >> s;

    ll ans = x;

    // 方針
    // U が入力されると、直前の L / R が無効になるので、 まずは S を改良し、 除ける U を除く
    // S'は最終的に必ず 10^18より小さくなり、取り除けるU がないならそのまま計算できるはず


    string s_ = "";
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == 'U')
        {
            if (s_.size() == 0)
            {
                s_.push_back('U');
                continue;
            }
            if (s_.back() == 'U')
            {
                s_.push_back('U');
                continue;
            }
            if (s_.back() != 'U')
            {
                s_.pop_back();
                continue;
            }
        }
        else
        {
            s_.push_back(s[i]);
        }
    }


    for (auto c : s_) {
        switch (c)
        {
        case 'U':
            ans = ans / 2;
            break;
        case 'L':
            ans = ans * 2;
            break;
        case 'R':
            ans = ans * 2 + 1;
            break;
        }
    }


    cout << ans << endl;
}