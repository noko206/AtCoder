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

int main(){
    ll x;
    cin >> x;
    string s = to_string(x);
    REP(i, (int)(s[0] - '0'), 10){
        REP(j, -9, 10){
            string tmp = "";
            tmp = (char)(i + '0');
            char pre = (char)(i + '0');
            bool is_ok = true;
            REP(k, 1, s.length()){
                char now = pre + j;
                if(now < '0' || now > '9'){
                    is_ok = false;
                    break;
                }
                pre = now;
                tmp += now;
            }
            // cout << tmp << endl;
            if(is_ok){
                ll ans = stoll(tmp);
                if(ans >= x){
                    cout << ans << endl;
                    return 0;
                }
            }
        }
    }
}