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

ll to_base_10(ll x){
    ll ans = 0;
    ll keta = 0;
    while(x > 0){
        if(x % 2 == 1){
            ans += (ll)pow(-2, keta);
        }
        x /= 2;
        ++keta;
    }
    return ans;
}

string to_string_for_base_m2(ll x){
    string ans = "";
    while(x > 0){
        ans = to_string(x % 2) + ans;
        x /= 2;
    }
    return ans;
}

int main(){
    ll n;
    cin >> n;
    if(n == 0){
        cout << 0 << endl;
        return 0;
    }
    vector<ll> base_m2;
    vector<pair<ll, ll>> base_10;
    REP(i, 1 << 20){
        base_m2.push_back(i);
        base_10.push_back(make_pair(to_base_10(i), i));
    }  
    sort(ALL(base_10));
    REP(i, 1 << 20){
        int ok = 1 << 20;
        int ng = -1;
        while(ok - ng != 1){
            int mid = (ok + ng) / 2;
            if(to_base_10(base_m2[i] << 20) + base_10[mid].first >= n){
                ok = mid;
            }
            else{
                ng = mid;
            }
        }
        if(ok == (1 << 20) || to_base_10(base_m2[i] << 20) + base_10[ok].first != n){
            continue;
        }
        cout << to_string_for_base_m2(base_m2[i]) + to_string_for_base_m2(base_10[ok].second) << endl;
        return 0;
    }
    return -1;
}