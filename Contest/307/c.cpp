#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define ALL(a) \
    (a) c;     \
    .begin(), (a).end()

const ll mod = 1000000007;
const ll LINF = 1e13;
const ll LLINF = 1e18;
const ll ALPHABET = 26;

void printmap(vector<string>& ab) {
    cerr << " ==== " << endl;
    for (auto v:ab) {
        cerr << v << endl;
    }
}

bool check(vector<string>& ab, vector<string>& x, ll hx, ll wx) {
    printmap(ab);

    //    4点全部出しとく
    ll left = 100,right= -1,upper = 100,lower = -1;
    for (int i = 0; i < ab.size(); ++i) {
        for (int j = 0; j < ab[i].size() ; ++j) {
            if (ab[i][j] == '#') {
                if (left > j) {
                    left = j;
                }
                if (right < j) {
                    right = j;
                }
                if (upper > i) {
                    upper = i;
                }
                if (lower < i) {
                    lower = i;
                }
            }
        }
    }
    cerr << left <<" , " << right <<" , "<< upper <<" , " << lower << endl;


    cerr << "hxwx" << endl;
    cerr << hx << " , " << wx << endl;

    for (int i = 0; i < ab.size() - hx; ++i) {
        for (int j = 0; j < ab[i].size() - wx; ++j) {
            bool ans = true;

            if (left < j || right > j + hx || upper < i || lower > i + wx){
                cerr << "out bounds" << endl;
                continue;
            }


            for (int k = 0; k < x.size(); ++k) {
                for (int l = 0; l < x[k].size(); ++l) {
                    if (ab[i + k][j + l] != x[k][l]) {
                        ans = false;
                        break;
                    }
                }
            }

            if (ans == true) {
                cerr << "find" << endl;
                cerr << i << " , " << j << endl;
                cerr << hx << " , " << wx << endl;
                return true;
            }


        }
    }

    return false;
}



int main()
{
    ll ha,wa;
    cin >> ha >> wa;
    vector<string> a(ha);
    for (int i = 0; i < ha; ++i) {
        cin >> a[i];
    }

    ll hb,wb;
    cin >> hb >> wb;
    vector<string> b(hb);
    for (int i = 0; i < hb; ++i) {
        cin >> b[i];
    }

    ll hx,wx;
    cin >> hx >> wx;
    vector<string> x(hx);
    for (int i = 0; i < hx; ++i) {
        cin >> x[i];
    }


    // a を起点にbの重ね方を全パターン割り出して、それに対してxを全パターン重ねる
    // 重ね方は、 (hb + ha + hb) * (wb + wa + wb)

    // 取り出し方は
    // (hb + ha + hb - hx) * (wb + wa + wb - wx)


    vector<string> ab_original(hb * 2 + ha);
    for (int i = 0; i < hb * 2 + ha; ++i) {
        for (int j = 0; j < wb * 2 + wa; ++j) {
            ab_original[i] += '.';
        }
    }

    for (int i = 0; i < ha; ++i) {
        for (int j = 0; j < wa; ++j) {
            ab_original[i + hb][j + wb] = a[i][j];
        }
    }

//    printmap(ab_original);

    bool ans = false;
    for (int i = 0; i < hb * 2 + ha - hb; ++i) {
        for (int j = 0; j < wb * 2 + wa - wb; ++j) {

            vector<string> ab(hb * 2 + ha);
            for (int k = 0; k < hb * 2 + ha; ++k) {
                ab[k] = ab_original[k];
            }

            // i,j はhb の起点
            for (int k = 0; k < hb; ++k) {
                for (int l = 0; l < wb; ++l) {
                    if (b[k][l] == '#') {
                        ab[i + k][j + l] = b[k][l];
                    }
                }
            }

//            printmap(ab);
            if (check(ab, x, hx, wx)) {
                ans = true;
                break;
            }
        }
    }
    cout << ((ans == true)?"Yes":"No") << endl;


}
