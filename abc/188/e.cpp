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

using Graph = vector<vector<int>>;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<pair<int, int>> b(n);
    REP(i, n){
        cin >> a[i];
        b[i].first = a[i];
        b[i].second = i;
    }
    sort(ALL(b));
    Graph G(n);
    REP(i, m){
        int x, y;
        cin >> x >> y;
        --x, --y;
        G[x].push_back(y);
    }
    queue<int> q;
    vector<int> dp(n, INF);
    vector<int> seen(n, false);
    int ans = -INF;
    REP(k, n){
        int i = b[k].second;
        if(G[i].size() == 0) continue;
        if(seen[i]) continue;
        q.push(i);
        seen[i] = true;
        dp[i] = a[i];
        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(int next : G[v]){
                if(seen[next]) continue;
                seen[next] = true;
                // cout << ans << ' ' << a[next] - dp[v] << endl;
                chmax(ans, a[next] - dp[v]);

                chmin(dp[next], dp[v]);
                chmin(dp[next], a[next]);
                q.push(next);
            }
        }
    }
    cout << ans << endl;
}