#include <iostream>
#include <string>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#define ll int64_t
#define ALL(a) \
    (a) c;     \
    .begin(), (a).end()

const ll mod = 1000000007;
const ll LINF = 1e13;
const ll LLINF = 1e18;
const ll ALPHABET = 26;

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
        is >> x; //for(int i=0; i<vec.size(); i++) is >> x[i]; とかでもいい
    return is;
}

int main()
{
    vector<string> s(3,"");
    for (int i = 0; i < 3;i++){
        cin >> s[i];
    }
   

    vector<string> d(4,"");
    d[0] = "ABC";
    d[1] = "ARC";
    d[2] = "AGC";
    d[3] = "AHC";

    string ans;

    vector<bool> b(4,false);


    for(int i = 0; i < 4; i++ ){
        cerr << "err:"<< b[i] << endl;
    }

    for (int i = 0; i < 3; i++){
    
        for (int j = 0; j < 4 ; j++) {
            cerr << "err:"<< s[i]  << "   :   " << d[j]<< endl;
            if (s[i] == d[j]){
                cerr << "err: eq" << endl;
                b[j]=true;
                break;
            }

        }
    }
    

    for(int i = 0; i < 4; i++ ){
        cerr << "err:"<< b[i] << endl;
        if (b[i] == false)
            cout << d[i] << endl;
    }
    
}