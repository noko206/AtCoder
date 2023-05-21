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

struct Point{
    double x;
    double y;
    double z;
};

double get_dist(Point a, Point b){
    double tmp = 0;
    tmp += (a.x - b.x) * (a.x - b.x);
    tmp += (a.y - b.y) * (a.y - b.y);
    tmp += (a.z - b.z) * (a.z - b.z);
    return sqrt(tmp);
}

int main(){
    int t;
    cin >> t;
    int l, x, y;
    cin >> l >> x >> y;
    int q;
    cin >> q;
    Point a, c;
    c.x = x;
    c.y = y;
    c.z = 0;
    vector<double> ans(q);
    REP(i, q){
        int e;
        cin >> e;
        a.x = 0;
        double rd =  (-1)*(2 * M_PI * e / (double)t) - (M_PI / 2.0);
        a.y = (l / 2.0) * cos(rd);
        a.z = 0;
        double d = get_dist(a, c);
        double at = atan(((l / 2.0) * sin(rd) + (l / 2.0)) / d);
        double r = at * 180 / M_PI;
        ans[i] = r;
    }
    REP(i, q){
        printf("%.9f\n", ans[i]);
    }
}