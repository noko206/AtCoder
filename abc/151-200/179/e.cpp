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
    ll n;
    cin >> n;
    int x, m;
    cin >> x >> m;
    vector<int> a;
    a.push_back(x);
    vector<bool> flg(m, false);
    flg[x] = true;
    ll ans = 0;
    ll cnt = 0;
    REP(i, 2 * m){
        int na = ((ll)a[i - cnt] * a[i - cnt]) % (ll)m;
        // cout << i << endl;
        if(na == 0 || i + 1 == n){
            for(int v : a){
                ans += (ll)v;
            }
            break;
        }
        if(flg[na]){
            if(cnt == 0){
                for(int v : a){
                    ans += (ll)v;
                }
                cnt = (ll)a.size();
                // cout << cnt << endl;
                REP(j, m){
                    flg[j] = false;
                }
                flg[na] = true;
                a.clear();
                // cout << a.size() << endl;
                a.push_back(na);
                // cout << a.size() << endl;
                // cout << "ok" << endl;
            }
            else{
                // cout << cnt << endl;
                ll sum = 0;
                for(int v : a){
                    sum += (ll)v;
                }
                ans += ((n - cnt) / (ll)a.size()) * sum;
                REP(j, (n - cnt) % (ll)a.size()){
                    ans += (ll)a[j];
                }
                break;
            }
        }
        else{
            // cout << a.size() << endl;
            // cout << na << endl;
            a.push_back(na);
            flg[na] = true;
        }
    }
    cout << ans << endl;
}