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
        is >> x; // for(int i=0; i<vec.size(); i++) is >> x[i]; とかでもいい
    return is;
}

int main()
{
    ll n;
    string s;
    cin >> n;

    vector<pair<ll, ll>> xy(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        xy[i] = make_pair(x, y);
    }
    cin >> s;

    vector<tuple<ll, ll, bool>> xylr(n);
    for (int i = 0; i < n; i++)
        xylr[i] = make_tuple(xy[i].first, xy[i].second, ((s[i] == 'L') ? true : false));

    sort(xylr.begin(), xylr.end(), [](const tuple<ll, ll, bool> &l, const tuple<ll, ll, bool> &r)
         { return (get<1>(l) < get<1>(r)); });

    ll prev = get<1>(xylr[0]);
    ll prev_itr = 0;
    bool ans = false;

    for (int i = 1; i < n; i++)
    {
        if (get<1>(xylr[i]) != prev || i == n - 1)
        {
            ll rightFull_begin = LINF;
            ll leftFull_end = -LINF;

            for (int j = prev_itr; j < i; j++)
            {
                if (get<2>(xylr[j]) == false)
                {
                    if (rightFull_begin > get<0>(xylr[j]))
                        rightFull_begin = get<0>(xylr[j]);
                }

                if (get<2>(xylr[j]) == true)
                {
                    if (leftFull_end < get<0>(xylr[j]))
                        leftFull_end = get<0>(xylr[j]);
                }

                if (leftFull_end > rightFull_begin)
                    ans = true;
            }

            prev_itr = i;
            prev = get<1>(xylr[i]);
        }
        if (ans == true)
            break;
    }

    cout << (ans ? "Yes" : "No") << endl;
}