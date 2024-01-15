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
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), c(n + m + 1);
    REP(i, n + 1){
        cin >> a[i];
    }
    REP(i, n + m + 1){
        cin >> c[i];
    }
    vector<int> b(m + 1);
    vector<int> tmp(n + 1);
    REP(i, n + 1){
        tmp[i] = c[n + m - i];
    }
    reverse(ALL(tmp));
    // cout << tmp[0] << ' ' << tmp[1] << endl;
    // for(int i = n + m; i >= 0; --i){
    //     if(i - n < 0) break;
    //     b[i - n] = tmp[0] / a[n];
    //     for(int j = n; j >= 0; --j){
    //         if(j == 0){
    //             tmp[0] = c[i - (n + 1)];
    //             cout << tmp[0] << ' ';
    //         }
    //         else{
    //             tmp[j] = tmp[j - 1] - (b[i - n] * a[j - 1]);
    //             cout << tmp[j] << ' ';
    //         }
    //     }
    //     cout << endl;
    // }
    // reverse(ALL(b));
    // REP(i, m + 1){
    //     cout << b[i] << ' ';
    // }
    // cout << endl;
    // cout << tmp[0] << ' ' << tmp[1] << endl;
    for(int i = m; i >= 0; --i){
        b[i] = tmp[n] / a[n];
        for(int j = n; j >= 0; --j){
            if(j == 0){
                tmp[0] = c[i - 1];
            }
            else {
                tmp[j] = tmp[j - 1] - (b[i] * a[j - 1]);
            }
        }
    }
    REP(i, m + 1){
        cout << b[i] << ' ';
    }
    cout << endl;
}