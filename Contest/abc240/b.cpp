#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
#define ll int64_t

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

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    cin >> a;

    set<int> se;
    for (auto v : a) {
        se.insert(v);
    }

    cout << se.size	() <<endl;
    
}


