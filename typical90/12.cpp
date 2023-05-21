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

// Union-Find
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

bool f[2005][2005];

UnionFind uf(2000 * 2000);

int main(){
    int h, w, q;
    cin >> h >> w >> q;
    vector<string> ans;
    REP(i, q){
        int t;
        cin >> t;
        if(t == 1){
            int _r, _c;
            cin >> _r >> _c;
            f[_r][_c] = true;
            if(f[_r - 1][_c]){
                int r = _r - 1, c = _c - 1;
                uf.unite(r * h + c, (r - 1) * h + c);
            }
            if(f[_r][_c + 1]){
                int r = _r - 1, c = _c - 1;
                uf.unite(r * h + c, r * h + (c + 1));
            }
            if(f[_r + 1][_c]){
                int r = _r - 1, c = _c - 1;
                uf.unite(r * h + c, (r + 1) * h + c);
            }
            if(f[_r][_c - 1]){
                int r = _r - 1, c = _c - 1;
                uf.unite(r * h + c, r * h + (c - 1));
            }
        }
        else{
            int ra, ca, rb, cb;
            cin >> ra >> ca >> rb >> cb;
            --ra, --ca, --rb, --cb;
            if(uf.same(ra * h + ca, rb * h + cb) && f[ra + 1][ca + 1] && f[rb + 1][cb + 1]){
                ans.push_back("Yes");
            }
            else{
                ans.push_back("No");
            }
        }
    }
    for(string a : ans){
        cout << a << endl;
    }
    return 0;
}