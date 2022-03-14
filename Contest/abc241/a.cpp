#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

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
    vector<ll> a(10);
    cin >> a;


    cout << a[a[a[0]]] << endl;

}