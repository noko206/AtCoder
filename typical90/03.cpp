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

int main(){
    int n;
    cin >> n;
    Graph G(n);
    REP(i, n - 1){
        int a, b;
        cin >> a >> b;
        G[a - 1].push_back(b - 1);
        G[b - 1].push_back(a - 1);
    }
    queue<int> q;
    q.push(0);
    int last = -1;
    vector<bool> seen(n, false);
    while(q.size()){
        int v = q.front();
        q.pop();
        last = v;
        for(int next : G[v]){
            if(seen[next]){
                continue;
            }
            seen[next] = true;
            q.push(next);
        }
    }
    q.push(last);
    vector<int> cnt(n, 0);
    while(q.size()){
        int v = q.front();
        q.pop();
        last = v;
        for(int next : G[v]){
            if(cnt[next] > 0 || next == v){
                continue;
            }
            cnt[next] = cnt[v] + 1;
            q.push(next);
        }
    }
    cout << cnt[last] + 1 << endl;
}