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
    vector<int> a(n);
    int g = -1;
    REP(i, n){
        cin >> a[i];
        if(i == 0) g = a[0];
        else g = gcd(g, a[i]);
    }
    bool is_setwise_coprime = false;
    if(g == 1){
        is_setwise_coprime = true;
    }
    vector<vector<int>> sieve(1001001);
    REP(i, 2, 1000001){
        int tmp = i;
        if(sieve[tmp].size() > 0) continue;
        while(tmp <= 1000000){
            sieve[tmp].push_back(i);
            tmp += i;
        }
    }

    bool is_pairwise_coprime = true;
    map<int, int> mp;
    REP(i, n){
        // cout << a[i] << ':' << endl;
        for(int tmp : sieve[a[i]]){
            // cout << tmp << endl;
            if(mp.find(tmp) != mp.end()){
                is_pairwise_coprime = false;
                break;
            }
            ++mp[tmp];
        }
        if(!is_pairwise_coprime){
            break;
        }
    }
    if(is_pairwise_coprime){
        cout << "pairwise coprime" << endl;
    }
    else if(is_setwise_coprime){
        cout << "setwise coprime" << endl;
    }
    else{
        cout << "not coprime" << endl;
    }
}