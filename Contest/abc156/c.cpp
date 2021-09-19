#include <iostream>
#include <string>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#define ll long long
#define ALL(a)  (a) c;.begin(),(a).end()
 
const ll mod = 1000000007;
const ll LINF = 1e13;
const ll LLINF = 1e18;
const ll ALPHABET = 26;
 
template <class T>
void Swap(T& r, T& l) 
{
  T tmp = r;
  r = l;
  l = tmp;
}
 
template<typename T>
istream& operator >> (istream& is, vector<T>& vec) 
{
  for (T& x : vec) is >> x; //for(int i=0; i<vec.size(); i++) is >> x[i]; とかでもいい
  return is;
}
 

 
int main(){
    ll n;
    vector<ll> x;
    cin >> n ;
    x.resize(n);

    cin >> x;

    ll ans = LLINF;

    for (int b = 1; b <= 100; b ++ ) {
        ll t = 0;
        for (int i = 0; i < n; i++) {
            t += (x[i] - b) * (x[i] - b);
        }
        if (ans > t) 
            ans = t;

    }
 
  cout << ans << endl;
}