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
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<int> p(a), q(b), r(c);
    REP(i, a){
        cin >> p[i];
    }
    REP(i, b){
        cin >> q[i];
    }
    REP(i, c){
        cin >> r[i];
    }
    sort(ALLR(p));
    sort(ALLR(q));
    sort(ALLR(r));
    priority_queue<int, vector<int>, greater<int>> ans;
    REP(i, x){
        ans.push(p[i]);
    }
    REP(i, y){
        ans.push(q[i]);
    }
    REP(i, c){
        // cout << ans.top() << endl;
        if(r[i] > ans.top()){
            ans.pop();
            ans.push(r[i]);
        }
        else{
            break;
        }
    }
    ll tot = 0;
    while(!ans.empty()){
        tot += ans.top();
        ans.pop();
    }
    cout << tot << endl;
}