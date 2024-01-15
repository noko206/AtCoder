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
    int t;
    cin >> t;
    vector<bool> ans;
    REP(_, t){
        ll a, s;
        cin >> a >> s;
        ll x = 0, y = 0;
        int up = 0;
        bool ng = false;
        for(int i = 0; i <= 60; ++i){
            int res = 0;
            if(a & (1 << i)){
                x |= (1 << i);
                y |= (1 << i);
                res += 2;
            }
            else{
                if((up == 0 && (s & (1 << i))) ||
                    (up == 1 && !(s & (1 << i)))){
                    x |= (1 << i);
                    res += 1;
                }
            }
            res += up;
            if(res >= 2){
                up = 1;
            }
            else{
                up = 0;
            }
            res %= 2;
            if(s & (1 << i)){
                if(res == 0){
                    // cout << "aa" << endl;
                    ng = true;
                    break;
                }
            }
            else{
                if(res == 1){
                    ng = true;
                    break;
                }
            }
            // cout << i << endl;
        }
        if(ng){
            ans.push_back(false);
        }
        else{
            if((x & y) == a && (x + y) == s){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
    }
    REP(i, t){
        if(ans[i]){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
}