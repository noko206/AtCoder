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

// N<=8
// int main(){
//     int n;
//     cin >> n;
//     vector<int> d(n), c(n), s(n);
//     REP(i, n){
//         cin >> d[i] >> c[i] >> s[i];
//     }
//     vector<int> p(n);
//     REP(i, n){
//         p[i] = i;
//     }
//     ll ans = 0;
//     do{
//         int now = 1;
//         ll cnt = 0;
//         REP(i, n){
//             int j = p[i];
//             if(now + c[j] - 1 <= d[j]){
//                 cnt += s[j];
//                 now += c[j];
//             }
//         }
//         chmax(ans, cnt);
//     }while(next_permutation(ALL(p)));
//     cout << ans << endl;
// }

// N<=20
// int main(){
//     int n;
//     cin >> n;
//     vector<int> d(n), c(n), s(n);
//     REP(i, n){
//         cin >> d[i] >> c[i] >> s[i];
//     }
//     ll ans = 0;
//     REP(bit, 1 << n){
//         vector<int> arr;
//         REP(i, n){
//             if(bit & (1 << i)){
//                 arr.push_back(i);
//             }
//         }
//         int m = arr.size();
//         vector<pair<int, int>> p(m);
//         REP(i, m){
//             p[i] = {d[arr[i]], arr[i]};
//         }
//         sort(ALL(p));
//         ll cnt = 0;
//         int now = 1;
//         REP(i, m){
//             int j = p[i].second;
//             if(now + c[j] - 1 <= d[j]){
//                 cnt += s[j];
//                 now += c[j];
//             }
//             else{
//                 cnt = 0;
//                 break;
//             }
//         }
//         chmax(ans, cnt);
//     }
//     cout << ans << endl;
// }

ll dp[5005][5005];

int main(){
    int n;
    cin >> n;
    vector<int> d(n), c(n), s(n);
    vector<pair<int, int>> p(n);
    REP(i, n){
        cin >> d[i] >> c[i] >> s[i];
        p[i] = {d[i], i};
    }
    sort(ALL(p));
    REP(i, n){
        int k = p[i].second;
        REP(j, 5001){
            if(c[k] > j || d[k] < j){
                dp[i + 1][j] = dp[i][j];
            }
            else{
                dp[i + 1][j] = max(dp[i][j], dp[i][j - c[k]] + s[k]);
            }
        }
    }
    cout << *max_element(dp[n], dp[n] + 5001) << endl;
}