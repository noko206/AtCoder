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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    REP(i, n){
        cin >> a[i];
    }
    int shift = 0;
    vector<int> ans;
    REP(i, q){
        int t, x, y;
        cin >> t >> x >> y;
        --x, --y;
        switch(t){
            case 1:
                swap(a[(x - shift + 1000 * n) % n], a[(y - shift + 1000 * n) % n]);
                break;
            case 2:
                ++shift;
                break;
            case 3:
                ans.push_back(a[(x - shift + 1000 * n) % n]);
                break;
        }
        // REP(i, n){
        //     cout << a[(i - shift + n) % n] << ' ';
        // }
        // cout << endl;
    }
    for(int an : ans){
        cout << an << endl;
    }
}