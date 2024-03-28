#include <iostream>
#include <vector>
// #include <algorightm>
#include <map>
#include <tuple>
// #include <cstudio>

using namespace std;
#define ll int64_t
#define ALL(a)  (a) c;.begin(),(a).end()

const ll mod = 1000000007;
const ll LINF = 1e13;
const ll LLINF = 1e18;
const ll ALPHABET = 26;

template <class T>
void Swap(T& r, T& l) {
  T tmp = r;
  r = l;
  l = tmp;
}

template<typename T>
istream& operator >> (istream& is, vector<T>& vec) {
  for (T& x : vec) is >> x; //for(int i=0; i<vec.size(); i++) is >> x[i]; とかでもいい
  return is;
}


int main(){
  string a;
  cin >> a;

  string ans = "ABC";
  if (a=="ABC")ans="ARC";

  cout << ans;

}
