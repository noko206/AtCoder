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
    int h, w, n;
    cin >> h >> w >> n;
    int sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;
    vector<pair<int, int>> xy(n);
    map<int, int> xmp, ymp;
    REP(i, n){
        cin >> xy[i].first >> xy[i].second;
        xmp[xy[i].first] = -1;
        ymp[xy[i].second] = -1;
    }
    int cnt = 0;
    for(pair<int, bool> x : xmp){
        xmp[x.first] = cnt;
        ++cnt;
    }
    cnt = 0;
    for(pair<int, bool> y : ymp){
        ymp[y.first] = cnt;
        ++cnt;
    }
    REP(i, n){
        xy[i].first = xmp[xy[i].first];
        xy[i].second = ymp[xy[i].second];
        cout << xy[i].first << ' ' << xy[i].second << endl;
    }

}