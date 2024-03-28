#include <bits/stdc++.h>

using namespace std;
#define ll long long

const ll mod = 1000000007;
const ll LINF = 1e13;
const ll LLINF = 1e18;
const ll ALPHABET = 26;


int main()
{
    ll h,w;
    cin >> h >> w;
    vector<string> s (h);
    for (int i = 0; i < h; ++i) {
        cin >> s[i];
    }

    //マス目は 10^3 * 10^3 で 10^6 回数

    ll ans = 0;
    vector<pair<ll,ll>> search = {
            make_pair(-1,-1),make_pair(-1,0),make_pair(-1,1),
            make_pair(0,-1 ),make_pair(0,0 ),make_pair(0,1 ),
            make_pair(1,-1 ),make_pair(1,0 ),make_pair(1,1 ),
    };

    queue<pair<ll,ll>> sensor_positions;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (s[i][j] == '#') {
                sensor_positions.push(make_pair(i,j));
            }
        }
    }


    while(!sensor_positions.empty()) {
        pair<ll,ll> pos = sensor_positions.front();
        sensor_positions.pop();
        if (s[pos.first][pos.second] != '#')continue;


        ans += 1;
        queue<pair<ll,ll>> sensor_search_tmp_positions;
        sensor_search_tmp_positions.push(pos);
        s[pos.first][pos.second] = '*';

        while(!sensor_search_tmp_positions.empty()) {
            pair<ll,ll> tmp_pos = sensor_search_tmp_positions.front();
            sensor_search_tmp_positions.pop();

            for (int k = 0; k < 9; ++k) {
                if (k == 4)continue;
                int _i = tmp_pos.first  + search[k].first;
                int _j = tmp_pos.second + search[k].second;

                if (_i < 0 || _i >= h)continue;
                if (_j < 0 || _j >= w)continue;

                if (s[_i][_j] == '#') {
                    sensor_search_tmp_positions.push(make_pair(_i,_j));
                    s[_i][_j] = '*';
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
