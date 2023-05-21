#include <bits/stdc++.h>
using namespace std;

#define _overload3(_1,_2,_3,name,...) name
#define _REP(i,n) REPI(i,0,n)
#define REPI(i,a,b) for(int i=int(a);i<int(b);++i)
#define REP(...) _overload3(__VA_ARGS__,REPI,_REP,)(__VA_ARGS__)
#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef long double ld;
const int MOD = 1e9+7;
const int INF = 2e9;
const long long LLINF = 2e18;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
ll gcd(ll x, ll y){ return (x % y) ? gcd(y, x % y) : y; }
ll lcm(ll x, ll y){ return x / gcd(x, y) * y; }

struct BIT {
    int n;
    vector<int> d;
    void init(int m){
        n = m;
        d.resize(n + 1, 0);
    }
    void add(int x, int y) {
        for (int i = x; i <= n; i += i & -i) {
            d[i] += y;
        }
    }
    void sub(int x, int y){
        for(int i = x; i <= n; i += i & -i){
            d[i] -= y;
        }
    }
    int sum(int x) {
        int y = 0;
        for (int i = x; i > 0; i -= i & -i) {
            y += d[i];
        }
        return y;
    }
    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    void show(){
        REP(i, d.size()){
            cout << d[i] << ' ';
        }
    }
};

int main(){
    int n, q;
    string s;
    cin >> n >> s >> q;
    vector<BIT> bit(26);
    REP(i, 26){
        bit[i].init(1 << 19);
    }
    REP(i, s.length()){
        bit[s[i] - 'a'].add(i + 1, 1);
    }
    // REP(i, 26){
    //     bit[i].show();
    //     cout << endl;
    // }
    REP(i, q){
        int t;
        cin >> t;
        if(t == 1){
            int iq;
            char cq;
            cin >> iq >> cq;
            bit[cq - 'a'].add(iq, 1);
            bit[s[iq - 1] - 'a'].sub(iq, 1);
            s[iq - 1] = cq;
        }
        else{
            int lq, rq;
            cin >> lq >> rq;
            int cnt = 0;
            REP(j, 26){
                cnt += bit[j].sum(lq, rq) ? 1 : 0;
            }
            cout << cnt << endl;
        }
    }
}