#include <iostream>
#include <vector>
#include <map>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

long long nCk(int n, int k) {
  long long x = 1; // n!の初期値
  long long y = 1; // (n-k)!の初期値
  long long z = 1; // k!の初期値

  rep(i, n) x *= n - i; // n!を計算
  rep(i, n - k) y *= n - k - i; // (n-k)!を計算
  rep(i, k) z *= k - i; // k!を計算

  return (x / (y * z)); // 定義通りに計算
}

int main()
{
  int N;
  cin >> N;

  int a;
  map<int, int> map_num;
  for (long long i=0; i<N; i++) {
    cin >> a;
    map_num[a]++;
  }

  map<int, int> map_cnt;
  for (pair<int, int> p : map_num) {
	  int num = p.first;
	  int cnt = p.second;
    if (cnt == 1) continue;
    map_cnt[cnt]++;
  }

  long long ans = nCk(N, 3);
  for (pair<int, int> p : map_cnt) {
	  int num_cnt = p.first;
	  int cnt = p.second;
    long long sub_2 = nCk(num_cnt, 2) * (long long) (N-num_cnt);
    ans -= sub_2 * cnt;
    if (num_cnt > 2) {
      long long sub_3 = nCk(num_cnt, 3);
      ans -= sub_3 * cnt;
    }
  }

  cout << ans << endl;
}