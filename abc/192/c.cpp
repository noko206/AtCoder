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

int f(int a){
    string g_1, g_2;
    g_1 = g_2 = to_string(a);
    sort(ALLR(g_1));
    sort(ALL(g_2));
    return stoi(g_1) - stoi(g_2);
}

int main(){
    int n, k;
    cin >> n >> k;
    int a = n;
    REP(i, k){
        a = f(a);
    }
    cout << a << endl;
}