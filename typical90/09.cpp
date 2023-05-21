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
    vector<int> x(n), y(n);
    REP(i, n){
        cin >> x[i] >> y[i];
    }
    double ans = 0;
    REP(i, n){
        vector<double> t;
        REP(j, n){
            if(i == j) continue;
            int nx = x[j] - x[i];
            int ny = y[j] - y[i];
            t.push_back(atan2(ny, nx) * 180 / M_PI);
        }
        sort(ALL(t));
        REP(j, n - 1){
            double s = 0;
            if(t[j] >= 0) s = t[j] - 180;
            else s = t[j] + 180;
            int pos = lower_bound(ALL(t), s) - t.begin();
            pos %= t.size();
            // printf("%.3f %.3f\n", t[j], *it);
            chmax(ans, min(abs(t[j] - t[pos]), 360 - abs(t[j] - t[pos])));
            //cout << ans << ' ';
            pos = ((pos - 1) + t.size()) % t.size();
            chmax(ans, min(abs(t[j] - t[pos]), 360 - abs(t[j] - t[pos])));
            // cout << ans << endl;
        }
    }
    printf("%.9f\n", ans);
}