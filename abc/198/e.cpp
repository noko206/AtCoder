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

vector<int> cnt(1e5 + 5, 0);
vector<bool> ans(1e5 + 5, false);
vector<int> c(1e5);

using Graph = vector<vector<int>>;

void dfs(const Graph &G, int v = 0, int p = -1){
    ++cnt[c[v]];
    if(cnt[c[v]] == 1){
        ans[v] = true;
    }
    for(int next : G[v]){
        if(next == p) continue;
        dfs(G, next, v);
    }
    --cnt[c[v]];
}

int main(){
    int n;
    cin >> n;
    REP(i, n){
        cin >> c[i];
    }
    Graph G(n);
    REP(i, n - 1){
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(G);
    REP(i, n){
        if(ans[i]){
            cout << i + 1 << endl;
        }
    }
}