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

vector<string> to_comp(const vector<string> x, int n){
    int i_min, i_max, j_min, j_max;
    i_min = j_min = INF;
    i_max = j_max = 0;
    REP(i, n){
        REP(j, n){
            if(x[i][j] == '#'){
                chmin(i_min, i);
                chmax(i_max, i);
                chmin(j_min, j);
                chmax(j_max, j);
            }
        }
    }
    vector<string> ans(i_max - i_min + 1, "");
    int cnt = 0;
    for (int i = i_min; i <= i_max; ++i){
        for (int j = j_min; j <= j_max; ++j){
            ans[cnt] += x[i][j];
        }
        ++cnt;
    }
    return ans;
}

// xそのまま、y回転
bool _is_same(vector<string> x, vector<string> y){
    bool is_ok = false;
    REP(r, 4){
        if(r % 2 == 0){
            if(x.size() != y.size() || x[0].length() != y[0].length()){
                // cout << r << "size" << endl;
                continue;
            }
        }
        else{
            if(x.size() != y[0].length() || x[0].length() != y.size()){
                // cout << r << "size" << endl;
                continue;
            }
        }
        int h = x.size();
        int w = x[0].length();
        bool flg = true;
        REP(i, h){
            REP(j, w){
                int yi, yj;
                switch(r){
                    case 0:
                        yi = i;
                        yj = j;
                        break;
                    case 1:
                        yi = j;
                        yj = (h - 1) - i;
                        break;
                    case 2:
                        yi = (h - 1) - i;
                        yj = (w - 1) - j;
                        break;
                    case 3:
                        yi = (w - 1) - j;
                        yj = i;
                        break;
                }
                // cout << yj << endl;
                // cout << x[i][j] << ", " << y[yi][yj] << endl;
                if(x[i][j] != y[yi][yj]){
                    flg = false;
                    break;
                }
            }
            if(!flg){
                break;
            }
        }
        if(flg){
            is_ok = true;
            break;
        }
    }
    return is_ok;
}

int main(){
    int n;
    cin >> n;
    vector<string> s(n), t(n);
    REP(i, n){
        cin >> s[i];
    }
    REP(i, n){
        cin >> t[i];
    }
    vector<string> sc, tc;
    sc = to_comp(s, n);
    tc = to_comp(t, n);
    if(_is_same(sc, tc)){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}