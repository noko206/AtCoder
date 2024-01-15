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
    priority_queue<int, vector<int>, greater<int>> pq;
    REP(i, n){
        int a;
        cin >> a;
        pq.push(a);
    }
    vector<pair<int, int>> cb(m);
    REP(i, m){
        cin >> cb[i].second >> cb[i].first;
    }
    sort(ALLR(cb));
    ll ans = 0;
    REP(i, m){
        bool is_break = false;
        REP(j, cb[i].second){
            if(pq.empty()){
                break;
            }
            int v = pq.top();
            pq.pop();
            if(chmax(v, cb[i].first)){
                ans += v;
            }
            else{
                ans += v;
                is_break = true;
                break;
            }
        }
        if(pq.empty() || is_break){
            break;
        }
    }
    while(!pq.empty()){
        int u = pq.top();
        pq.pop();
        ans += u;
    }
    cout << ans << endl;
}