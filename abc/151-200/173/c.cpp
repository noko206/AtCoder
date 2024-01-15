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
    int h, w, K;
    cin >> h >> w >> K;
    vector<string> c(h);
    REP(i, h){
        cin >> c[i];
    }
    vector<string> tmp_c;
    tmp_c = c;
    int ans = 0;
    REP(i, 1 << h){
        REP(j, 1 << w){
            c = tmp_c;
            REP(k, h){
                if(i & (1 << k)){
                    REP(l, w){
                        c[k][l] = 'r';
                    }
                }
            }
            REP(k, w){
                if(j & (1 << k)){
                    REP(l, h){
                        c[l][k] = 'r';
                    }
                }
            }
            int cnt = 0;
            REP(k, h){
                // cout << c[k] << endl;
                REP(l, w){
                    if(c[k][l] == '#'){
                        ++cnt;
                    }
                }
            }
            // cout << endl;
            if(cnt == K){
                ++ans;
            }
        }
    }
    cout << ans << endl;
}