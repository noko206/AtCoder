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

int n;
bool is_ok = true;
vector<char> ans;

bool dfs2(const vector<string> &s, vector<int> val, int v){
    if(v == n) return true;
    
    // 前者を-1
    bool front = --val[s[v][0] - 'A'] >= 0;

    // 後者を-1
    bool back = --val[s[v][1] - 'A'] >= 0;

    return front || back;
}

void dfs(const vector<string> &s, vector<int> val, int v = 0){
    if(v == n) return;

    // 前者を-1
    bool front = --val[s[v][0] - 'A'] >= 0;
    if(front){
        ++val[s[v][1] - 'A'];
        if(dfs2(s, val, v + 1)){
            ans.push_back(s[v][1]);
            dfs(s, val, v + 1);
        }
        else{
            --val[s[v][1] - 'A'];
            front = false;
        }
    }
    
    if(front) return;
    ++val[s[v][0] - 'A'];
    // 後者を-1
    bool back = --val[s[v][1] - 'A'] >= 0;
    if(back){
        ++val[s[v][0] - 'A'];
        if(dfs2(s, val, v + 1)){
            ans.push_back(s[v][0]);
            dfs(s, val, v + 1);
        }
        else{
            --val[s[v][0] - 'A'];
            back = false;
        }
    }

    if(back) return;

    is_ok = false;
}

int main(){
    cin >> n;
    vector<int> val(3);
    REP(i, 3){
        cin >> val[i];
    }
    vector<string> s(n);
    REP(i, n){
        cin >> s[i];
    }
    dfs(s, val);

    if(is_ok){
        cout << "Yes" << endl;
        for(char a : ans){
            cout << a << endl;
        }
    }
    else{
        cout << "No" << endl;
    }
}