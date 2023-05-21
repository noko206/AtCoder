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
    int n, m;
    cin >> n >> m;
    vector<int> s(m), c(m);
    REP(i, m){
        cin >> s[i] >> c[i];
    }
    int r = pow(10, n);
    int l = r == 10 ? 0 : r / 10;
    REP(i, l, r){
        string ans = to_string(i);
        bool is_ok = true;
        REP(j, m){
            if(ans.length() < s[j]){
                is_ok = false;
                break;
            }
            if(ans[s[j] - 1] != c[j] + '0'){
                is_ok = false;
                break;
            }
        }
        if(is_ok){
            cout << ans << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}