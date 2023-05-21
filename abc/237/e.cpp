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
using P = pair<ll, int>;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> h(n);
    REP(i, n){
        cin >> h[i];
    }
    Graph G(n);
    REP(i, m){
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.emplace(0LL, 0);
    vector<ll> dist(n, LLINF);
    dist[0] = 0;
    while(!pq.empty()){
        P p = pq.top();
        pq.pop();
        ll d = p.first;
        int v = p.second;
        if(dist[v] < d) continue;
        for(int u : G[v]){
            if(chmin(dist[u], dist[v] + abs(h[v] - h[u]))){
                pq.emplace(dist[u], u);
            }
        }
    }
    ll ans = -LLINF;
    REP(i, n){
        chmax(ans, (- dist[i] - 3 * h[i] + 3 * h[0]) / 2);
    }
    cout << ans << endl;
}