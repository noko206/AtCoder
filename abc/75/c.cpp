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

class UnionFind {
private:
    vector<int> parent;

public:
    UnionFind(int n){
        for (int i = 0; i < n; i++){
            parent.resize(n);
            parent[i] = i;
        }
    }

    int root(int x) {
        if(parent[x] == x){
            return x;
        }
        return parent[x] = root(parent[x]);
    }

    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if(rx == ry){
            return;
        }
        parent[rx] = ry;
    }

    bool same(int x, int y){
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

    void reset(int n){
        for (int i = 0; i < n; i++){
            parent[i] = i;
        }
    }
};

int main(){
    int n, m, ans = 0;
    cin >> n >> m;
    UnionFind uf(n);
    vector<pair<int, int>> ab;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        ab.push_back(make_pair(a, b));
    }
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            if(i == j){
                continue;
            }
            uf.unite(ab[j].first, ab[j].second);
        }
        // rootが2種類以上あるか調べる
        int root = uf.root(0);
        for (int j = 1; j < n; j++){
            if(root != uf.root(j)){
                ans++;
                break;
            }
        }
        uf.reset(n);
    }
    cout << ans << endl;
}