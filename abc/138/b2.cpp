#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, d;
	cin >> n >> d;

	int ans = n;
	for (int bit = 0; bit < (1 << n); ++bit) {
		vector<bool> is_monitored(n, false);
		for (int i = 0; i < n; ++i) {
			if (bit & (1 << i)) {
				for (int j = max(i - d, 0); j <= min(i + d, n - 1); ++j) {
					is_monitored[j] = true;
				}
			}
		}
		bool is_ok = true;
		for (int i = 0; i < n; ++i) {
			if (!is_monitored[i]) {
				is_ok = false;
			}
		}
		if (is_ok) {
			ans = min(ans, __builtin_popcount(bit));
		}
	}

	cout << ans << endl;
}