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

int is_win(char a, char b){
    map<char, int> j;
    j['G'] = 0;
    j['C'] = 1;
    j['P'] = 2;
    int x, y;
    x = j[a] + 3;
    y = j[b] + 3;
    if((x + 1) % 3 == y % 3){
        return 1;
    }
    else if(x % 3 == (y + 1) % 3){
        return 0;
    }
    else if(x % 3 == y % 3){
        return 2;
    }
    else{
        return -1;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<string> a(2 * n);
    vector<pair<int, int>> res(2 * n);
    REP(i, 2 * n){
        cin >> a[i];
        res[i] = make_pair(0, i);
    }
    REP(i, m){
        REP(j, n){
            char x = a[res[2 * j].second][i];
            char y = a[res[2 * j + 1].second][i];
            switch(is_win(x, y)){
                case 1:
                    --res[2 * j].first;
                    // cout << 2 * j << endl;
                    break;
                case 0:
                    --res[2 * j + 1].first;
                    // cout << 2 * j + 1 << endl;
                    break;
                case 2:
                    // cout << "drow" << endl;
                    break;
                case -1:
                    // cout << "error" << endl;
                    break;
            }
        }
        sort(ALL(res));
    }
    REP(i, 2 * n){
        cout << res[i].second + 1 << endl;
    }
}