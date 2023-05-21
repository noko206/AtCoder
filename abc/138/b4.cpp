#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, d;
	cin >> n >> d;

	vector<int> st(n);

	for (int i = 0; i < n; ++i) {
		int tot = 0;
		for (int j = max(i - d, 0); j <= min(i + d, n - 1); ++j) {
			tot |= 1 << j;
		}
		st[i] = tot;
	}

	int ans = n;
	for (int bit = 0; bit < (1 << n); ++bit) {
		int parity = 0;
		for (int i = 0; i < n; ++i) {
			if (bit & (1 << i)) {
				parity |= st[i];
			}
		}
		if (__builtin_popcount(parity) == n) {
			ans = min(ans, __builtin_popcount(bit));
		}
	}

	cout << ans << endl;
}