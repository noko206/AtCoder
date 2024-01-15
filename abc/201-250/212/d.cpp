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

int main(){
    int q;
    cin >> q;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll s = 0;
    vector<ll> ans;
    REP(i, q){
        int p;
        cin >> p;
        int x;
        ll mi;
        switch(p){
            case 1:
                cin >> x;
                pq.push(x - s);
                break;
            case 2:
                cin >> x;
                s += x;
                break;
            case 3:
                mi = pq.top();
                pq.pop();
                mi += s;
                ans.push_back(mi);
                break;
        }
    }
    for(ll a : ans){
        cout << a << endl;
    }
}