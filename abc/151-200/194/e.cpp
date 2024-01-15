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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    multiset<int> ms;
    set<int> s;
    REP(i, n + 1){
        s.insert(i);
    }
    REP(i, n){
        cin >> a[i];
        if(i < m){
            ms.insert(a[i]);
            s.erase(a[i]);
        }
    }
    int ans = *s.begin();
    // cout << *s.begin() << endl;
    REP(i, n - m){
        ms.erase(ms.find(a[i]));
        if(ms.find(a[i]) == ms.end()){
            s.insert(a[i]);
        }
        ms.insert(a[i + m]);
        s.erase(a[i + m]);
        chmin(ans, *s.begin());
        // cout << *s.begin() << endl;
    }
    cout << ans << endl;
}