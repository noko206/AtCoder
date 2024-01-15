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
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(mp.find(a[i]) == mp.end()){
            mp[a[i]] = 1;
        }
        else{
            mp[a[i]]++;
        }
    }
    ll ans = 0;
    for (int i = 0; i < n - 1; i++){
        mp[a[i]]--;
        ans += (n - (i + 1)) - mp[a[i]];
    }
    cout << ans << endl;
}