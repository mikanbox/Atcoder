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
    int n, x;
    cin >> n >> x;

    vector<pair<int,int>> ab(n);
    for (int i = 0; i < n; i++) {
        int a,b;
        cin >> a >> b;
        ab[i].first = a;
        ab[i].second = b;
    }

    vector<int> pos = vector<int>(1000000, 0);
    pos[0] = 1;
    

    for (int i = 0; i < n; i++) {
        for (int j = x; j >= 0; j--) {
            if (pos[j] > 0) {
                pos[j + ab[i].first]++;
                pos[j + ab[i].second]++;
                pos[j] = 0;
                cerr << j << ", ";
            }
        }
        cerr << endl;
    }

    cout << ((pos[x] > 0) ? "Yes" : "No") << endl;


    
}





