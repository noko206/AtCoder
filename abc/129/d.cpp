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
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    REP(i, h){
        cin >> s[i];
    }
    vector<vector<int>> cnt(h, vector<int> (w, 0));
    REP(i, h){
        int tot = 0;
        REP(j, w){
            if(s[i][j] == '.') ++tot;
            else tot = 0;
            cnt[i][j] += tot;
        }
    }
    REP(i, h){
        int tot = 0;
        REP(j, w){
            if(s[i][w - j - 1] == '.') ++tot;
            else tot = 0;
            cnt[i][w - j - 1] += tot;
        }
    }
    REP(j, w){
        int tot = 0;
        REP(i, h){
            if(s[i][j] == '.') ++tot;
            else tot = 0;
            cnt[i][j] += tot;
        }
    }
    REP(j, w){
        int tot = 0;
        REP(i, h){
            if(s[h - i - 1][j] == '.') ++tot;
            else tot = 0;
            cnt[h - i - 1][j] += tot;
        }
    }
    int ans = 0;
    REP(i, h){
        REP(j, w){
            if(s[i][j] == '.') cnt[i][j] -= 3;
            chmax(ans, cnt[i][j]);
        }
    }
    cout << ans << endl;
}