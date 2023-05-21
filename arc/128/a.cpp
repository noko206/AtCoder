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
    int n;
    cin >> n;
    vector<int> a(n);
    REP(i, n){
        cin >> a[i];
    }
    bool is_up = !(a[0] < a[1]);
    vector<int> ans(n);
    REP(i, n - 1){
        if(a[i] < a[i + 1]){
            if(!is_up){
                is_up = true;
                a[i] = 1;
            }
            else{
                a[i] = 0;
            }
        }
        else{
            if(is_up){
                is_up = false;
                a[i] = 1;
            }
            else{
                a[i] = 0;
            }
        }
    }
    
    int cnt = 0;
    REP(i, n){
        if(ans[i] == 1){
            ++cnt;
        }
    }
    if(cnt % 2 == 1){
        for (int i = n - 1; i >= 0; ++i){
            if(ans[i] == 1){
                ans[i] = 0;
                break;
            }
        }
    }
    REP(i, n){
        cout << ans[i] << ' ';
    }
    cout << endl;
}