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
    vector<int> index(n + 5, -1);
    queue<pair<int, int>> same;
    REP(i, m){
        if(index[q[i].front()] == -1){
            ++index[q[i].front()] = i;
        }
        else{
            same.push(make_pair(index[q[i].front()], i));
        }
    }
    int cnt = 0;
    while(!same.empty()){
        pair<int, int> v;
        v = same.front();
        same.pop();
        q[v.first].pop();
        q[v.second].pop();
        ++cnt;
        if(!q[v.first].empty()){
            if(index[q[v.first].front()] == -1){
                ++index[q[v.first].front()] = v.first;
            }
            else{
                same.push(make_pair(index[q[v.first].front()], v.first));
            }
        }
        if(!q[v.second].empty()){
            if(index[q[v.second].front()] == -1){
                ++index[q[v.second].front()] = v.second;
            }
            else{
                same.push(make_pair(index[q[v.second].front()], v.second));
            }
        }
    }
    if(cnt == n){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}