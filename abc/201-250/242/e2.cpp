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
    int t;
    cin >> t;
    vector<ll> ans(t);
    REP(i, t){
        int n;
        string s;
        cin >> n >> s;
        ll tot = 1;
        REP(j, (n - 1) / 2){
            tot *= s[j] - 'A' + 1;
            tot %= MOD;
        }
        tot *= max(1, (int)(s[(n - 1) / 2] - 'A'));
        tot %= MOD;
        string check = "";
        REP(j, n){
            if(j <= (n - 1) / 2) check += (char)(s[j]);
            else check += (char)(s[n - (j + 1)]);
        }
        if(s == check){
            ++tot;
            tot %= MOD;
        }
        ans[i] = tot;
    }
    REP(i, t){
        cout << ans[i] << endl;
    }
}