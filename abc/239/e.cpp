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
    int n, q;
    cin >> n >> q;
    vector<int> x(n);
    REP(i, n){
        cin >> x[i];
    }
    Graph G(n);
    REP(i, n - 1){
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<vector<pair<int, int>>> query(n); // v->(k, i);
    REP(i, q){
        int v, k;
        cin >> v >> k;
        --v, --k;
        query[v].push_back({k, i});
    }
    vector<multiset<int>> s(n);
    vector<int> ans(q, -1);
    auto dfs = [&](auto self, int v, int p) -> void {
        s[v].insert(x[v]);
        for(int u : G[v]){
            if(u == p) continue;
            self(self, u, v);
            auto it = s[u].rbegin();
            while(it != s[u].rend()){
                if((int)s[v].size() >= 20 && *s[v].rend() >= *it){
                    break;
                }
                s[v].insert(*it);
                if((int)s[v].size() > 20){
                    s[v].erase(s[v].begin());
                }
                ++it;
            }
        }
        for(pair<int, int> p : query[v]){
            int k = p.first;
            int i = p.second;
            auto it = s[v].rbegin();
            advance(it, k);
            ans[i] = *it;
        }
    };
    dfs(dfs, 0, -1);
    REP(i, q){
        cout << ans[i] << endl;
    }
}