#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;
const int INF = 2e9;

int main(){
    int n;
    cin >> n;
    vector<int> t(n);
    int s = 0;
    for(auto &x : t){
        cin >> x;
        s += x;
    }
    if(n == 1){
        cout << t[0] << endl;
        return 0;
    }
    vector<vector<bool>> dp(n + 5, vector<bool>(s, false));
    dp[0][0] = true;
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= s; j++){
            dp[i + 1][j] = dp[i][j];
            if(j >= t[i]){
                dp[i + 1][j] = dp[i + 1][j] | dp[i][j - t[i]];
            }
        }
    }
    for (int i = s / 2; i <= s; i++){
        for (int j = 0; j < n; j++){
            if(dp[j][i]){
                cout << max(i, s - i) << endl;
                return 0;
            }
        }
    }
}