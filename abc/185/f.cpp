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

class LazySegmentTree {
private:
    int n;
    vector<ll> node, lazy;

public:
    LazySegmentTree(vector<ll> v) {
        int sz = (int)v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1);
        lazy.resize(2*n-1, 0);

        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = node[i*2+1] ^ node[i*2+2];
    }

    void eval(int k, int l, int r) {
        if(lazy[k] == 0) return;
        if(r - l > 1) {
            lazy[2*k+1] = lazy[k];
            lazy[2*k+2] = lazy[k];
        }
        node[k] ^= lazy[k];
        lazy[k] = 0;
    }

    void change(int a, int b, ll x, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b) {
            lazy[k] = x;
            eval(k, l, r);
        }
        else {
            change(a, b, x, 2*k+1, l, (l+r)/2);
            change(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] ^= x;
        }
    }

    ll get(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a) return 0;
        if(a <= l && r <= b) return node[k];
        ll vl = get(a, b, 2*k+1, l, (l+r)/2);
        ll vr = get(a, b, 2*k+2, (l+r)/2, r);
        return vl ^ vr;
    }
};

int main(){
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    REP(i, n){
        cin >> a[i];
    }
    LazySegmentTree seg(a);
    vector<int> ans;
    REP(i, q){
        int t, x, y;
        cin >> t >> x >> y;
        --x;
        if(t == 1){
            seg.change(x, x + 1, seg.get(x, x)^y);
        }
        if(t == 2){
            ans.push_back(seg.get(x, y));
        }
    }
    for(int v : ans){
        cout << v << endl;
    }
}