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

vector<ll> runrun;

void set_runrun(int keta, int cnt = 1, string now = ""){
    if(keta < cnt){
        if(now[0] == '0') return;
        // cout << now << endl;
        runrun.push_back(stoll(now));
        return;
    }
    if(cnt == 1){
        REP(i, 0, 10){
            set_runrun(keta, cnt + 1, (char)(i + '0') + now);
        }
    }
    else{
        if(now[0] - 1 >= '0'){
            set_runrun(keta, cnt + 1, (char)(now[0] - 1) + now);
        }
        set_runrun(keta, cnt + 1, (char)(now[0]) + now);
        if(now[0] + 1 <= '9'){
            set_runrun(keta, cnt + 1, (char)(now[0] + 1) + now);
        }
    }
}

int main(){
    int k;
    cin >> k;
    REP(i, 1, 100){
        if(runrun.size() >= k) break;
        set_runrun(i);
    }
    sort(ALL(runrun));
    // REP(i, runrun.size()){
    //     cout << runrun[i] << endl;
    // }
    cout << runrun[k - 1] << endl;
}