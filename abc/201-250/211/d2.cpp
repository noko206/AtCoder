using namespace std;
typedef long long int lint;
typedef pair<int, lint> pil;
typedef pair<lint, int> pli;
typedef pair<lint, lint> pll;

const int N = 100100;
int n;
vector<pil> edges[N];
 
pll add(pll a, pll b) {
  if (a.first != b.first) return min(a,b);
  return pll(a.first,(a.second+b.second)%mod);
}
pll mul(pll a,pll b){
  return pll(a.first+b.first,a.second*b.second%mod);
}
 
/*
 * edges に辺の情報(終点、距離)を入れると、(sからの最短距離,最短距離の道の本数%mod)を保持する vector を返す。
 */
vector<pll> calc(int s) {
  vector<pll> dp(n, pll(inf, 0));
  vector<bool> vis(n, false);
  priority_queue<pli, vector<pli> , greater<pli> > que;
  dp[s] = pll(0, 1);
  que.push(pli(0, s));
  while (not que.empty()) {
    pli vd = que.top(); que.pop();
    int v = vd.second;
    if (vis[v]) continue;
    vis[v] = true;
    REP(i, 0, edges[v].size()) {
      pil wc = edges[v][i];
      int w = wc.first;
      lint c = wc.second;
      dp[w]=add(dp[w],mul(dp[v],pll(c,1)));
      que.push(pli(dp[w].first,w));
    }
  }
  return dp;
}

int main(){
    int m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    REP(i, m){
        int a, b;
        cin >> a >> b;
        --a, --b;
        edges[i] = make_pair(a, b);
    }
    calc(0)
}