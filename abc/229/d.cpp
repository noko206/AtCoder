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
    string s;
    int k;
    cin >> s >> k;
    int j = -1;
    int n = s.length();
    int cnt = 0;
    int ans = 0;

    bool is_all_dot = true;
    REP(i, n){
        if(s[i] != '.'){
            is_all_dot = false;
        }
    }
    if(is_all_dot){
        cout << min(k, n) << endl;
        return 0;
    }

    REP(i, n){
        while(cnt < k && j + 1 < n){
            if(s[j + 1] == '.'){
                ++cnt;
            }
            ++j;
        }
        while(j != n - 1 && s[j + 1] != '.'){
            ++j;
        }
        // cout << i << ' ' << j << endl;
        chmax(ans, j - i + 1);
        if(s[i] == '.'){
            --cnt;
        }
    }
    cout << ans << endl;
}