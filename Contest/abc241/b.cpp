#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
#define ll int64_t


template <typename T>
istream &operator>>(istream &is, vector<T> &vec)
{
    for (T &x : vec)
        is >> x; // for(int i=0; i<vec.size(); i++) is >> x[i]; とかでもいい
    return is;
}


int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<ll> b(m);

    cin >> a;
    cin >> b;
 
    // vector<ll> a_(1000000001,0);
    map<ll,ll> a_;
    for (auto v : a) 
        a_[v]++;
    

    bool ans = true;

    for (auto v : b) {
        if (a_.find(v) == a_.end()) {
            ans = false;
            break;
        }
        if (a_[v] <= 0) {
            ans = false;
            break;
        }
        a_[v]--;
    }
    

    cout << (ans ? "Yes" : "No") << endl;
}