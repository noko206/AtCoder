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
    multiset<ll> s;
    vector<ll> ans;
    REP(i, q){
        int t;
        cin >> t;
        if(t == 1){
            ll x;
            cin >> x;
            s.insert(x);
        }
        if(t == 2){
            ll x;
            int k;
            cin >> x >> k;
            auto it = s.upper_bound(x);
            bool is_break = false;
            auto begin = s.begin();
            REP(i, k){
                if(it == begin){
                    is_break = true;
                    break;
                }
                --it;
            }
            if(is_break){
                ans.push_back(-1);
            }
            else{
                ans.push_back(*it);
            }
        }
        if(t == 3){
            ll x;
            int k;
            cin >> x >> k;
            auto it = s.lower_bound(x);
            auto end = s.end();
            if(it == end){
                ans.push_back(-1);
                continue;
            }
            bool is_break = false;
            REP(i, k - 1){
                ++it;
                if(it == end){
                    is_break = true;
                    break;
                }
            }
            if(is_break){
                ans.push_back(-1);
            }
            else{
                ans.push_back(*it);
            }
        }
    }
    REP(i, (int)ans.size()){
        cout << ans[i] << endl;
    }
}