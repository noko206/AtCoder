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
    int n, q;
    cin >> n >> q;
    vector<multiset<int>> rate(2e5 + 1);
    multiset<int> max_rate;

    auto get_max_from_rate = [&](int i){
        if(rate[i].size() == 0) return -1;
        return *rate[i].rbegin();
    };
    auto insert_max_rate = [&](int i){
        int x = get_max_from_rate(i);
        if(x == -1) return;
        max_rate.insert(x);
    };
    auto delete_max_rate = [&](int i){
        int x = get_max_from_rate(i);
        if(x == -1) return;
        max_rate.erase(max_rate.find(x));
    };
    auto insert_rate = [&](int i, int x){
        delete_max_rate(i);
        rate[i].insert(x);
        insert_max_rate(i);
    };
    auto delete_rate = [&](int i, int x){
        delete_max_rate(i);
        rate[i].erase(rate[i].find(x));
        insert_max_rate(i);
    };

    vector<int> a(n), b(n);
    REP(i, n){
        cin >> a[i] >> b[i];
        insert_rate(b[i], a[i]);
    }

    vector<int> ans(q);
    REP(i, q){
        int c, d;
        cin >> c >> d;
        --c;
        delete_rate(b[c], a[c]);
        b[c] = d;
        insert_rate(b[c], a[c]);
        ans[i] = *max_rate.begin();
    }
    REP(i, q){
        printf("%d\n", ans[i]);
    }
}