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
    string s;
    cin >> s;
    vector<int> x;
    int left = 0;
    int right = n - 1;
    int pre = right;
    REP(k, 26){
        for(int i = right; i >= left; --i){
            if(s[i] == k + 'a'){
                pre = right;
                right = i - 1;
                bool is_continue = true;
                REP(j, left, right + 1){
                    if(s[j] > k + 'a'){
                        left = j + 1;
                        x.push_back(i);
                        x.push_back(j);
                        is_continue = false;
                        break;
                    }
                }
                if(is_continue){
                    left = right + 1;
                    right = pre;
                    break;
                }
            }
        }
    }
    sort(ALL(x));
    int m = x.size();
    REP(i, m / 2){
        swap(s[x[i]], s[x[(m - 1) - i]]);
    }
    cout << s << endl;
}