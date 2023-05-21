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
    ll n, a, b, p, q, r, s;
    cin >> n >> a >> b >> p >> q >> r >> s;
    vector<string> ans(q - p + 1);
    string dot = "";
    REP(i, s - r + 1){
        dot += ".";
    }
    REP(i, q - p + 1){
        ans[i] = dot;
    }
    ll left = max(1 - a, 1 - b);
    ll right = min(n - 1, n - b);

    ll i_min = max(a + left, p);
    ll j_min = max(b + left, r);
    ll k = max(i_min - a, j_min - b);
    i_min = a + k;
    j_min = b + k;
    ll i_max = min(a + right, q);
    ll j_max = min(b + right, s);
    k = min(i_max - a, j_max - b);
    i_max = a + k;
    j_max = b + k;

    // ll i_min = max(a + left, p);
    // ll j_min = max(b + left, r);
    // ll i_max = min(a + right, q);
    // ll j_max = min(b + right, s);
    while(i_min <= i_max && j_min <= j_max){
        ans[i_min - p][j_min - r] = '#';
        ++i_min, ++j_min;
    }

    left = max(1 - a, b - n);
    right = min(n - a, b - 1);

    i_min = max(a + left, p); cout << i_min << endl;
    j_min = min(b - left, s); cout << j_min << endl;
    k = min(i_min - a, b - j_min);
    i_min = a + k;
    j_min = b - k;
    i_max = min(a + right, q);
    j_max = max(b - right, r);
    k = max(i_max - a, b - j_max);
    // i_min = max(a + left, p);
    // j_max = max(b - left, r);
    // i_max = min(a + right, q);
    // j_min = min(b - right, s);

    while(i_min <= i_max && j_min <= j_max){
        ans[i_min - p][j_max - r] = '#';
        ++i_min, --j_max;
    }

    REP(i, ans.size()){
        cout << ans[i] << endl;
    }
}