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
    vector<int> a(1<<n);
    queue<int> q;
    REP(i, 1<<n){
        cin >> a[i];
        q.push(i);
    }
    int ans = 0;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        if(q.empty()){
            break;
        }
        int u = q.front();
        q.pop();
        if(a[v] > a[u]){
            q.push(v);
            ans = u + 1;
        }
        else{
            q.push(u);
            ans = v + 1;
        }
    }
    cout << ans << endl;
}