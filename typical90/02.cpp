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

int main(){
    int n;
    cin >> n;
    if(n % 2 == 1){
        return 0;
    }
    vector<string> ans;
    string str = "";
    REP(i, n){
        str += "(";
    }
    REP(bit, 1 << n){
        vector<int> _enum;
        REP(i, n){
            if(bit & (1 << i)){
                _enum.push_back(i);
            }
        }
        string tmp = str;
        for(int _e : _enum){
            tmp[_e] = ')';
        }
        int cnt = 0;
        // cout << tmp << endl;
        REP(i, n){
            if(tmp[i] == '('){
                ++cnt;
            }
            else{
                --cnt;
            }
            if(cnt < 0){
                break;
            }
        }
        if(cnt == 0){
            ans.push_back(tmp);
        }
    }
    sort(ALL(ans));
    for(string a : ans){
        cout << a << endl;
    }
}