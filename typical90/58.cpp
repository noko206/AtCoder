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
    ll k;
    cin >> n >> k;
    vector<bool> seen(100000, false);
    vector<int> disp;
    int cnt = 0;
    int tmp = n;
    while(true){
        if(seen[n]){
            break;
        }
        if((ll)cnt == k){
            cout << n << endl;
            return 0;
        }
        seen[n] = true;
        ++cnt;
        int m = n;
        REP(i, 5){
            n += m % 10;
            m /= 10;
        }
        n %= 100000;
    }
    cnt = 0;
    while(true){
        if(tmp == n){
            break;
        }
        ++cnt;
        int m = tmp;
        REP(i, 5){
            tmp += m % 10;
            m /= 10;
        }
        tmp %= 100000;
    }
    bool is_start = true;
    while(true){
        if(tmp == n && !is_start){
            break;
        }
        if(is_start){
            is_start = false;
        }
        disp.push_back(tmp);
        int m = tmp;
        REP(i, 5){
            tmp += m % 10;
            m /= 10;
        }
        tmp %= 100000;
    }
    cout << disp[(k - cnt) % disp.size()] << endl;
    // cout << disp[disp.size() - 1] << endl;
}