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
    map<int, int> mp;
    REP(i, n){
        int a, b;
        cin >> a >> b;
        ++mp[a];
        --mp[a + b];
    }
    int pre = -1;
    for(pair<int, int> now : mp){
        if(pre == -1){
            pre = now.first;
            continue;
        }
        mp[now.first] += mp[pre];
        pre = now.first;
    }
    pre = -1;
    vector<int> ans(n + 1, 0);
    for(pair<int, int> now : mp){
        if(pre == -1){
            pre = now.first;
            continue;
        }
        ans[mp[pre]] += now.first - pre;
        pre = now.first;
    }
    REP(i, n){
        cout << ans[i + 1] << ' ';
    }
    cout << endl;
}