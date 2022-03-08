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

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    cin >> a;

    stack< pair<int,int> > cylinder;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        
        if (cylinder.size() == 0) {
            cylinder.push(make_pair(a[i],1));
        } else {
            if (cylinder.top().first == a[i]) {
                cylinder.top().second++;
            } else {
                cylinder.push(make_pair(a[i],1));
            }
        }
        ans++;

        if ( cylinder.top().second == cylinder.top().first ) {
            ans-= cylinder.top().second;
            cylinder.pop();
        }

        cout << ans << endl;
    }


    
}

