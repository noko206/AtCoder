#include <iostream>
#include <vector>
using namespace std;
const long long mod = 998244353;

int main()
{
  int N, M, K;
  cin >> N >> M >> K;

  // S（左：閉区間、右：開区間）
  vector<vector<long long>> dp(N+1, vector<long long>(K+1)), S(N+1, vector<long long>(K+1));

  dp[0][0] = 1;

  for (int i=0; i<N; i++) {
    for (int j=1; j<=K; j++) {
      S[i][j] = S[i][j-1] + dp[i][j-1];
      S[i][j] %= mod;

      if (j-M > 0) {
        dp[i+1][j] = S[i][j] - S[i][j-M];
      } else {
        dp[i+1][j] = S[i][j] - S[i][0];
      }
      dp[i+1][j] += mod; // 追加しました！
      dp[i+1][j] %= mod;
    }
  }

  long long ans = 0;
  for (int j=0; j<=K; j++) {
    ans += dp[N][j];
    ans %= mod;
  }

  cout << ans << endl;
}