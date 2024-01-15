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
    int n;
    cin >> n;
    Graph G(n);
    REP(i, n - 1){
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<pair<int, int>> ans(n, make_pair(-1, -1));
    int leaf = 1;
    auto dfs = [&](auto self, int v, int p) -> int {
        ans[v].first = leaf;
        int cnt = 0;
        for(int u : G[v]){
            if(u == p) continue;
            cnt += self(self, u, v);
        }
        if(G[v].size() == 1 && v != 0){
            ++cnt;
        }
        ans[v].second = ans[v].first + cnt - 1;
        if(G[v].size() == 1 && v != 0){
            // cout << v + 1 << endl;
            ++leaf;
        }
        return cnt;
    };
    dfs(dfs, 0, -1);
    REP(i, n){
        cout << ans[i].first << ' ' << ans[i].second << endl;
    }
}