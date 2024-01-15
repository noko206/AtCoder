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

int cnt[10][10];

int main(){
    int n;
    cin >> n;
    REP(i, 1, n + 1){
        int tail = i % 10;
        int head = -1, tmp = i;
        while(tmp > 0){
            head = tmp % 10;
            tmp /= 10;
        }
        ++cnt[head][tail];
    }
    int ans = 0;
    REP(i, 10){
        REP(j, 10){
            ans += cnt[i][j] * cnt[j][i];
        }
    }
    cout << ans << endl;
}