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

int dp[1000005];
int a;

void rec(int n, int cnt){
    if(!chmin(dp[n], cnt)){
        return;
    }
    if(n / 10 != 0){
        string tmp, m;
        tmp = to_string(n);
        m = "";
        if(tmp[1] != '0'){
            REP(i, 1, tmp.length()){
                m += tmp[i];
            }
            m += tmp[0];
            int p = stoi(m);
            rec(p, cnt + 1);
        }
    }
    if(n % a == 0){
        rec(n / a, cnt + 1);
    }
}

int main(){
    int n;
    cin >> a >> n;
    REP(i, 1000005){
        dp[i] = INF;
    }
    rec(n, 0);
    if(dp[1] == INF){
        cout << -1 << endl;
    }
    else{
        cout << dp[1] << endl;
    }
}