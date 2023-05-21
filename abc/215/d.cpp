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
    map<int, bool> mp;
    REP(i, n){
        int a;
        cin >> a;
        if(a != 1){
            mp[a] = true;
        }
        for (int j = 2; (ll)j * j <= (ll)a; ++j){
            if(a % j == 0){
                mp[j] = true;
                mp[a / j] = true;
            }
        }
    }
    // for(pair<int, bool> p : mp){
    //     cout << p.first << ' ' << p.second << endl;
    // }
    // return 0;
    vector<int> ans;
    for (int k = 1; k <= m; ++k){
        if(mp.count(k) != 0){
            continue;
        }
        bool is_ok = true;
        for (int j = 1; (ll)j * j <= (ll)k; ++j){
            if(k % j == 0){
                if(mp.count(j) != 0){
                    is_ok = false;
                    break;
                }
                if(mp.count(k / j) != 0){
                    is_ok = false;
                    break;
                }
            }
        }
        if(is_ok){
            ans.push_back(k);
        }
    }
    cout << ans.size() << endl;
    for(int a : ans){
        cout << a << endl;
    }
}