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
    double p;
    cin >> p;

    auto f = [p](double x){
        return x + p / pow(2, x / 1.5);
    };

    double left = 0;
    double right = 1e9;
    
    while(right - left > 1e-9){
        double c1 = (left * 2 + right) / 3.0;
        double c2 = (left + right * 2) / 3.0;
        if(f(c1) > f(c2)){
            left = c1;
        }
        else{
            right = c2;
        }
    }

    printf("%.12f\n", f(left));
}