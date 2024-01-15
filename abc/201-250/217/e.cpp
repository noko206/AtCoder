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

vector<int> a;

void my_sort(int sort_num){
    vector<int> unsort;
    int n = a.size();
    REP(i, sort_num, n){
        unsort.push_back(a[i]);
    }
    a.erase(a.begin() + sort_num, a.end());
    for(int v : unsort){
        int ok = a.size();
        int ng = -1;
        while(ok - ng > 1){
            int mid = (ok + ng) / 2;
            if(a[mid] > v){
                ok = mid;
            }
            else{
                ng = mid;
            }
        }
        a.insert(a.begin() + ok, v);
    }
}

int main(){
    int q;
    cin >> q;
    vector<int> ans;
    int sort_num = 0;
    REP(i, q){
        int query, x;
        cin >> query;
        switch(query){
            case 1:
                cin >> x;
                a.push_back(x);
                break;
            case 2:
                ans.push_back(a[0]);
                a.erase(a.begin());
                sort_num = max(sort_num - 1, 0);
                break;
            case 3:
                my_sort(sort_num);
                sort_num = a.size();
                break;
        }
    }
    for(int an : ans){
        cout << an << endl;
    }
}