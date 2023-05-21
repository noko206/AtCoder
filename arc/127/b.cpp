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

string to_three(int s){
    string ans = "";
    while(s > 0){
        ans = to_string(s % 3) + ans;
        s /= 3;
    }
    return ans;
}

string slide(string str){
    string ans = "";
    char to[] = {'1', '2', '0'};
    REP(i, str.length()){
        ans += to[str[i] - '0'];
    }
    return ans;
}

int main(){
    int n, l;
    cin >> n >> l;
    int base = 2 * pow(3, l - 1);
    REP(i, n){
        int s = base + i;
        string str = to_three(s);
        cout << str << endl;
        str = slide(str);
        cout << str << endl;
        str = slide(str);
        cout << str << endl;
    }
}