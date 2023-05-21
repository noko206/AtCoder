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
    ll n, k;
    cin >> n >> k;
    vector<int> a(n), b;
    REP(i, n){
        cin >> a[i];
    }
    b = a;
    sort(ALL(b));
    ll okashi = k / n;
    int amari = k % n;
    int ok = -1;
    if(amari != 0){
        ok = b[amari - 1];
    }
    REP(i, n){
        if(a[i] <= ok){
            cout << okashi + 1 << endl;
        }
        else{
            cout << okashi << endl;
        }
    }
}