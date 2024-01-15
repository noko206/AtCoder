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

struct TRAIN{
    int prev;
    int next;
};

int main(){
    int n, q;
    cin >> n >> q;
    vector<TRAIN> t(n + 1);
    REP(i, n + 1){
        t[i].prev = -1;
        t[i].next = -1;
    }
    REP(i, q){
        int k, x, y;
        cin >> k;
        vector<int> ans;
        switch(k){
            case 1:
                cin >> x >> y;
                t[x].next = y;
                t[y].prev = x;
                break;
            case 2:
                cin >> x >> y;
                t[x].next = -1;
                t[y].prev = -1;
                break;
            case 3:
                cin >> x;
                TRAIN now = t[x];
                if(now.prev == -1 && now.next == -1){
                    cout << 1 << ' ' << x << endl;
                    break;
                }
                while(now.prev != -1){
                    now = t[now.prev];
                }
                now = t[now.next];
                while(true){
                    ans.push_back(now.prev);
                    // cout << now.prev << ' ';
                    if(now.next == -1){
                        break;
                    }
                    now = t[now.next];
                }
                now = t[now.prev];
                ans.push_back(now.next);
                // cout << now.next << endl;
                cout << ans.size() << ' ';
                for(int a : ans){
                    cout << a << ' ';
                }
                cout << endl;
                break;
        }
    }
}