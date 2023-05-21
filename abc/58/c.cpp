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
    set<int> s;
    REP(i, 10){
        s.insert(i);
    }
    REP(i, k){
        int d;
        cin >> d;
        s.erase(d);
    }
    vector<int> a;
    a.push_back(-1);
    for(int v : s){
        a.push_back(v);
    }
    sort(ALL(a));
    int m = 11 - k;
    REP(i, 1000000){
        int j = i;
        vector<int> b;
        while(j > 0){
            b.push_back(j % m);
            j /= m;
        }
        reverse(ALL(b));
        int ans = 0;
        for(int v : b){
            if(ans == 0){
                if(v == 0){
                    continue;
                }
            }
            else{
                if(v == 0){
                    break;
                }
            }
            ans *= 10;
            ans += a[v];
        }
        if(ans >= n){
            cout << ans << endl;
            return 0;
        }
    }
}