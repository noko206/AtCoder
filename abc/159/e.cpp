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
    int h, w, K;
    cin >> h >> w >> K;
    vector<string> s(h);
    REP(i, h){
        cin >> s[i];
    }
    ll ans = LLINF;
    REP(i, 1 << (h - 1)){
        vector<int> cut;
        cut.push_back(0);
        REP(j, (h - 1)){
            if(i & 1 << j){
                cut.push_back(j + 1);
            }
        }
        cut.push_back(h);
        vector<int> cnt(cut.size(), 0);
        // cout << cut.size() << endl;
        ll cut_cnt = cut.size() - 2;
        bool is_ok = true;
        REP(j, w){
            bool is_cut = false;
            REP(k, cut.size() - 1){
                REP(l, cut[k], cut[k + 1]){
                    if(s[l][j] == '1'){
                        ++cnt[k];
                        if(cnt[k] > K){
                            is_cut = true;
                        }
                    }
                }
            }
            if(is_cut){
                ++cut_cnt;
                // cout << j << ' ';
                REP(k, cnt.size()){
                    cnt[k] = 0;
                }
                REP(k, cut.size() - 1){
                    REP(l, cut[k], cut[k + 1]){
                        if(s[l][j] == '1'){
                            ++cnt[k];
                            if(cnt[k] > K){
                                is_ok = false;
                            }
                        }
                    }
                }
            }
            if(!is_ok){
                break;
            }
        }
        // cout << endl;
        if(is_ok){
            chmin(ans, cut_cnt);
        }
        // cout << ans << endl;
    }
    cout << ans << endl;
}