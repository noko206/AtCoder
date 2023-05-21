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
    Graph G(n);
    REP(i, m){
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].push_back(v);
    }
    vector<bool> loop(n, false);
    vector<bool> seen(n, false);
    stack<int> st;
    auto dfs = [&](auto dfs, int v) -> bool{
        if(seen[v] || loop[v]){
            loop[v] = true;
            seen[v] = false;
            while(!st.empty()){
                int u = st.top();
                st.pop();
                loop[u] = true;
                seen[u] = false;
            }
            return true;
        }
        seen[v] = true;
        st.push(v);
        for(int u : G[v]){
            dfs(dfs, u);
            if(st.empty()) return true;
        }
        seen[v] = false;
        st.pop();
        return false;
    };
    vector<int> num(n);
    REP(i, n){
        num[i] = i;
    }
    shuffle(ALL(num), num);
    REP(j, n){
        int i = num[j];
        if(loop[i]) continue;
        dfs(dfs, i);
    }
    int ans = 0;
    REP(i, n){
        if(loop[i]) ++ans;
    }
    cout << ans << endl;
}