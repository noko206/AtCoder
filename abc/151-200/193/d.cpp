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

int score(string str){
    int ans = 0;
    vector<int> cnt(10, 0);
    for(char c : str){
        ++cnt[c - '0'];
    }
    REP(i, 1, 10){
        ans += i * pow(10, cnt[i]);
    }
    return ans;
}

int main(){
    int k;
    string s, t;
    cin >> k >> s >> t;
    vector<int> cnt(10, 0);
    for(char c : s + t){
        if(c == '#'){
            continue;
        }
        ++cnt[c - '0'];
    }
    double ans = 0;
    REP(i, 1, 10){
        s[4] = i + '0';
        if(cnt[i] + 1 > k){
            continue;
        }
        REP(j, 1, 10){
            t[4] = j + '0';
            if(i == j){
                if(cnt[j] + 2 > k){
                    continue;
                }
            }
            else{
                if(cnt[j] + 1 > k){
                    continue;
                }
            }
            int takahashi = score(s);
            int aoki = score(t);
            if(takahashi <= aoki){
                continue;
            }
            if(i == j){
                ans += ((k - cnt[i]) / (double)(9 * k - 8)) * ((k - (cnt[j] + 1)) / (double)(9 * k - 9));
            }
            else{
                ans += ((k - cnt[i]) / (double)(9 * k - 8)) * ((k - cnt[j]) / (double)(9 * k - 9));
            }
        }
    }
    printf("%.8f\n", ans);
}