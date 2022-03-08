#include <iostream>
#include <string>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#define ll int64_t

const ll mod = 1000000007;
const ll LINF = 1e13;
const ll LLINF = 1e18;

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

int main()
{
    
    int a;
    int b;
    cin >> a >> b;

    cout << ( ((b - a)  == 1 || (b - a) == 9)  ? "Yes" : "No" ) << endl;
    
}