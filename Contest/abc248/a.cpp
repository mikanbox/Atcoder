#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
    string s;
    cin >> s;

    vector<bool> num(10,false);

    for(auto v:s) {
        num[v - '0'] = true;
    }

    for(int i = 0; i < 10; i++) 
        if (num[i] == false)
            cout << i << endl;

}