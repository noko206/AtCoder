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
    int q;
    cin >> q;
    deque<pair<int, int>> dq;
    vector<ll> ans;
    REP(i, q){
        int t;
        cin >> t;
        if(t == 1){
            int x, c;
            cin >> x >> c;
            dq.push_back({x, c});
        }
        else{
            int c;
            cin >> c;
            ll tot = 0;
            while(true){
                pair<int, int> p = dq.front();
                dq.pop_front();
                int px = p.first;
                int pc = p.second;
                if(c < pc){
                    tot += (ll)c * px;
                    ans.push_back(tot);
                    pc -= c;
                    dq.push_front({px, pc});
                    break;
                }
                else if(c == pc){
                    tot += (ll)c * px;
                    ans.push_back(tot);
                    break;
                }
                else{
                    tot += (ll)pc * px;
                    c -= pc;
                }
            }
        }
    }
    for(ll a : ans){
        cout << a << endl;
    }
}