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


void showboard(vector<vector<char>> &board) {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board.size(); ++j) {
            cerr << board[i][j];
        }
        cerr << endl;
    }
}


bool rec_search(vector<vector<char>> &board, string r, string c, ll depth) {
    if (depth == r.size()) return true;

    for (int i = 0; i < r.size(); ++i) {
        for (int j = 0; j < r.size(); ++j) {
            if (i == j)continue;
            for (int k = 0; k < r.size(); ++k) {
                if (k == j)continue;
                if (k == i)continue;
                for (int l = 0; l < r.size(); ++l) {
                    board[l][depth] = '.';
                }
                board[i][depth] = 'A';
                for (int l = 0; l < depth; ++l) {
                    if (board[i][l] =='A')continue;
                }
                board[j][depth] = 'B';
                for (int l = 0; l < depth; ++l) {
                    if (board[j][l] =='B')continue;
                }
                board[k][depth] = 'C';
                for (int l = 0; l < depth; ++l) {
                    if (board[k][l] =='C')continue;
                }

                if (  board[min(min(i,j),k)][depth] != c[depth])
                    continue;

                rec_search(board,r,c,depth + 1);
            }
        }
    }



}

int main()
{
    ll n;
    cin >> n;
    string r,c;
    cin >> r;
    cin >> c;


    bool ans = true;

    vector<vector<char>> board(n,vector<char>(n,'.'));
    // 再帰で行けそう？

    // 各行 5 つの候補から ABC埋めるのは 5 * 4 * 3 で、これを5回繰り返す。
    // 実際は後半はおける場所限られるので間に合う？
    rec_search(board, r, c, 0);


    if (ans == false) {
        cout << "No" << endl;
    } else {
        showboard(board);
    }

}
