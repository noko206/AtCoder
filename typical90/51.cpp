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
    int n, k;
    ll p;
    cin >> n >> k >> p;
    vector<ll> even, odd;
    REP(i, n){
        ll a;
        cin >> a;
        if(i % 2 == 0){
            even.push_back(a);
        }
        else{
            odd.push_back(a);
        }
    }
    vector<vector<ll>> even_conb(even.size() + 1), odd_conb(odd.size() + 1);
    REP(i, 1 << even.size()){
        ll sum = 0;
        int cnt = 0;
        REP(j, even.size()){
            if(i & (1 << j)){
                sum += even[j];
                ++cnt;
            }
        }
        even_conb[cnt].push_back(sum);
    }
    REP(i, 1 << odd.size()){
        ll sum = 0;
        int cnt = 0;
        REP(j, odd.size()){
            if(i & (1 << j)){
                sum += odd[j];
                ++cnt;
            }
        }
        odd_conb[cnt].push_back(sum);
    }
    REP(i, even_conb.size()){
        sort(ALL(even_conb[i]));
    }
    ll ans = 0;
    REP(i, odd_conb.size()){
        if(k - i < 0 || k - i >= even_conb.size()){
            continue;
        }
        REP(j, odd_conb[i].size()){
            int ok = -1;
            int ng = even_conb[k - i].size();
            while(ng - ok != 1){
                int mid = (ok + ng) / 2;
                if(odd_conb[i][j] + even_conb[k - i][mid] <= p){
                    ok = mid;
                }
                else{
                    ng = mid;
                }
            }
            ans += (ll)ok + 1;
        }
    }
    cout << ans << endl;
}