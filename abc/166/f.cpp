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
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<char> ans(n);
    REP(i, n){
        string s;
        cin >> s;
        if(s == "AB"){
            if(a < b){
                ++a;
                --b;
                ans[i] = 'A';
            }
            else{
                --a;
                ++b;
                ans[i] = 'B';
            }
        }
        if(s == "AC"){
            if(a < c){
                ++a;
                --c;
                ans[i] = 'A';
            }
            else{
                --a;
                ++c;
                ans[i] = 'C';
            }
        }
        if(s == "BC"){
            if(b < c){
                ++b;
                --c;
                ans[i] = 'B';
            }
            else{
                --b;
                ++c;
                ans[i] = 'C';
            }
        }
        if(a < 0 || b < 0 || c < 0){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    REP(i, n){
        cout << ans[i] << endl;
    }
}