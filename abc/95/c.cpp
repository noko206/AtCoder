#include <bits/stdc++.h>
using namespace std;

#define _overload3(_1,_2,_3,name,...) name
#define _REP(i,n) REPI(i,0,n)
#define REPI(i,a,b) for(int i=int(a);i<int(b);++i)
#define REP(...) _overload3(__VA_ARGS__,REPI,_REP,)(__VA_ARGS__)
#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
#define MEMSET(v, h) memset((v), h, sizeof(v))
typedef long long ll;
typedef long double ld;
const int MOD = 1e9+7;
const int INF = 2e9;
const long long LLINF = 1LL<<60;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll ans = LLINF;
    REP(i, 0, max(x + 1, y + 1)){
        ll a_cnt, b_cnt, ab_cnt;
        ll price;
        a_cnt = i;
        if(a_cnt > x){
            ab_cnt = 0;
        }
        else{
            ab_cnt = 2 * (x - i);
        }
        b_cnt = 0;
        if(ab_cnt / 2 >= y){
            b_cnt = 0;
        }
        else{
            if(b < 2 * c){
                b_cnt = y - ab_cnt / 2;
            }
            else{
                ab_cnt = 2 * y;
            }
        }
        price = a_cnt * a + b_cnt * b + ab_cnt * c;
        // if(i == 100000) cout << a_cnt << ' ' << b_cnt << ' ' << ab_cnt << ' ' << price << endl;
        chmin(ans, price);
    }
    cout << ans << endl;
}