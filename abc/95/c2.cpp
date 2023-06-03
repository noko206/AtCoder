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
struct Init { Init() { ios::sync_with_stdio(0); cin.tie(0); }} init;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
template<class T, class... Ts> void output(const T& a, const Ts&... b) { cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }
template<class T> void output(vector<T> v) { for (auto u : v) cout << u << ' '; cout << '\n'; };
void yesno(bool is_ok) { cout << (is_ok ? "yes" : "no") << '\n'; }
void YesNo(bool is_ok) { cout << (is_ok ? "Yes" : "No") << '\n'; }
void YESNO(bool is_ok) { cout << (is_ok ? "YES" : "NO") << '\n'; }

/**
 * @brief Binary-Trie
 * @docs docs/binary-trie.md
 */
template< typename T, int MAX_LOG, typename D = int >
struct BinaryTrie {
public:
  struct Node {
    Node *nxt[2];
    D exist;
    vector< int > accept;

    Node() : nxt{nullptr, nullptr}, exist(0) {}
  };

  Node *root;

  explicit BinaryTrie() : root(new Node()) {}

  explicit BinaryTrie(Node *root) : root(root) {}

  void add(const T &bit, int idx = -1, D delta = 1, T xor_val = 0) {
    root = add(root, bit, idx, MAX_LOG, delta, xor_val);
  }

  void erase(const T &bit, T xor_val = 0) {
    add(bit, -1, -1, xor_val);
  }

  Node *find(const T &bit, T xor_val = 0) {
    return find(root, bit, MAX_LOG, xor_val);
  }

  D count(const T &bit, T xor_val = 0) {
    auto node = find(bit, xor_val);
    return node ? node->exist : 0;
  }

  pair< T, Node * > min_element(T xor_val = 0) {
    assert(root->exist > 0);
    return kth_element(0, xor_val);
  }

  pair< T, Node * > max_element(T xor_val = 0) {
    assert(root->exist > 0);
    return kth_element(root->exist - 1, xor_val);
  }

  pair< T, Node * > kth_element(D k, T xor_val = 0) { // 0-indexed
    assert(0 <= k && k < root->exist);
    return kth_element(root, k, MAX_LOG, xor_val);
  }

  D count_less(const T &bit, T xor_val = 0) { // < bit
    return count_less(root, bit, MAX_LOG, xor_val);
  }

private:

  virtual Node *clone(Node *t) { return t; }

  Node *add(Node *t, T bit, int idx, int depth, D x, T xor_val, bool need = true) {
    if(need) t = clone(t);
    if(depth == -1) {
      t->exist += x;
      if(idx >= 0) t->accept.emplace_back(idx);
    } else {
      bool f = (xor_val >> depth) & 1;
      auto &to = t->nxt[f ^ ((bit >> depth) & 1)];
      if(!to) to = new Node(), need = false;
      to = add(to, bit, idx, depth - 1, x, xor_val, need);
      t->exist += x;
    }
    return t;
  }

  Node *find(Node *t, T bit, int depth, T xor_val) {
    if(depth == -1) {
      return t;
    } else {
      bool f = (xor_val >> depth) & 1;
      auto &to = t->nxt[f ^ ((bit >> depth) & 1)];
      return to ? find(to, bit, depth - 1, xor_val) : nullptr;
    }
  }

  pair< T, Node * > kth_element(Node *t, D k, int bit_index, T xor_val) { // 0-indexed
    if(bit_index == -1) {
      return {0, t};
    } else {
      bool f = (xor_val >> bit_index) & 1;
      if((t->nxt[f] ? t->nxt[f]->exist : 0) <= k) {
        auto ret = kth_element(t->nxt[f ^ 1], k - (t->nxt[f] ? t->nxt[f]->exist : 0), bit_index - 1, xor_val);
        ret.first |= T(1) << bit_index;
        return ret;
      } else {
        return kth_element(t->nxt[f], k, bit_index - 1, xor_val);
      }
    }
  }

  D count_less(Node *t, const T &bit, int bit_index, T xor_val) {
    if(bit_index == -1) return 0;
    D ret = 0;
    bool f = (xor_val >> bit_index) & 1;
    if((bit >> bit_index & 1) and t->nxt[f]) ret += t->nxt[f]->exist;
    if(t->nxt[f ^ (bit >> bit_index & 1)]) ret += count_less(t->nxt[f ^ (bit >> bit_index & 1)], bit, bit_index - 1, xor_val);
    return ret;
  }
};

int main(){
	int n;
	cin >> n;
	vector<int> x(n);
	REP(i, n) cin >> x[i];
	vector<int> y = x;
	sort(ALL(y));
	vector<int> decompress;
	REP(i, n) if(i == 0 || y[i] != y[i - 1]) decompress.push_back(y[i]);
	map<int, int> compress;
	REP(i, decompress.size()){
		compress[decompress[i]] = i;
	}
	BinaryTrie<int, 200000> bt;
	REP(i, n) bt.add(x[i] = compress[x[i]]);
	vector<int> ans(n);
	int m = n / 2 - 1;
	REP(i, n){
		bt.erase(x[i]);
		ans[i] = decompress[bt.kth_element(m)];
		bt.add(x[i]);
	}
	output(ans);
}