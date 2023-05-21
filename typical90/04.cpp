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
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    REP(i, h){
        REP(j, w){
            cin >> a[i][j];
        }
    }
    vector<int> b(h);
    REP(i, h){
        int tmp = 0;
        REP(j, w){
            tmp += a[i][j];
        }
        b[i] = tmp;
    }
    vector<int> c(w);
    REP(i, w){
        int tmp = 0;
        REP(j, h){
            tmp += a[j][i];
        }
        c[i] = tmp;
    }
    REP(i, h){
        REP(j, w){
            cout << b[i] + c[j] - (a[i][j]) << ' ';
        }
        cout << endl;
    }
}