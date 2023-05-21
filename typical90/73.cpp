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

ll dp[100100][5];
vector<char> c;

using Graph = vector<vector<int>>;

void dfs(const Graph &G, int v = 0, int parent = -1){
    ll val = 1, val2 = 1;
    for(int child : G[v]){
        if(child == parent){
            continue;
        }
        dfs(G, child, v);
        if(c[v] == 'a'){
            val *= dp[child][0] + dp[child][2];
            val2 *= dp[child][0] + dp[child][1] + 2 * dp[child][2];
        }
        else{
            val *= dp[child][1] + dp[child][2];
            val2 *= dp[child][0] + dp[child][1] + 2 * dp[child][2];
        }
        val %= MOD;
        val2 %= MOD;
    }

    if(c[v] == 'a'){
        dp[v][0] = val;
        dp[v][2] = (val2 - val + MOD) % MOD;
    }
    else{
        dp[v][1] = val;
        dp[v][2] = (val2 - val + MOD) % MOD;
    }
}

int main(){
    int n;
    cin >> n;
    c.resize(n);
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
    cout << dp[0][2] << endl;
}