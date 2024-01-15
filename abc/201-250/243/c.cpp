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
    map<int, int> mpR, mpL;
    vector<int> x(n), y(n);
    REP(i, n){
        cin >> x[i] >> y[i];
    }
    string s;
    cin >> s;
    REP(i, n){
        if(s[i] == 'L'){
            if(mpL.find(y[i]) == mpL.end()){
                mpL[y[i]] = x[i];
            }
            else{
                chmax(mpL[y[i]], x[i]);
            }
        }
        else{
            if(mpR.find(y[i]) == mpR.end()){
                mpR[y[i]] = x[i];
            }
            else{
                chmin(mpR[y[i]], x[i]);
            }
        }
    }
    bool is_ok = false;
    for(pair<int, int> p : mpL){
        int yl = p.first;
        int xl = p.second;
        if(mpR.find(yl) == mpR.end()){
            continue;
        }
        if(mpR[yl] < xl){
            is_ok = true;
        }
    }
    if(is_ok){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}