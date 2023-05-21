#include <bits/stdc++.h>
using namespace std;

#define _overload3(_1,_2,_3,name,...) name
#define _REP(i,n) REPI(i,0,n)
#define REPI(i,a,b) for(int i=int(a);i<int(b);++i)
#define REP(...) _overload3(__VA_ARGS__,REPI,_REP,)(__VA_ARGS__)
#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef long double ld;
const int MOD = 1e9+7;
const int INF = 2e9;
const long long LLINF = 2e18;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
ll gcd(ll x, ll y){ return (x % y) ? gcd(y, x % y) : y; }
ll lcm(ll x, ll y){ return x / gcd(x, y) * y; }

class RangeMax {
public:
	int size_ = 1;
	vector<long long> dat;

	void init(int sz) {
		while (size_ <= sz) size_ *= 2;
		dat.resize(size_ * 2, -(1LL << 60));
	}
	void update(int pos, long long x) {
		pos += size_;
		dat[pos] = x;
		while (pos >= 2) {
			pos >>= 1;
			dat[pos] = max(dat[pos * 2], dat[pos * 2 + 1]);
		}
	}
	long long query_(int l, int r, int a, int b, int u) {
		if (l <= a && b <= r) return dat[u];
		if (r <= a || b <= l) return -(1LL << 60);
		long long v1 = query_(l, r, a, (a + b) >> 1, u * 2);
		long long v2 = query_(l, r, (a + b) >> 1, b, u * 2 + 1);
		return max(v1, v2);
	}
	long long query(int l, int r) {
		return query_(l, r, 0, size_, 1);
	}
};

const int MAX = 10005;

ll dp[505][MAX];

int main(){
    int w, n;
    cin >> w >> n;
    vector<RangeMax> seg(n + 1);
    REP(i, n + 1){
        REP(j, w + 1){
            dp[i][j] = -1;
        }
        seg[i].init(w + 1);
    }
    dp[0][0] = 0;
    seg[0].update(0, 0);
    REP(i, n){
        int l, r, v;
        cin >> l >> r >> v;
        REP(j, w + 1){
            dp[i + 1][j] = dp[i][j];
            int ql = max(0, j - r);
            int qr = max(0, j - l + 1);
            if(ql == qr){
                continue;
            }
            ll res = seg[i].query(ql, qr);
            if(res != -1){
                chmax(dp[i + 1][j], res + v);
            }
        }
        REP(j, w + 1){
            seg[i + 1].update(j, dp[i + 1][j]);
        }
    }
    // REP(i, n + 1){
    //     REP(j, w + 1){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    cout << dp[n][w] << endl;
}