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
    ld x0, y0, xt, yt;
    cin >> x0 >> y0 >> xt >> yt;
    ld xm = (x0 + xt) / 2, ym = (y0 + yt) / 2;
    x0 -= xm;
    y0 -= ym;
    // 2π/N回転
    ld _cos = cos(2 * M_PI / n), _sin = sin(2 * M_PI / n);
    ld x1 = x0 * _cos - y0 * _sin, y1 = x0 * _sin + y0 * _cos;
    x1 += xm;
    y1 += ym;
    cout << x1 << ' ' << y1 << endl;
}