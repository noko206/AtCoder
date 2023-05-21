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
    priority_queue<pair<int, int>> pq;
    vector<queue<int>> q(m);
    REP(i, m){
        int k;
        cin >> k;
        REP(j, k){
            int a;
            cin >> a;
            q[i].push(a);
        }
    }
    REP(i, m){
        pq.push(make_pair(q[i].front(), i));
        q[i].pop();
    }
    bool is_ok = true;
    while(!pq.empty()){
        pair<int, int> v, u;
        v = pq.top();
        pq.pop();
        // 1個取り出して空になった場合
        if(pq.empty()){
            is_ok = false;
            break;
        }
        u = pq.top();
        pq.pop();
        if(v.first != u.first){
            is_ok = false;
            break;
        }
        if(!q[v.second].empty()){
            pq.push(make_pair(q[v.second].front(), v.second));
            q[v.second].pop();
        }
        if(!q[u.second].empty()){
            pq.push(make_pair(q[u.second].front(), u.second));
            q[u.second].pop();
        }
    }
    if(is_ok){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}