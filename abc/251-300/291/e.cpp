#include <bits/stdc++.h>
using namespace std;

#define _overload3(_1,_2,_3,name,...) name
#define _REP(i,n) REPI(i,0,n)
#define REPI(i,a,b) for(int i=int(a);i<int(b);++i)
#define REP(...) _overload3(__VA_ARGS__,REPI,_REP,)(__VA_ARGS__)
#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
typedef long long ll;
const int INF32 = 1001001001;
const long long INF64 = 1001001001001001001;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

struct Edge {
    int to;
};
using Graph = vector<vector<Edge>>;

vector<int> topo_sort(const Graph &G) {  // bfs
    vector<int> ans;
    int n = (int)G.size();
    vector<int> ind(n);            // ind[i]: 頂点iに入る辺の数(次数)
    for (int i = 0; i < n; i++) {  // 次数を数えておく
        for (auto e : G[i]) {
            ind[e.to]++;
        }
    }
    queue<int> que;
    for (int i = 0; i < n; i++) {  // 次数が0の点をキューに入れる
        if (ind[i] == 0) {
            que.push(i);
        }
    }
    while (!que.empty()) {  // 幅優先探索
        int now = que.front();
        ans.push_back(now);
        que.pop();
        for (auto e : G[now]) {
            ind[e.to]--;
            if (ind[e.to] == 0) {
                que.push(e.to);
            }
        }
    }
    return ans;
}

int main(){
	int n, m;
	cin >> n >> m;
	Graph to(n), from(n);
	REP(i, m){
		int x, y;
		cin >> x >> y;
		--x; --y;
		to[x].push_back({y});
		from[y].push_back({x});
	}
	bool is_ok = false;
	vector<int> topo = topo_sort(to);
	vector<int> dist(n, -1);
	if((int)topo.size() < n){
		cout << "No" << endl;
		return 0;
	}
	dist[topo[0]] = 1;
	REP(i, n){
		int v = topo[i];
		for(auto u: from[v]){
			chmax(dist[v], dist[u.to] + 1);
		}
	}
	REP(i, n) {
		if(dist[i] == n){
			is_ok = true;
		}
	}
	if(!is_ok){
		cout << "No" << endl;
		return 0;
	}
	vector<int> ans(n);
	REP(i, n){
		ans[topo[i]] = i + 1;
	}
	cout << "Yes" << endl;
	REP(i, n){
		cout << ans[i] << ' ';
	}
	cout << endl;
}