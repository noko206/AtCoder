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

std::ostream &operator<<(std::ostream &dest, __int128_t value) {
    std::ostream::sentry s(dest);
    if (s) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[128];
        char *d = std::end(buffer);
        do {
            --d;
            *d = "0123456789"[tmp % 10];
            tmp /= 10;
        } while (tmp != 0);
        if (value < 0) {
            --d;
            *d = '-';
        }
        int len = std::end(buffer) - d;
        if (dest.rdbuf()->sputn(d, len) != len) {
            dest.setstate(std::ios_base::badbit);
        }
    }
    return dest;
}

__int128 gcd(__int128 x, __int128 y){ return (x % y) ? gcd(y, x % y) : y; }
__int128 lcm(__int128 x, __int128 y){ return x / gcd(x, y) * y; }

int main(){
    int n, m;
    cin >> n >> m;
    __int128 sum = 1;
    REP(i, n){
        int a;
        cin >> a;
        sum = lcm(sum, (__int128)a);
    }
    vector<int> ans;
    for (int k = 1; k <= m; ++k){
        if(gcd(sum, (__int128)k) == (__int128)1){
            ans.push_back(k);
        }
    }
    cout << ans.size() << endl;
    for(int a : ans){
        cout << a << endl;
    }
}