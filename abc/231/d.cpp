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
vector<bool> seen;
bool is_loop = false;
int n;

void dfs(const Graph &G, int v, int p = -1, int cnt = 0){
    seen[v] = true;
    if(is_loop || cnt > n){
        is_loop = true;
        return;
    }
    for(int u : G[v]){
        if(u == p) continue;
        dfs(G, u, v, cnt + 1);
    }
}

int main(){
    int m;
    cin >> n >> m;
    Graph G(n);
    REP(i, m){
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    bool is_ok = true;
    REP(i, n){
        if(G[i].size() > 2){
            is_ok = false;
        }
    }
    if(!is_ok){
        cout << "No" << endl;
        return 0;
    }
    seen.resize(n, false);
    REP(i, n){
        if(!seen[i]){
            dfs(G, i);
        }
        if(is_loop){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}