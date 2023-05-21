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

vector<int> cut;
vector<int> ans;

void query(int c, int x){
    int ok = cut.size();
    int ng = -1;
    while(ok - ng > 1){
        int mid = (ok + ng) / 2;
        if(cut[mid] > x){
            ok = mid;
        }
        else{
            ng = mid;
        }
    }
    if(c == 1){
        cut.insert(cut.begin() + ok, x);
    }
    else{
        ans.push_back(cut[ok] - cut[ng]);
    }
}

int main(){
    int l, q;
    cin >> l >> q;
    int c, x;
    cut.push_back(0);
    cut.push_back(l);
    REP(i, q){
        cin >> c >> x;
        query(c, x);
    }
    for(int a : ans){
        cout << a << endl;
    }
}