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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> t(n);
    REP(i, n){
        t[i].resize(n);
        REP(j, n){
            cin >> t[i][j];
        }
    }
    vector<int> city(n - 1);
    REP(i, n - 1){
        city[i] = i + 1;
    }
    int ans = 0;
    do{
        int cost = t[0][city[0]];
        REP(i, 1, n - 1){
            cost += t[city[i - 1]][city[i]];
        }
        cost += t[city[n - 2]][0];
        if(cost == k){
            ++ans;
        }
    } while (next_permutation(ALL(city)));
    cout << ans << endl;
}