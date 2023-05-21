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
const int MOD = 998244353;
const int INF = 2e9;
const long long LLINF = 2e18;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
ll gcd(ll x, ll y){ return (x % y) ? gcd(y, x % y) : y; }
ll lcm(ll x, ll y){ return x / gcd(x, y) * y; }

using Graph = vector<vector<int>>;
bool seen[200200];

int v_num = 0;
int e_num = 0;

void dfs(const Graph &G, int v){
    seen[v] = true;
    ++v_num;
    e_num += G[v].size();
    for(int next : G[v]){
        if(seen[next]) continue;
        dfs(G, next);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    Graph G(n);
    REP(i, m){
        int x, y;
        cin >> x >> y;
        --x, --y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    ll ans = 1;
    REP(i, n){
        if(seen[i]) continue;
        v_num = 0;
        e_num = 0;
        dfs(G, i);
        if(v_num * 2 == e_num){
            ans *= 2;
            ans %= MOD;
        }
        else{
            ans = 0;
        }
    }
    cout << ans << endl;
}