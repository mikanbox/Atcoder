#include <bits/stdc++.h>


using namespace std;
#define ll long long

const ll mod = 1000000007;
const ll LINF = 1e13;
const ll LLINF = 1e18;
const ll ALPHABET = 26;


int main()
{
    ll w,h,n;
    cin >> w >> h >> n;
    vector<pair<ll,ll>> pq = vector<pair<ll,ll>>(n);

    for (int i = 0; i < n; ++i) {
        ll p,q;
        cin >> p >>q;
        pq[i] = make_pair(p,q);
    }


    ll a,b;
    cin >> a;
    vector<ll> _a(a);

    for (ll i = 0; i < a; ++i) {
        cin >> _a[i];
    }

    cin >> b;
    vector<ll> _b(b);
    for (ll i = 0; i < b; ++i) {
        cin >> _b[i];
    }

    // Input Test
//    for (auto v: pq) {
//        cerr << v.first << "," << v.second << endl;
//    }
//    for (auto v: _a) {
//        cerr << v << "," ;
//    }cerr << endl;
//    for (auto v: _b) {
//        cerr << v << "," ;
//    }cerr << endl;


    // ケーキ w,h を a と b にそって全部切って。 pq の値を計算
    // a < 10^5
    // b < 10^5
    // a+b < 10^8
    // a*b > 10^8
    // n < 10^5
    // n*a とか n*bの探索は無理
    // ケーキ (A+1)(B+1) > 10^8 なので、ケーキをいちいち列挙するのは不可

    // 単調性としては、ケーキ切った後は、必ずケーキ切る前よりいちごの数は減る
    // 切っていくごとに、探索の枝刈りできそう？→できない気がする
    // min と max は同時に出せない場合、２回繰り返せばOK
    // (A+1)(B+1)が出せれば、二分探索とかで求めることはできる。列挙は無理
    // ケーキ n 回きった時の max -> ケーキn+1回きった時のmax ：成り立たない

    // 縦だけ、横だけ切って計算して、最後にあわせるとか？


    // いちご (10^5)に注目すべき？
    // いちごベースで 同じ場所に所属するものを集める (O1 or log n )でできれば良さそう

    // これで良さそう

    // あるいちごが、 a 本目と a+1 本目の切断の間　かつ b本目と b+1 本目の切断の間
    // いちごの x を使用し、a 本目と a+1 本目の切断の間 → 二分探索で logn
    // いちごの y を使用し、b本目と b+1 本目の切断の間 z →二分探索で logn
    // n * logn < 10^7 : ギリセーフ

    // hash_set とかで key(a,b) にいちごの数をどんどん足していく O(1)
    // hash_set 多分列挙できるから、最後に列挙して min / max  もとめる

    unordered_map<string,ll> ichigo_num_hashmap;
    //昇順ソート
    sort(_a.begin(), _a.end());
    sort(_b.begin(), _b.end());

    // upper_bound keyより大きい要素の内の一番左側のイテレータを返す

    for (auto ichigo:pq) {
        ll x = ichigo.first;
        ll y = ichigo.second;

        // lower_boundは、探索したいkey以上のイテレータを返す
        // -1 -> 0
        // INFINITY -> hoge.end() これは　0 からみて、距離が n ?
        auto a_itr = lower_bound(_a.begin(),_a.end(),x);
        ll a_index = distance(_a.begin(), a_itr) ; // 計算量めっちゃ怪しい.上限下限のチェック怪しい
        auto b_itr = lower_bound(_b.begin(),_b.end(),y);
        ll b_index = distance(_b.begin(), b_itr) ; // 計算量めっちゃ怪しい.上限下限のチェック怪しい


        string key = to_string(a_index) + "," + to_string(b_index);
        ichigo_num_hashmap[key] = ichigo_num_hashmap[key] + 1;
    }





    ll _min = LLINF;
    ll _max = -1;

    for (auto v:ichigo_num_hashmap) {
        if (v.second > _max) {
            _max = v.second;
        }
        if (v.second < _min) {
            _min = v.second;
        }
    }


    // 0 どうする問題
    // １以上いちごがあるケーキの数が、切り分けた数より小さい場合、かならず0ケーキがある
    if (ichigo_num_hashmap.size() < (a+1) * (b+1) ) {
        _min = 0;
    }

    cout << _min << " " << _max << endl;

    return 0;
}
