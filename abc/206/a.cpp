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
    double n;
    cin >> n;
    int m = (int)(1.08 * n);
    if(206 > m){
        cout << "Yay!" << endl;
    }
    else if(206 == m){
        cout << "so-so" << endl;
    }
    else{
        cout << ":(" << endl;
    }
}