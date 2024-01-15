#include <bits/stdc++.h>
using namespace std;

#define _overload3(_1,_2,_3,name,...) name
#define _REP(i,n) REPI(i,0,n)
#define REPI(i,a,b) for(int i=int(a);i<int(b);++i)
#define REP(...) _overload3(__VA_ARGS__,REPI,_REP,)(__VA_ARGS__)
#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
#define MEMSET(v) memset((v), 0, sizeof(v))
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
    REP(i, n){
        cin >> a[i];
    }
    ll ans = LLINF;
    REP(bit, 1<<(n-1)) {
        vector<int> _enum;
        REP(i, n) {
            if (bit & (1<<i)) {
                _enum.push_back(i);
            }
        }
        _enum.push_back(-1);
        ll _xor = 0, _or = 0;
        int k = 0;
        REP(i, n){
            _or |= a[i];
            if(_enum[k] == i || i == n - 1){
                ++k;
                _xor ^= _or;
                _or = 0;
            }
        }
        chmin(ans, _xor);
    }
    cout << ans << endl;
}