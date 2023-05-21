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
    vector<string> s(n);
    REP(i, n){
        cin >> s[i];
    }
    // 横
    bool is_ok = false;
    REP(i, n){
        int cnt = 0;
        REP(j, 6){
            if(s[i][j] == '#'){
                ++cnt;
            }
        }
        if(cnt >= 4){
            is_ok = true;
        }
        REP(j, 6, n){
            if(s[i][j] == '#'){
                ++cnt;
            }
            if(s[i][j - 6] == '#'){
                --cnt;
            }
            if(cnt >= 4){
                is_ok = true;
            }
        }
    }
    // 縦
    REP(i, n){
        int cnt = 0;
        REP(j, 6){
            if(s[j][i] == '#'){
                ++cnt;
            }
        }
        if(cnt >= 4){
            is_ok = true;
        }
        REP(j, 6, n){
            if(s[j][i] == '#'){
                ++cnt;
            }
            if(s[j - 6][i] == '#'){
                --cnt;
            }
            if(cnt >= 4){
                is_ok = true;
            }
        }
    }
    // 右上方向
    REP(i, 5, n){
        int cnt = 0;
        REP(j, 6){
            if(s[i - j][j] == '#'){
                ++cnt;
            }
        }
        if(cnt >= 4){
            is_ok = true;
        }
        REP(j, 6, n){
            if(i - j < 0) break;
            if(s[i - j][j] == '#'){
                ++cnt;
            }
            if(s[i - j + 6][j - 6] == '#'){
                --cnt;
            }
            if(cnt >= 4){
                is_ok = true;
            }
        }
    }
    // 右上方向2
    REP(i, n - 5){
        int cnt = 0;
        REP(j, 6){
            if(s[n - 1 - j][i + j] == '#'){
                ++cnt;
            }
        }
        if(cnt >= 4){
            is_ok = true;
        }
        REP(j, 6, n){
            if(n - 1 - j < 0 || i + j >= n) break;
            if(s[n - 1 - j][i + j] == '#'){
                ++cnt;
            }
            if(s[n - 1 - j + 6][i + j - 6] == '#'){
                --cnt;
            }
            if(cnt >= 4){
                is_ok = true;
            }
        }
    }
    // 右下方向
    REP(i, n - 5){
        int cnt = 0;
        REP(j, 6){
            if(s[i + j][j] == '#'){
                ++cnt;
            }
        }
        if(cnt >= 4){
            is_ok = true;
        }
        REP(j, 6, n){
            if(i + j >= n) break;
            if(s[i + j][j] == '#'){
                ++cnt;
            }
            if(s[i + j - 6][j - 6] == '#'){
                --cnt;
            }
            if(cnt >= 4){
                is_ok = true;
            }
        }
    }
    // 右下方向2
    REP(i, n - 5){
        int cnt = 0;
        REP(j, 6){
            if(s[j][i + j] == '#'){
                ++cnt;
            }
        }
        if(cnt >= 4){
            is_ok = true;
        }
        REP(j, 6, n){
            if(i + j >= n) break;
            if(s[j][i + j] == '#'){
                ++cnt;
            }
            if(s[j - 6][i + j - 6] == '#'){
                --cnt;
            }
            if(cnt >= 4){
                is_ok = true;
            }
        }
    }
    if(is_ok){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}