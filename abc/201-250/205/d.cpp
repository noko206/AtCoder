#include <bits/stdc++.h>
using namespace std;

#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
using Graph = vector<vector<int>>;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;
const int INF = 1 << 29;
const long long LLINF = 1LL << 60;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

int main(){
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    a.push_back(0);
    sort(a.begin(), a.end());
    vector<ll> k(q);
    for (int i = 0; i < q; i++)
    {
        cin >> k[i];
    } 
    vector<ll> ans;
    for(auto x : k){
        ll ng = 0;
        ll ok = n + 1;
        while(ok - ng != 1){
            ll mid = (ng + ok) / 2;
            if(a[mid] - mid >= x){
                ok = mid;
            }
            else{
                ng = mid;
            }
        }
        ans.push_back(a[ng] + x - (a[ng] - ng));
    }
    for(auto a : ans){
        cout << a << endl;
    }
}