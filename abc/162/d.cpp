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
    int n;
    string s;
    cin >> n >> s;
    vector<int> r(n, 0), g(n, 0), b(n, 0);
    for(int i = n - 1; i >= 0; --i){
        switch(s[i]){
            case 'R':
                ++r[i];
                break;
            case 'G':
                ++g[i];
                break;
            case 'B':
                ++b[i];
                break;
        }
        if(i != n - 1){
            r[i] += r[i + 1];
            g[i] += g[i + 1];
            b[i] += b[i + 1];
        }
    }
    ll ans = 0;
    REP(i, n - 2){
        REP(j, i + 1, n - 1){
            if(s[i] == s[j]){
                continue;
            }
            if((s[i] == 'R' && s[j] == 'G') || (s[i] == 'G' && s[j] == 'R')){
                ans += b[j + 1];
                int k = 2 * j - i;
                if(k < n && s[k] == 'B'){
                    --ans;
                }
            }
            if((s[i] == 'G' && s[j] == 'B') || (s[i] == 'B' && s[j] == 'G')){
                ans += r[j + 1];
                int k = 2 * j - i;
                if(k < n && s[k] == 'R'){
                    --ans;
                }
            }
            if((s[i] == 'B' && s[j] == 'R') || (s[i] == 'R' && s[j] == 'B')){
                ans += g[j + 1];
                int k = 2 * j - i;
                if(k < n && s[k] == 'G'){
                    --ans;
                }
            }
        }
    }
    // REP(i, n){
    //     cout << b[i] << endl;
    // }
    cout << ans << endl;
}