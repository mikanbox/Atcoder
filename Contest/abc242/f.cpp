#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;
#define ll int64_t

const ll LLINF = 1e18;
const ll ALPHABET = 26;
const ll MOD = 998244353;

template <typename T>
istream &operator>>(istream &is, vector<T> &vec)
{
    for (T &x : vec)
        is >> x; //for(int i=0; i<vec.size(); i++) is >> x[i]; とかでもいい
    return is;
}


void comb(vector<vector <ll> > &v){
  for(int i = 0;i < v.size(); i++){
    v[i][0] = 1;
    v[i][i] = 1;
  }
  for(int k = 1; k < v.size(); k++){
    for(int j = 1; j < k; j++){
      v[k][j] = (v[k-1][j-1] + v[k-1][j]) % MOD;
    }
  }
}


int main()
{
    ll n, m;
    ll b, w;
    cin >> n >> m >> b >> w;
    

    // 考察
    // b + w 回配置する
    // 配置箇所は (n * m)
    // (n * m) C (b + w) となるが、制約が存在するため、その通りには置けない

    // 制約
    // コマを置くと、そのコマと上下左右には色の違うコマは置けない→各色のコマは対角線上ぽい位置に配置される(例外あり)。行列でも表せそうな感じ　
    // b,wは高々 10^3 * 2.5 なのでn^2 * logn くらいなら可能

    // 愚直解
    // ---左上から b だけ置いていく。計算量は xxx　→うそ
    // ---次に置けそうか判定しながら、左上から w だけ置いていく。計算量は xx : 間に合わない　→うそ
    // w置けるかの判定をo(1)でできれば良さそうか
    // bの置き方を判定 : (n * m)　から b 個のますを置く組み合わせ (n * m) C b　→この値だけであれば、O(n)で出せそうだが...
    // 最大で (10^3) 10^3なので全然計算量足りない。いちいち置いていって評価するのは無理そう

    // 愚直解は計算量が爆発する


    // 残りマス数を具体的に計算せずに出す
    // f(k) = k番目の black を置いた時の残りマス数
    // f(0) = n * m
    // f(1) = n * m - (n + m - 1)

    // f(2)以降は、既存のマスとかぶっているかどうかで パターンある
    // f(2) = n * m - (n + m - 1) - (n + m - 1) + 2 = n * m - (n + m) * 2 + 4  : 重複箇所が四箇所
    // f(2) = n * m - (n + m - 1) - (n - 1)
    // f(2) = n * m - (n + m - 1) - (m - 1)

    // 行列両方を一緒に考えるのは無理そう?

    // 行列分離して考える
    // n row から 1以上、min(b,n)　以下選択
    // m col から 1以上、min(b,m)　以下選択

    // 残った行列数から w の組み合わせは比較的早く計算可能か

    vector<vector<ll>> nCk(n + 1, vector<ll>(n + 1, 0));
    vector<vector<ll>> mCk(m + 1, vector<ll>(m + 1, 0));
    vector<vector<ll>> nmCk(n * m + 1, vector<ll>(n * m + 1, 0));
    comb(nCk);
    comb(mCk);
    comb(nmCk);


    ll ans = 0;
    for (int i = 1; i <= min(b, n); i++) {
        for (int j = 1; j <= min(b, m); j++) {
            // n row から 1以上、min(b, n)　以下選択
            // m col から 1以上、min(b, m)　以下選択
            if (i * j < b) 
                continue;

            ll left_i = n - i;
            ll left_j = m - j;

            // ここまでの組み合わせの数を計算
            //使えるマスは i * j　でここから b 個 選んでくる
            ll comb_b = nmCk[n * m][b];
            // cerr << "comb_b : " << comb_b << endl;

            for (int k = 1; k <= min(w, left_i); k++) {
                for (int l = 1; l <= min(w, left_j); l++) {
                    if (k + l < w)
                        continue;
                    
                    ll comb_w = nmCk[left_i * left_j][w];
                    ans += comb_b * comb_w % MOD;
                    ans %= MOD;
                }
            }
        }
    }        
    

    cout << ans << endl;

}
