#include <bits/stdc++.h>
using namespace std;

#define _overload3(_1,_2,_3,name,...) name
#define _REP(i,n) REPI(i,0,n)
#define REPI(i,a,b) for(int i=int(a);i<int(b);++i)
#define REP(...) _overload3(__VA_ARGS__,REPI,_REP,)(__VA_ARGS__)
#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
#define MEMSET(v, h) memset((v), h, sizeof(v))
typedef long long ll;
typedef long double ld;
const int MOD = 1e9+7;
const int INF = 2e9;
const long long LLINF = 1LL<<60;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

int main(){
    int n;
    cin >> n;
    vector<int> t(n);
    vector<ld> l(n), r(n);
    REP(i, n){
        cin >> t[i] >> l[i] >> r[i];
        switch(t[i]){
            case 1:
                break;
            case 2:
                r[i] -= 0.1;
                break;
            case 3:
                l[i] += 0.1;
                break;
            case 4:
                r[i] -= 0.1;
                l[i] += 0.1;
                break;
        }
    }
    int ans = 0;
    REP(i, n){
        REP(j, i + 1, n){
            if(l[j] <= l[i] && l[i] <= r[j]){
                ans++;
            }
            else if(l[i] <= l[j] && r[j] <= r[i]){
                ans++;
            }
            else if(l[j] <= r[i] && r[i] <= r[j]){
                ans++;
            }
        }
    }
    cout << ans << endl;
}