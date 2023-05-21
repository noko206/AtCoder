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

vector<vector<int>> x;
int n, m;

void set_x(vector<int> v){
    if(v.size() == n){
        x.push_back(v);
        return;
    }
    int mi;
    if(v.size() == 0){
        mi = 0;
    }
    else{
        mi = v[v.size() - 1];
    }
    v.push_back(0);
    REP(i, mi, m){
        v[v.size() - 1] = i;
        set_x(v);
    }
}

int main(){
    int q;
    cin >> n >> m >> q;
    vector<int> a(q), b(q), c(q), d(q);
    REP(i, q){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        --a[i], --b[i];
    }
    ll ans = 0;
    vector<int> tmp;
    set_x(tmp);
    // cout << x.size() << endl;
    REP(i, x.size()){
        ll cnt = 0;
        REP(j, q){
            if(x[i][b[j]] - x[i][a[j]] == c[j]){
                cnt += d[j];
            }
        }
        chmax(ans, cnt);
    }
    cout << ans << endl;
}