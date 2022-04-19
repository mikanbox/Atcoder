#include <iostream>
#include <string>
using namespace std;
#define ll int64_t



int main(void)
{
    ll n;
    string t;
    cin >> n;
    cin >> t;

    ll direction = 0;
    ll x = 0;
    ll y = 0;

    for (auto v: t) {
        if (v == 'S') {
            switch (direction) {
                case 0:
                    x++;
                    break;
                case 1:
                    y--;
                    break;
                case 2:
                    x--;
                    break;
                case 3:
                    y++;
                    break;
            }
        } else {
            direction = (direction + 1) % 4;
        }
    }
    
    cout << x << " " << y << endl;
    return 0;
}