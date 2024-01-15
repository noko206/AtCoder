#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, d;
	cin >> n >> d;

	vector<int> dp(n + 1);
	dp[0] = 0;

	for (int i = 1; i <= n; ++i) {
		if (i >= 2 * d + 1) {
			dp[i] = dp[i - (2 * d + 1)] + 1;
		}
		else {
			dp[i] = 1;
		}
	}

	cout << dp[n] << endl;
}