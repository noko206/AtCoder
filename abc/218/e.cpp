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

int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> v;
    ll ans = 0;
    REP(i, m){
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        v.push_back(make_pair(c, make_pair(a, b)));
        ans += c;
    }
    sort(ALL(v));
    UnionFind uf(n);
    bool is_ok_break = false;
    REP(i, m){
        pair<int, int> ab = v[i].second;
        if(uf.same(ab.first, ab.second) && v[i].first > 0){
            continue;
        }
        uf.unite(ab.first, ab.second);
        if(v[i].first > 0 && is_ok_break){
            break;
        }
        ans -= v[i].first;
        if(uf.size(0) == n){
            is_ok_break = true;
        }
    }
    cout << ans << endl;
}