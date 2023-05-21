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

class UnionFind {
private:
    vector<int> par;
    vector<int> siz;

public:
    UnionFind(int n){
        for (int i = 0; i < n; i++){
            par.push_back(i);
        }
        siz.resize(n, 1);
    }

    int root(int x) {
        if(par[x] == x){
            return x;
        }
        return par[x] = root(par[x]);
    }

    bool unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if(rx == ry){
            return false;
        }
        if(siz[rx] < siz[ry]){
            swap(rx, ry);
        }
        siz[rx] += siz[ry];
        par[ry] = rx;
        return true;
    }

    bool same(int x, int y){
        return root(x) == root(y);
    }

    int size(int x){
        return siz[root(x)];
    }
};

const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};

int main(){
    vector<vector<int>> a(4);
    vector<int> village;
    REP(i, 4){
        a[i].resize(4);
        REP(j, 4){
            cin >> a[i][j];
            if(a[i][j] == 1){
                village.push_back(i * 4 + j);
            }
        }
    }
    ll ans = 0;
    REP(bit, 1 << 16){
        UnionFind uf(16);
        vector<vector<bool>> ohori(4, vector<bool>(4, false));
        bool is_ok = true;
        REP(i, 16){
            if((bit & (1 << i))){
                REP(j, 4){
                    int y = (i / 4) + dy[j];
                    int x = (i % 4) + dx[j];
                    if(x < 0 || y < 0 || x >= 4 || y >= 4){
                        continue;
                    }
                    if(ohori[y][x] && !uf.same(i, y * 4 + x)){
                        uf.unite(i, y * 4 + x);
                    }
                    ohori[i / 4][i % 4] = true;
                }
            }
            else{
                if(a[i / 4][i % 4] == 1){
                    break;
                }
            }
        }
        bool flg = true;
        REP(i, 4){
            REP(j, 4){
                if(ohori[i][j]){
                    continue;
                }
                int cnt = 0;
                REP(k, 4){
                    int y = i + dy[k];
                    int x = j + dx[k];
                    if(x < 0 || y < 0 || x >= 4 || y >= 4){
                        break;
                    }
                    if(ohori[y][x]){
                        ++cnt;
                    }
                }
                if(cnt == 4){
                    flg = false;
                }
            }
            if(!flg){
                break;
            }
        }
        if(!flg){
            continue;
        }
        for(int v : village){
            for(int u : village){
                if(!uf.same(v, u)){
                    is_ok = false;
                    break;
                }
            }
            if(!is_ok){
                break;
            }
        }
        if(is_ok){
            ++ans;
        }
    }
    cout << ans << endl;
}