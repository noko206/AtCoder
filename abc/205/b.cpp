#include <bits/stdc++.h>
using namespace std;

#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
using Graph = vector<vector<int>>;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;
const int INF = 1 << 29;
const long long LLINF = 1LL << 60;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x : a){
        cin >> x;
    }
    vector<bool> b(n + 1, false);
    for(auto x : a){
        b[x] = true;
    }
    bool is_ok = true;
    for (int i = 1; i <= n; i++){
        if(!b[i]){
            is_ok = false;
            break;
        }
    }
    if(is_ok){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}