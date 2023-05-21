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
    vector<int> a(n), tot(n, 0);
    REP(i, n){
        cin >> a[i];
        if(a[i] == 0){
            a[i] = -1;
        }
        if(i == 0){
            tot[i] = a[i];
        }
        else {
            tot[i] = a[i] + tot[i - 1];
        }
    }
    // if(n == 1){
    //     cout << 2 << endl;
    //     return 0;
    // }
    vector<int> ma(n), mi(n);
    REP(i, n){
        if(i == 0){
            ma[i] = max(tot[i], 0);
            mi[i] = min(tot[i], 0);
        }
        else{
            ma[i] = max(ma[i - 1], tot[i]);
            mi[i] = min(mi[i - 1], tot[i]);
        }
    }
    int _ma = 0, _mi = INF;
    REP(i, n){
        chmax(_ma, tot[i] - mi[i]);
        chmin(_mi, tot[i] - ma[i]);
    }
    cout << _ma - _mi + 1 << endl;
    // cout << _ma << ' ' << _mi << endl;
}