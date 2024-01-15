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

struct ROOM{
    int pre;
    int now;
};

int main(){
    int n, m;
    cin >> n >> m;
    Graph G(n);
    REP(i, m){
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    queue<ROOM> q;
    q.push({0, 0});
    vector<int> ans(n, -1);
    while(!q.empty()){
        ROOM v = q.front();
        q.pop();
        for(int next : G[v.now]){
            if(ans[next] != -1) continue;
            ans[next] = v.now;
            q.push({v.now, next});
        }
    }
    bool is_ok = true;
    REP(i, n){
        if(ans[i] == -1){
            is_ok = false;
        }
    }
    if(is_ok){
        cout << "Yes" << endl;
        REP(i, 1, n){
            cout << ans[i] + 1 << endl;
        }
    }
    else{
        cout << "No" << endl;
    }
}