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
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    vector<pair<int, int>> s, t;
    s.push_back({x1 + 1, y1 + 2});
    s.push_back({x1 + 2, y1 + 1});
    s.push_back({x1 + 2, y1 - 1});
    s.push_back({x1 + 1, y1 - 2});
    s.push_back({x1 - 1, y1 - 2});
    s.push_back({x1 - 2, y1 - 1});
    s.push_back({x1 - 2, y1 + 1});
    s.push_back({x1 - 1, y1 + 2});
    
    t.push_back({x2 + 1, y2 + 2});
    t.push_back({x2 + 2, y2 + 1});
    t.push_back({x2 + 2, y2 - 1});
    t.push_back({x2 + 1, y2 - 2});
    t.push_back({x2 - 1, y2 - 2});
    t.push_back({x2 - 2, y2 - 1});
    t.push_back({x2 - 2, y2 + 1});
    t.push_back({x2 - 1, y2 + 2});

    bool is_ok = false;
    REP(i, s.size()){
        REP(j, t.size()){
            if(s[i].first == t[j].first && s[i].second == t[j].second){
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