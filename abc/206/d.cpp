#include <bits/stdc++.h>
using namespace std;

#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
using Graph = vector<vector<int>>;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;
const int INF = 1 << 29;
const long long LLINF = 1LL << 60;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

class UnionFind {
private:
    vector<int> parent;

public:
    UnionFind(int n){
        for (int i = 0; i < n; i++){
            parent.push_back(i);
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
};

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x : a){
        cin >> x;
    }
    UnionFind uf(200005);
    int ans = 0;
    for (int i = 0; i < (n + 1) / 2; i++){
        if(uf.same(a[i], a[(n - 1) - i])){
            continue;
        }
        uf.unite(a[i], a[(n - 1) - i]);
        ans++;
    }
    cout << ans << endl;
}