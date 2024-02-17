// clang-format off
#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif

#define _overload3(_1,_2,_3,name,...) name
#define _REP(i,n) REPI(i,0,n)
#define REPI(i,a,b) for(int i=int(a);i<int(b);++i)
#define REP(...) _overload3(__VA_ARGS__,REPI,_REP,)(__VA_ARGS__)
#define _RREP(i,n) RREPI(i,n,0)
#define RREPI(i,a,b) for(int i=int(a);i>=int(b);--i)
#define RREP(...) _overload3(__VA_ARGS__,RREPI,_RREP,)(__VA_ARGS__)
#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
typedef long long ll;
const int INF32 = 1001001001;
const long long INF64 = 1001001001001001001;
struct Init { Init() { ios::sync_with_stdio(0); cin.tie(0); cout << setprecision(15); }} init;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
template<class T> T gcd(T x, T y){ return (x % y) ? gcd(y, x % y) : y; }
template<class T> T lcm(T x, T y){ return x / gcd(x, y) * y; }
template<class T, class... Ts> void output(const T& a, const Ts&... b) { cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }
template<class T> void output(vector<T> v) { for (auto u : v) cout << u << ' '; cout << '\n'; };
void yesno(bool is_ok) { cout << (is_ok ? "yes" : "no") << '\n'; }
void YesNo(bool is_ok) { cout << (is_ok ? "Yes" : "No") << '\n'; }
void YESNO(bool is_ok) { cout << (is_ok ? "YES" : "NO") << '\n'; }

// clang-format on
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

template <class T> struct Imos2d {
   public:
    Imos2d(int h, int w) : h(h), w(w), data(h + 1, vector<T>(w + 1, 0)){};

    // [si, gi), [sj, gj)
    void add(int si, int sj, int gi, int gj, T x) {
        assert(0 <= si && si <= gi && gi <= h);
        assert(0 <= sj && sj <= gj && gj <= w);
        data[si][sj] += x;
        data[si][gj] -= x;
        data[gi][sj] -= x;
        data[gi][gj] += x;
    }

    void build() {
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                data[i + 1][j] += data[i][j];
            }
        }
        for (int j = 0; j < w; ++j) {
            for (int i = 0; i < h; ++i) {
                data[i][j + 1] += data[i][j];
            }
        }
    }

    T get(int i, int j) {
        assert(0 <= i && i < h);
        assert(0 <= j && j < w);
        return data[i][j];
    }

   private:
    int h, w;
    vector<vector<T>> data;
};

template <typename T> unordered_map<T, int> compress(vector<T> &a) {
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    unordered_map<T, int> comp;
    for (int i = 0; i < (int)a.size(); ++i) {
        comp[a[i]] = i;
    }
    return comp;
}

int _x1[1000], _y1[1000], _x2[1000], _y2[1000];

int main() {
    int w, h;
    cin >> w >> h;
    int n;
    cin >> n;
    vector<int> x, y;
    REP(i, n) {
        cin >> _x1[i] >> _y1[i] >> _x2[i] >> _y2[i];
        x.push_back(_x1[i]);
        x.push_back(_x2[i]);
        y.push_back(_y1[i]);
        y.push_back(_y2[i]);
        if (_x2[i] + 1 <= w) x.push_back(_x2[i] + 1);
        if (_y2[i] + 1 <= h) y.push_back(_y2[i] + 1);
    }
    x.push_back(0);
    x.push_back(w);
    y.push_back(0);
    y.push_back(h);
    auto compX = compress(x);
    auto compY = compress(y);
    h = compY.size() - 1;
    w = compX.size() - 1;
    Imos2d<int> imos(h, w);
    REP(i, n) {
        imos.add(compY[_y1[i]], compX[_x1[i]], compY[_y2[i]], compX[_x2[i]], 1);
    }
    imos.build();
    vector seen(h, vector<bool>(w, false));
    REP(i, h) REP(j, w) if (imos.get(i, j) > 0) seen[i][j] = true;
    int ans = 0;
    REP(i, h) {
        REP(j, w) {
            if (seen[i][j]) continue;
            ++ans;
            queue<pair<int, int>> q;
            q.push({i, j});
            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();
                REP(k, 4) {
                    int ni = r + dy[k];
                    int nj = c + dx[k];
                    if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
                    if (seen[ni][nj]) continue;
                    seen[ni][nj] = true;
                    q.push({ni, nj});
                }
            }
        }
    }
    output(ans);
}
