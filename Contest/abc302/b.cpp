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
    ll h, w;
    cin >> h >> w;
    vector<string> s_horizon = vector<string>(0);
    vector<string> s_vertical = vector<string>(0);
    vector<pair<string,pair<int,int>>> s_cross = vector<pair<string,pair<int,int>>>(0);
    vector<pair<string,pair<int,int>>> s_cross_rev = vector<pair<string,pair<int,int>>>(0);

    vector<vector<char>> s = vector<vector<char>>(h,vector<char>(w));
    for (long i = 0; i < h; i++){
        string ss;
        cin >> ss;
        s_horizon.push_back(ss);
        for (long j = 0; j < w; j++)
        {
            s[i][j] = ss[j];
        }        
    }

    for (long i = 0; i < w; i++){
        string ss = "";
        for (long j = 0; j < h; j++)
        {
            ss += s[j][i];
        }
        s_vertical.push_back(ss);
    }

    for (long i = 0; i < h; i++){
        string ss = "";
        for (long k = 0; k < 100; k++)
        {
            if (i + k < h && 0 + k < w) {
                ss += s[i + k][0 + k];
            }
        }
        if (ss.size() > 4) {
            s_cross.push_back(make_pair(ss,make_pair(i,0)));
        }
    }

    for (long j = 0; j < w; j++)
    {
        string ss = "";
        for (long k = 0; k < 100; k++)
        {
            if (0 + k < h && j + k < w) {
                ss += s[0 + k][j + k];
            }
        }
        if (ss.size() > 4) {
            s_cross.push_back(make_pair(ss,make_pair(0,j)));
        }
    }


    // rev

    for (long i = 0; i < h; i++){
        string ss = "";
        for (long k = 0; k < 100; k++)
        {
            if (i - k > 0 && 0 + k < w) {
                ss += s[i - k][0 ];
            }
        }
        if (ss.size() > 4) {
            s_cross_rev.push_back(make_pair(ss,make_pair(i,0)));
        }
    }

    for (long j = 0; j < w; j++)
    {
        string ss = "";
        for (long k = 0; k < 100; k++)
        {
            if (h - 1 - k >= 0 && j + k < w) {
                ss += s[h - 1 - k][j + k];
            }
        }
        if (ss.size() > 4) {
            s_cross.push_back(make_pair(ss,make_pair(h - 1,j)));
        }
    }



    for (int i = 0; i < h; ++i) {
        if (s_horizon[i].find("snuke") != string::npos) {
            int index = s_horizon[i].find("snuke");
            for (int k = 0; k < 5; ++k) {
                cout << i + 1 << " "<< index + k + 1<< endl;
            }
            return 0;
        }
        if (s_horizon[i].find("ekuns") != string::npos) {
            int index = s_horizon[i].find("ekuns");
            for (int k = 4; k >= 0; --k) {
                cout << i + 1 << " "<< index + k + 1<< endl;
            }
            return 0;
        }
    }

    for (int j = 0; j < w; ++j) {
        if (s_vertical[j].find("snuke") != string::npos) {
            int index = s_vertical[j].find("snuke");
            for (int k = 0; k < 5; ++k) {
                cout << index + k + 1 << " "<< j + 1 << endl;
            }
            return 0;
        }
        if (s_vertical[j].find("ekuns") != string::npos) {
            int index = s_vertical[j].find("ekuns");
            for (int k = 4; k >= 0; --k) {
                cout << index + k + 1 << " "<< j + 1 << endl;
            }
            return 0;
        }
    }






    for (pair<string,pair<int,int>> v: s_cross) {
        string w = v.first;
        if (w.find("snuke") != string::npos) {
            int index = w.find("snuke");
            for (int k = 0; k < 5; ++k) {
                cout << v.second.first + index + k + 1<< " "<< v.second.second + index + k  + 1<< endl;
            }
            return 0;
        }
        if (w.find("ekuns") != string::npos) {
            int index = w.find("ekuns");
            for (int k = 4; k >= 0; --k) {
                cout << v.second.first + index + k + 1<< " "<< v.second.second + index + k  + 1<< endl;
            }
            return 0;
        }
    }



    // 右上
    for (pair<string,pair<int,int>> v: s_cross_rev) {
        string w = v.first;
        if (w.find("snuke") != string::npos) {
            int index = w.find("snuke");
            for (int k = 0; k < 5; ++k) {
                cout << v.second.first - index - k + 1<< " "<< v.second.second + index + k  + 1<< endl;
            }
            return 0;
        }
        if (w.find("ekuns") != string::npos) {
            int index = w.find("ekuns");
            for (int k = 4; k >= 0; --k) {
                cout << v.second.first - index - k + 1<< " "<< v.second.second + index + k  + 1<< endl;
            }
            return 0;
        }
    }

    return 0;
}
