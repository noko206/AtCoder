#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;
const int INF = 2e9;

vector<vector<int>> G(2005);
vector<bool> seen;

void dfs(int v){
    // cout << "ok" << endl;
    seen[v] = true;
    for(auto next : G[v]){
        if(seen[next]){
            continue;
        }
        dfs(next);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    // vector<vector<bool>> ans(n+5);
    int ans = 0;
    for (int i = 1; i <= n; i++){
        seen.assign(n + 1, false);
        dfs(i);
        // ans[i].resize(n+5);
        for (int j = 1; j <= n; j++){
            // ans[i][j] = seen[j];
            if(seen[j]){
                ans++;
                // cout << i << ',' << j << endl;
            }
        }
    }
    cout << ans << endl;
}