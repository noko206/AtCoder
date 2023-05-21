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
    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    map<int, int> flg;
    REP(i, n){
        cin >> c[i];
        if(flg.count(c[i]) == 0){
            flg[c[i]] = 0;
        }
    }
    int tmp = 0;
    REP(i, k){
        if(flg[c[i]] == 0){
            ++tmp;
        }
        ++flg[c[i]];
    }
    int ans = tmp;
    REP(i, k, n){
        if(flg[c[i]] == 0){
            ++tmp;
        }
        ++flg[c[i]];
        --flg[c[i - k]];
        if(flg[c[i - k]] == 0){
            --tmp;
        }
        chmax(ans, tmp);
    }
    cout << ans << endl;
}