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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    REP(i, n){
        cin >> a[i];
    }
    REP(i, m){
        cin >> b[i];
    }
    sort(ALL(a));
    sort(ALL(b));
    int ai = 0;
    int bi = 0;
    int ans = INF;
    while(ai < n && bi < m){
        chmin(ans, abs(a[ai] - b[bi]));
        if(a[ai] < b[bi]){
            ++ai;
        }
        else if(a[ai] > b[bi]){
            ++bi;
        }
        else{
            break;
        }
    }
    cout << ans << endl;
}