#include <bits/stdc++.h>
using namespace std;

#define _overload3(_1,_2,_3,name,...) name
#define _REP(i,n) REPI(i,0,n)
#define REPI(i,a,b) for(int i=int(a);i<int(b);++i)
#define REP(...) _overload3(__VA_ARGS__,REPI,_REP,)(__VA_ARGS__)
#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
#define MEMSET(v, h) memset((v), h, sizeof(v))
typedef long long ll;
typedef long double ld;
const int MOD = 1e9+7;
const int INF = 2e9;
const long long LLINF = 2e18;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

int main(){
    string x;
    ll m;
    cin >> x >> m;
    if(x.length() == 1){
        if(stoi(x) <= m){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
        return 0;
    }
    int ma = 0;
    for(char c : x){
        chmax(ma, c - '0');
    }
    ll ok = ma, ng = m + 1;
    while(ng - ok > 1){
        ll mid = (ok + ng) / 2;
        ll sum = 0;
        for(char c : x){
            if(sum > m / mid){
                sum = m + 1;
                break;
            }
            else{
                sum = sum * mid + (c - '0');
            }
        }
        if(sum <= m){
            ok = mid;
        }
        else{
            ng = mid;
        }
    }
    cout << ok - ma << endl;
}