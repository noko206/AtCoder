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
    int h, w, m;
    cin >> h >> w >> m;
    map<int, int> mph, mpw;
    int hmaxval = 0, wmaxval = 0;
    map<pair<int, int>, bool> d;
    REP(i, m){
        int y, x;
        cin >> y >> x;
        chmax(hmaxval, ++mph[y]);
        chmax(wmaxval, ++mpw[x]);
        d[make_pair(y, x)] = true;
    }
    vector<int> hmax, wmax;
    for(pair<int, int> y : mph){
        if(hmaxval == y.second){
            hmax.push_back(y.first);
        }
    }
    for(pair<int, int> x : mpw){
        if(wmaxval == x.second){
            wmax.push_back(x.first);
        }
    }
    int ans = hmaxval + wmaxval - 1;
    // cout << hmaxval << ' ' << wmaxval << endl;
    for(int y : hmax){
        for(int x : wmax){
            if(d.find(make_pair(y, x)) == d.end()){
                // cout << y << ':' << x << endl;
                ++ans;
                cout << ans << endl;
                return 0;
            }
        }
    }
    cout << ans << endl;
}