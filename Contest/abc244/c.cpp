#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define ll int64_t



int main(void)
{
    ll n;
    cin >> n;

    vector<bool> used_num(n * 2 + 1 + 1);
    used_num[0] = true;
    ll minimum_num = 1;


    while (true) {
        ll input;
        cout << minimum_num << endl;
        used_num[minimum_num] = true;
        cin >> input;
        if (input == 0)
            break;
        
        used_num[input] = true;
        for ( ; minimum_num < used_num.size(); minimum_num++) {
            if (used_num[minimum_num] == false)
                break;
        }
    }
}