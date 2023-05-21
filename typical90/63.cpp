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
    vector<vector<int>> p(h);
    REP(i, h){
        p[i].resize(w);
        REP(j, w){
            cin >> p[i][j];
        }
    }
    int ans = 0;
    REP(k, 1 << h){
        map<int, int> mp;
        vector<int> check(w, 0);
        REP(j, w){
            bool is_same = true;
            int h_value = -1;
            int cnt = 0;
            REP(i, h){
                if(!(k & 1 << i)) continue;
                ++cnt;
                if(h_value == -1){
                    h_value = p[i][j];
                }
                if(h_value != p[i][j]){
                    is_same = false;
                }
            }
            if(is_same && h_value != -1){
                mp[h_value] += cnt;
            }
        }
        // int test = -1;
        for(pair<int, int> q : mp){
            if(chmax(ans, q.second)){
                // test = q.first;
            }
        }
        // if(test != -1){
        //     cout << test << ' ' << ans << endl;
        // }
    }
    cout << ans << endl;
}