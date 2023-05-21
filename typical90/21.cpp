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

using Graph = vector<vector<int>>;

bool seen[100100];
vector<int> path;
ll cnt = 0;

void dfs(const Graph &G, int v){
    seen[v] = true;
    for(int next : G[v]){
        if(seen[next]){
            continue;
        }
        dfs(G, next);
    }
    path.push_back(v);
}

void rdfs(const Graph &G, int v){
    seen[v] = true;
    ++cnt;
    for(int next : G[v]){
        if(seen[next]){
            continue;
        }
        rdfs(G, next);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    Graph G(n);
    REP(i, m){
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].push_back(b);
    }
    REP(i, n){
        if(seen[i]){
            continue;
        }
        dfs(G, i);
    }
    reverse(ALL(path));
    REP(i, n){
        seen[i] = false;
    }
    ll ans = 0;
    Graph H(n);
    REP(a, n){
        for(int b : G[a]){
            H[b].push_back(a);
        }
    }
    for(int i : path){
        cnt = 0;
        if(seen[i]){
            continue;
        }
        rdfs(H, i);
        ans += cnt * (cnt - 1) / 2;
    }
    cout << ans << endl;
}