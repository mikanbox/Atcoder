#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
#define ll int64_t


template <typename T>
istream &operator>>(istream &is, vector<T> &vec)
{
    for (T &x : vec)
        is >> x; // for(int i=0; i<vec.size(); i++) is >> x[i]; とかでもいい
    return is;
}


int main() {
    ll n,d;
    cin >> n >> d;

    vector<pair<ll,ll>> lr(n, make_pair(0,0));

    for (ll i = 0; i < n; ++i) {
        ll l,r;
        cin >> l >> r;
        lr[i] = make_pair(l,r);
//        lr.emplace_back(l,r);
    }

    // D で被覆するのと、かぶってるところは複数回攻撃が必要なのがネック
    // 区間の話だけど、最小回数求めるので全探索か貪欲か二分探索が必要
    // 二分探索は無理なので貪欲か全探索(DP)が必要
    // どっちも無理そうに見えるが,,,
    // 単調性も見えないし、DPぽい感じもしないよなあ

    // 順序は関係ないから、貪欲でも行けたりする？
        // 左から見ていって、一番左の要素の一番右は絶対パンチ必要
        // これを繰り返すとか？

        // 被覆するケースは基本 LR が異なる。Rが同じ場合は複数回 or 手前からの攻撃か必要そうだが、、、、今回は大丈夫なのかな。
        // R が同じ壁があるとだるそうだが。..?　→これは全く同じ壁がない限り、先頭から見ていけばいいのか。
        // L,R が同じだと複数回必要だけど、これも最初に重複検出して index に値入れておけば問題ないか。


    sort(lr.begin(), lr.end(),[](pair<ll,ll> left, pair<ll,ll>right){
        return left.second < right.second;
//        if (left.first == right.first) {
//            // 比較式にイコール入れると無限にソートしちゃう
//            return (left.second < right.second);
//        } else {
//            return (left.first < right.first);
//        }
    });


    ll ans = 0;
    ll pindex = -10000000000000;
    for (ll i = 0; i < n; ++i) {
        if (lr[i].first <= pindex + d - 1) {
            continue;
        }

        ans++;
        ll rmin = lr[i].second;
        pindex = lr[i].second;

        for (ll j = i; j < n; ++j) {
            // 範囲 d を超えたら break
            if (lr[j].first >= lr[i].first + d )
                break;

            // 一番右が近い要素を抜き出し→あー壁やからちゃうのか
            if (rmin > lr[j].second && lr[j].second < i + d) {
                rmin = lr[j].second;
                pindex = j;
            }
        }
    }

    cout << ans<< endl;

}