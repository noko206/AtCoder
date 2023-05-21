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
    vector<int> x(n), y(n), h(n);
    REP(i, n){
        cin >> x[i] >> y[i] >> h[i];
    }
    REP(cx, 101){
        REP(cy, 101){
            int H = -1;
            REP(i, n){
                if(h[i] == 0) continue;
                H = h[i] + abs(x[i] - cx) + abs(y[i] - cy);
            }
            bool is_ok = true;
            REP(i, n){
                if(max(H - abs(x[i] - cx) - abs(y[i] - cy), 0) != h[i]){
                    is_ok = false;
                }
            }
            if(is_ok){
                cout << cx << ' ' << cy << ' ' << H << endl;
                return 0;
            }
        }
    }
}