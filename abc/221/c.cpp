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
    vector<int> a;
    while(n > 0){
        a.push_back(n % 10);
        n /= 10;
    }
    sort(ALL(a));
    ll ans = 0;
    do{
        REP(i, a.size() - 1){
            ll x = 0, y = 0;
            REP(j, a.size()){
                if(j <= i){
                    if(x == 0 && a[j] == 0){
                        break;
                    }
                    x = x * 10 + a[j];
                }
                else{
                    if(y == 0 && a[j] == 0){
                        break;
                    }
                    y = y * 10 + a[j];
                }
            }
            chmax(ans, x * y);
        }
    } while (next_permutation(ALL(a)));
    cout << ans << endl;
}