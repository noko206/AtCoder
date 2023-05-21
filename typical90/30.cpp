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
    int n, k;
    cin >> n >> k;
    int ans = 0;
    vector<int> test(n + 1, 0);
    for (int i = 2; i <= n; ++i){
        int m = i;
        vector<bool> is_prime_factors(m + 1, false);
        int cnt = 0;
        for (int j = 2; (ll)j * j <= (ll)m; ++j){
            while(m % j == 0){
                if(!is_prime_factors[j]){
                    is_prime_factors[j] = true;
                    ++cnt;
                }
                m /= j;
            }
        }
        if(m != 1){
            ++cnt;
        }
        if(cnt >= k){
            ++ans;
        }
        test[i] = cnt;
    }
    ofstream f("test.txt");
    for(int v : test){
        f << v << ',';
    }
    f.close();
    cout << ans << endl;
}