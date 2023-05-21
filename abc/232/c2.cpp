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
ll gcd(ll x, ll y){ return (x % y) ? gcd(y, x % y) : y; }
ll lcm(ll x, ll y){ return x / gcd(x, y) * y; }

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> ta(n, vector<bool>(n, false));
    vector<vector<bool>> ao(n, vector<bool>(n, false));
    REP(i, m){
        int a, b;
        cin >> a >> b;
        --a, --b;
        ta[a][b] = true;
        ta[b][a] = true;
    }
    REP(i, m){
        int c, d;
        cin >> c >> d;
        --c, --d;
        ao[c][d] = true;
        ao[d][c] = true;
    }
    if(m == 0){
        cout << "Yes" << endl;
        return 0;
    }
    vector<int> p(n);
    REP(i, n){
        p[i] = i;
    }
    bool is_ok = false;
    do{
        bool same = true;
        REP(i, n){
            REP(j, n){
                if(ta[i][j] != ao[p[i]][p[j]]){
                    same = false;
                }
            }
        }
        if(same){
            is_ok = true;
            break;
        }
    }while(next_permutation(ALL(p)));
    if(is_ok){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}