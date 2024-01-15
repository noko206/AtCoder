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
    cin >> n;
    vector<int> s(n), t(n);
    REP(i, n){
        cin >> s[i];
    }
    int mi_i = 0;
    REP(i, n){
        cin >> t[i];
        if(t[mi_i] > t[i]){
            mi_i = i;
        }
    }
    vector<int> ans(n, 0);
    ans[mi_i] = t[mi_i];
    REP(i, n){
        int j = (i + mi_i) % n;
        ans[(j + 1) % n] = min(t[(j + 1) % n], ans[j] + s[j]);
    }
    REP(i, n){
        cout << ans[i] << endl;
    }
    return 0;
}