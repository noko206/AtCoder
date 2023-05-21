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
    vector<int> a(n);
    REP(i, n){
        cin >> a[i];
    }
    int q;
    cin >> q;
    vector<int> b(q);
    REP(i, q){
        cin >> b[i];
    }
    sort(ALL(a));

    vector<int> ans(q, INF);
    REP(i, q){
        int ok = -1;
        int ng = n;
        while(ng - ok != 1){
            int mid = (ok + ng) / 2;
            if(a[mid] < b[i]){
                ok = mid;
            }
            else{
                ng = mid;
            }
        }
        if(ok != -1){
            chmin(ans[i], abs(a[ok] - b[i]));
        }
        if(ng != n){
            chmin(ans[i], abs(a[ng] - b[i]));
        }
    }

    REP(i, q){
        cout << ans[i] << endl;
    }
}