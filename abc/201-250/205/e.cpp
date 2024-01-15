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

int ans;
int cnt = 0;
int n, m, k;

void dfs(int w, int b){
    // cout << ++cnt % MOD << endl;
    if (w > b + k && !(w == 0 && b == 0)){
        return;
    }
    if(w + b == n + m){
        // cout << w << ' ' << b << endl;
        ans++;
        ans %= MOD;
        return;
    }
    if(w < n){
        dfs(w + 1, b);
    }
    if(b < m){
        dfs(w, b + 1);
    }
}

int main(){
    cin >> n >> m >> k;
    ans = 0;
    dfs(0, 0);
    cout << ans << endl;
}