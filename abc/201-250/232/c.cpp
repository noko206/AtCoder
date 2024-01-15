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

using Graph = vector<vector<int>>;

int main(){
    int n, m;
    cin >> n >> m;
    // vector<int> a(m), b(m), c(m), d(m);
    Graph ta(n), ao(n);
    REP(i, m){
        int a, b;
        // cin >> a[i] >> b[i];
        cin >> a >> b;
        // --a[i], --b[i];
        --a, --b;
        ta[a].push_back(b);
        ta[b].push_back(a);
    }
    REP(i, m){
        // cin >> c[i] >> d[i];
        // --c[i], --d[i];
        int c, d;
        cin >> c >> d;
        --c, --d;
        ao[c].push_back(d);
        ao[d].push_back(c);
    }
    vector<int> p(n);
    REP(i, n){
        p[i] = i;
    }
    bool is_ok = true;
    do{
        // bool test = false;
        // if(p[0] == 2 && p[1] == 1 && p[2] == 0 && p[3] == 3){
        //     test = true;
        //     cout << "test" << endl;
        // }
        is_ok = true;
        REP(i, n){
            // if(test){
            //     cout << ta[i].size() << ' ' << ao[p[i]].size() << endl;
            // }
            if(ta[i].size() != ao[p[i]].size()){
                is_ok = false;
                break;
            }
            set<int> s;
            for(int v : ta[i]){
                s.insert(v);
                // if(test){
                //     cout << v << endl;
                // }
            }
            for(int v : ao[p[i]]){
                s.insert(p[v]);
                // if(test){
                //     cout << v << endl;
                // }
            }
            // if(test){
            //     cout << ta[i].size() << ' ' << s.size() << endl;
            // }
            if(ta[i].size() != s.size()){
                is_ok = false;
                break;
            }
        }
        if(is_ok){
            break;
        }
    }while(next_permutation(ALL(p)));
    if(is_ok){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}