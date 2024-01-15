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

/* RMQ：[0,n-1] について、区間ごとの最小値を管理する構造体
    update(a,b,x): 区間[a,b) の要素を x に更新。O(log(n))
    query(a,b): [a,b) での最小の要素を取得。O(log(n))
*/
template <typename T>
struct RMQ {
    const T INF = numeric_limits<T>::max();
    int n;
    vector<T> dat, lazy;
    RMQ(int n_) : n(), dat(n_ * 4, INF), lazy(n_ * 4, INF) {
        int x = 1;
        while (n_ > x) x *= 2;
        n = x;
    }

    /* lazy eval */
    void eval(int k) {
        if (lazy[k] == INF) return;  // 更新するものが無ければ終了
        if (k < n - 1) {             // 葉でなければ子に伝搬
            lazy[k * 2 + 1] = lazy[k];
            lazy[k * 2 + 2] = lazy[k];
        }
        // 自身を更新
        dat[k] = lazy[k];
        lazy[k] = INF;
    }

    void update(int a, int b, T x, int k, int l, int r) {
        eval(k);
        if (a <= l && r <= b) {  // 完全に内側の時
            lazy[k] = x;
            eval(k);
        } else if (a < r && l < b) {                     // 一部区間が被る時
            update(a, b, x, k * 2 + 1, l, (l + r) / 2);  // 左の子
            update(a, b, x, k * 2 + 2, (l + r) / 2, r);  // 右の子
            dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }
    void update(int a, int b, T x) { update(a, b, x, 0, 0, n); }

    T query_sub(int a, int b, int k, int l, int r) {
        eval(k);
        if (r <= a || b <= l) {  // 完全に外側の時
            return INF;
        } else if (a <= l && r <= b) {  // 完全に内側の時
            return dat[k];
        } else {  // 一部区間が被る時
            T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return min(vl, vr);
        }
    }
    T query(int a, int b) { return query_sub(a, b, 0, 0, n); }

    /* debug */
    inline T operator[](int a) { return query(a, a + 1); }
    void print() {
        for (int i = 0; i < 2 * n - 1; ++i) {
            cout << (*this)[i];
            if (i != n) cout << ",";
        }
        cout << endl;
    }
};

int main(){
	int n;
	cin >> n;
	vector<int> u(n - 1), v(n - 1), w(n - 1);
	vector<vector<int>> to(n);
	REP(i, n - 1){
		cin >> u[i] >> v[i] >> w[i];
		--u[i]; --v[i];
		to[u[i]].push_back(v[i]);
		to[v[i]].push_back(u[i]);
	}
	vector<bool> visited(n, false);
	vector<int> id(n, -1);
	int cnt = 0;
	auto dfs = [&](auto &dfs, int v = 0, int p = -1) -> void {
		if(!visited[v]){
			id[v] = cnt;
		}
		visited[v] = true;
		++cnt;
		for(int u : to[v]){
			if(u == p) continue;
			dfs(dfs, u, v);
		}
		++cnt;
	};
	dfs(dfs);
	RMQ<ll> seg(cnt);
	REP(i, n - 1){
		seg.update(min(id[u[i]], id[v[i]]), max(id[u[i]], id[v[i]]), w[i]);
	}
	int q;
	cin >> q;
	vector<ll> ans;
	while(q--){
		int t;
		cin >> t;
		if(t == 1){
			int i, W;
			cin >> i >> W;
			--i;
			seg.update(min(id[u[i]], id[v[i]]), max(id[u[i]], id[v[i]]), W);
		}
		if(t == 2){
			int U, V;
			cin >> U >> V;
			--U; --V;
			ans.push_back(
				seg.query(min(0, id[V]), max(0, id[V]))
				+ seg.query(min(id[U], 0), max(id[U], 0))
				- (2 * seg.query(min(id[U], id[V]), max(id[U], id[V])))
			);
		}
	}
	for(int v: ans){
		cout << v << endl;
	}
}