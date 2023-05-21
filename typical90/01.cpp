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
    int n, l, k;
    cin >> n >> l >> k;
    vector<int> a(n);
    REP(i, n){
        cin >> a[i];
    }
    // 答えがm以上か
    int ok = -1;
    int ng = l;
    while(ng - ok != 1){
        int mid = (ok + ng) / 2;
        int k_cnt = 0;
        int m_cnt = 0;
        REP(i, n){
            if(i == 0){
                m_cnt = a[i];
            }
            else{
                m_cnt += a[i] - a[i - 1];
            }
            if(m_cnt >= mid){
                ++k_cnt;
                m_cnt = 0;
            }
        }
        if(k_cnt > k || (k_cnt == k && m_cnt + (l - a[n - 1]) >= mid)){
            ok = mid;
            // cout << "ok:" << mid << endl;
        }
        else{
            ng = mid;
            // cout << "ng:" << mid << endl;
        }
    }
    cout << ok << endl;
}