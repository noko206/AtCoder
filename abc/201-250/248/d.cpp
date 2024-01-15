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

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> cnt(n + 1);
    REP(i, n){
        cin >> a[i];
        cnt[a[i]].push_back(i + 1);
    }
    int q;
    cin >> q;
    vector<int> ans(q);
    REP(i, q){
        int l, r, x;
        cin >> l >> r >> x;
        if(cnt[x].size() == 0){
            ans[i] = 0;
            continue;
        }
        int cl = distance(cnt[x].begin(), lower_bound(ALL(cnt[x]), l));
        int cr = distance(cnt[x].begin(), upper_bound(ALL(cnt[x]), r));
        ans[i] = cr - cl;
        //cout << cr << ' ' << cl << endl;
    }
    REP(i, q){
        cout << ans[i] << endl;
    }
}