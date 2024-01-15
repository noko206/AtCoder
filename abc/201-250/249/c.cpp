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
    vector<vector<int>> cnt(n, vector<int>(26, 0));
    REP(i, n){
        string s;
        cin >> s;
        REP(j, s.length()){
            ++cnt[i][s[j] - 'a'];
        }
    }
    int ans = 0;
    REP(bit, 1 << n){
        vector<int> t;
        REP(i, n){
            if(bit & (1 << i)){
                t.push_back(i);
            }
        }
        vector<int> tot(26, 0);
        for(int i : t){
            REP(j, 26){
                tot[j] += cnt[i][j];
            }
        }
        int num = 0;
        for(int v : tot){
            if(v == k){
                ++num;
            }
        }
        chmax(ans, num);
    }
    cout << ans << endl;
}