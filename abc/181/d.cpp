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
    string s;
    cin >> s;
    if(s.length() == 1){
        if(s == "8"){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
        return 0;
    }
    if(s.length() == 2){
        if(stoi(s) % 8 == 0){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
        return 0;
    }
    vector<int> cnt(10, 0);
    for(char c : s){
        ++cnt[c - '0'];
    }
    int n = 104;
    while(n < 1000){
        vector<int> chk(10, 0);
        int m = n;
        while(m > 0){
            ++chk[m % 10];
            m /= 10;
        }
        bool is_ok = true;
        REP(i, 10){
            if(cnt[i] < chk[i]){
                is_ok = false;
                break;
            }
        }
        if(is_ok){
            cout << "Yes" << endl;
            return 0;
        }
        n += 8;
    }
    cout << "No" << endl;
}