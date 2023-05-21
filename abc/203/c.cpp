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
    ll k;
    cin >> n >> k;
    vector<pair<ll, ll>> ab(n);
    REP(i, n){
        ll a, b;
        cin >> a >> b;
        ab[i] = make_pair(a, b);
    }
    sort(ALL(ab));
    ll current = 0;
    REP(i, n){
        k -= ab[i].first - current;
        current = ab[i].first;
        if(k < 0){
            current += k;
            break;
        }
        k += ab[i].second;
        if(i == n - 1){
            current += k;
        }
    }
    cout << current << endl;
}