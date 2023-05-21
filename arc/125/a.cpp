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
    int n, m;
    cin >> n >> m;
    vector<int> s(n);
    REP(i, n){
        cin >> s[i];
    }
    int pos = n;
    int dif = 0;
    int ans = 0;
    REP(i, m){
        int t;
        cin >> t;
        if(ans == -1){
            continue;
        }
        if(t == s[pos % n]){
            // cout << "itti" << endl;
            ++ans;
            continue;
        }
        if(dif == 0){
            while(true){
                ++dif;
                ++ans;
                // cout << "idou" << endl;
                if(pos - dif == -1){
                    ans = -1;
                    break;
                }
                if(t == s[(pos + dif) % n]){
                    // cout << "+itti" << endl;
                    pos += dif;
                    dif = -1;
                    ++ans;
                    break;
                }
                else if(t == s[(pos - dif) % n]){
                    // cout << "-itti" << endl;
                    pos -= dif;
                    dif = 1;
                    ++ans;
                    break;
                }
            }
        }
        else{
            pos += dif;
            dif *= -1;
            ans += 2;
            // cout << "2tti" << endl;
        }
    }
    cout << ans << endl;
}