#include <iostream>

using namespace std;

int main(void) {
    long a,b,k;
    cin >> a >> b >> k;

    long ans = 0;
    for (long i = 0; i < b; i++) {
        if (a >= b)
            continue;
        a *= k;
        ans++;
    }
    cout << ans << endl;
}