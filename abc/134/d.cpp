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
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    REP(i, n){
        cin >> a[i + 1];
    }
    vector<int> ans(n + 1, 0);
    for(int i = n; i > 0; --i){
        int j = i * 2;
        int cnt = 0;
        while(j <= n){
            cnt += ans[j];
            j += i;
        }
        if(cnt % 2 == a[i]){
            ans[i] = 0;
        }
        else{
            ans[i] = 1;
        }
    }
    vector<int> b;
    REP(i, 1, n + 1){
        if(ans[i] == 1){
            b.push_back(i);
        }
    }
    cout << b.size() << endl;
    for(int v : b){
        cout << v << ' ';
    }
    cout << endl;
}