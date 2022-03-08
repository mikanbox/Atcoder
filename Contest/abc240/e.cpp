#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;
#define ll int64_t;

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
        is >> x;
    return is;
}


int main(void) {
    int n;
    cin >> n;

    vector<pair<int,int>> edge(n - 1);
    for (int i = 0; i < n; i++ ) {
        int u,v;
        cin >> u >> v;
        edge[i] = make_pair(u, v);
    }

    
    for (auto e : edge) {
        cerr << e.first << " --- " << e.second << endl;
    }



    return 0;
}