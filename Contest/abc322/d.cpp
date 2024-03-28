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


void minocopy(vector<vector<char>> src, vector<vector<char>>& dest) {

    for (int j = 0; j < 4; ++j) {
        for (int k = 0; k < 4; ++k) {
            dest[j][k] = src[j][k];
        }
    }
}

bool slideMino(vector<vector<char>>& mino, ll x, ll y) {
    // x,y 方向に可能な限りスライド
    bool CanMoveComplete = true;

    // y 方向にスライド
    if (y < 0) {
        for (int i = 0; i < abs(y); ++i) {
            ll isBlank = true;
            for (int j = 0; j < 4; ++j) {
                if (mino[0][j] == '#') {
                    isBlank = false;
                    CanMoveComplete = false;
                    break;
                }
            }
            if (isBlank) {
                for (int k = 0; k < 3; ++k) {
                    for (int j = 0; j < 4; ++j) {
                        mino[k][j] = mino[k + 1][j];
                    }
                }
                for (int j = 0; j < 4; ++j) {
                    mino[3][j] = '.';
                }
            }
        }
    }
    //y + (した)
    if (y > 0) {
        for (int i = 0; i < abs(y); ++i) {
            ll isBlank = true;
            for (int j = 0; j < 4; ++j) {
                if (mino[3][j] == '#') {
                    isBlank = false;
                    CanMoveComplete = false;
                    break;
                }
            }
            if (isBlank) {
                for (int k = 2; k >= 0; --k) {
                    for (int j = 0; j < 4; ++j) {
                        mino[k + 1][j] = mino[k][j];
                    }
                }
                for (int j = 0; j < 4; ++j) {
                    mino[0][j] = '.';
                }
            }
        }
    }


    // x -  方向にスライド
    if (x < 0) {
        for (int i = 0; i < abs(x); ++i) {
            ll isBlank = true;
            for (int j = 0; j < 4; ++j) {
                if (mino[j][0] == '#') {
                    isBlank = false;
                    CanMoveComplete = false;
                    break;
                }
            }
            if (isBlank) {
                for (int k = 0; k < 4; ++k) {
                    for (int j = 0; j < 3; ++j) {
                        mino[k][j] = mino[k][j + 1];
                    }
                }
                for (int k = 0; k < 4; ++k) {
                    mino[k][3] = '.';
                }
            }
        }
    }
    //x + 右方向
    if (x > 0) {
        for (int i = 0; i < abs(x); ++i) {
            ll isBlank = true;
            for (int j = 0; j < 4; ++j) {
                if (mino[j][3] == '#') {
                    isBlank = false;
                    CanMoveComplete = false;
                    break;
                }
            }
            if (isBlank) {
                for (int k = 0; k < 4; ++k) {
                    for (int j = 2; j >= 0; --j) {
                        mino[k][j + 1] = mino[k][j];
                    }
                }
                for (int k = 0; k < 4; ++k) {
                    mino[k][0] = '.';
                }
            }
        }
    }

    return CanMoveComplete;
}

void showMino(vector<vector<char>>& mino) {
    cerr << "==show==" <<endl;
    for (int j = 0; j < 4; ++j) {
        for (int k = 0; k < 4; ++k) {
            cerr << mino[j][k];
        }
        cerr << endl;
    }
}

void rotateMino(vector<vector<char>>& mino) {
    vector<vector<char>> tmp_mino(4,vector<char>(4,'a'));
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            tmp_mino[3 - j][i] = mino[i][j];
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            mino[i][j] = tmp_mino[i][j];
        }
    }
}

int main()
{
    ll h = 4;
    ll w = 4;

    ll num = 3;

    vector<vector<vector<char>>> poriominos(num,vector<vector<char>>(h,vector<char>(w,'a')));

    for (int i = 0; i < num; ++i) {
        for (int j = 0; j < h; ++j) {
            for (int k = 0; k < w; ++k) {
                cin >> poriominos[i][j][k];
            }
        }
    }



    bool  ans = false;


    // 順当似とこうと思うと、4回転して 16 箇所配置 4 * 16 が3ピースで64^3 でいけそう？ 2^8^3
    // 2^24 10^6 * 16 ギリアウトかも。でも減らせばセーフか

    //回転操作と並行移動がだるいな...
    vector<vector<vector<vector<char>>>> mino_candidates(3,vector<vector<vector<char>>>());

    for (int q = 0; q < 3; ++q) {

        for (int p = 0; p < 4; ++p) {
            rotateMino(poriominos[q]);
//        showMino(poriominos[q]);
            vector<vector<char>> tmp(4,vector<char>(4,','));
            minocopy(poriominos[q],tmp);
            slideMino(tmp,-4,-4);
//            showMino(tmp);

            vector<vector<char>> tmp2(4,vector<char>(4,','));

            for (int i = 0; i <= 3; ++i) {
                for (int j = 0; j <= 3; ++j) {
                    minocopy(tmp,tmp2);
                    bool isCanMove = slideMino(tmp2,i,j);

                    if (isCanMove) {
//                        vector<vector<char>> _tmp(4,vector<char>(4,','));
//                        minocopy(tmp2,_tmp);
////                        showMino(tmp2);
//                        mino_candidates[q].push_back(tmp3);
//                        showMino(tmp2);
                        mino_candidates[q].push_back(tmp2);
                    }
                }
            }

        }
    }


    for (auto m1:mino_candidates[0]) {
        for (auto m2:mino_candidates[1]) {
            for (auto m3:mino_candidates[2]) {

//                vector<vector<char>> _tmp(4,vector<char>(4,'.'));
                bool isAns = true;
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        ll count = 0;
                        if (m1[i][j] == '#') {
                            count++;
                        }
                        if (m2[i][j] == '#') {
                            count++;
                        }
                        if (m3[i][j] == '#') {
                            count++;
                        }
                        if (count != 1) {
                            isAns = false;
                        }
                    }
                }
//                showMino(_tmp);
                if (isAns) {
                    ans = true;
                }
            }
        }
    }




    cout << ((ans)?"Yes":"No") << endl;
    return 0;
}
