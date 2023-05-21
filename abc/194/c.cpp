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

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> cnt(405, 0);
    REP(i, n){
        cin >> a[i];
        ++cnt[a[i] + 200];
    }
    ll ans = 0;
    REP(i, n){
        --cnt[a[i] + 200];
        for (ll j = -200; j <= 200; ++j) {
            ans += (a[i] - j) * (a[i] - j) * cnt[j + 200];
        }
    }
    cout << ans << endl;
}