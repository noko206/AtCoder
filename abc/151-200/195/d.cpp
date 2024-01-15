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
    int n, m, q;
    cin >> n >> m >> q;
    vector<pair<int, int>> vw(n);
    REP(i, n){
        cin >> vw[i].second >> vw[i].first;
    }
    vector<pair<int, int>> x(m);
    REP(i, m){
        cin >> x[i].first;
        x[i].second = i + 1;
    }
    vector<pair<int, int>> query(q);
    REP(i, q){
        cin >> query[i].first >> query[i].second;
    }
    sort(ALLR(vw));
    sort(ALL(x));
    REP(k, q){
        vector<bool> is_inserted(n, false);
        ll ans = 0;
        REP(i, m){
            if(query[k].first <= x[i].second && x[i].second <= query[k].second){
                continue;
            }
            REP(j, n){
                if(is_inserted[j]){
                    continue;
                }
                if(vw[j].second <= x[i].first){
                    ans += vw[j].first;
                    is_inserted[j] = true;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
}