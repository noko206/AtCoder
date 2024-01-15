#include <bits/stdc++.h>
using namespace std;

#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
using Graph = vector<vector<int>>;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;
const int INF = 2e9;
const long long LLINF = 1LL << 60;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

vector<int> cnt(200005, 0);
vector<int> parent(200005, 0);

void set_parent(const Graph &G, int v){
    for(auto child : G[v]){
        if(parent[v] == child){
            continue;
        }
        parent[child] = v;
        set_parent(G, child);
    }
}

void propagate_cnt(const Graph &G, int v){
    for(auto child : G[v]){
        if(parent[v] == child){
            continue;
        }
        cnt[child] += cnt[v];
        propagate_cnt(G, child);
    }
}

int main(){
    int n, q;
    cin >> n >> q;
    Graph G(n + 1);
    for (int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    set_parent(G, 1);
    for (int i = 0; i < q; i++){
        int p, x;
        cin >> p >> x;
        cnt[p] += x;
    }
    propagate_cnt(G, 1);
    for (int i = 1; i <= n; i++){
        cout << cnt[i] << ' ';
    }
    cout << endl;
}