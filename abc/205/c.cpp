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
    int a, b, c;
    cin >> a >> b >> c;
    if(a == b){
        cout << '=' << endl;
        return 0;
    }
    if(c % 2 == 0){
        if(abs(a) == abs(b)){
            cout << '=' << endl;
        }
        else if(abs(a) < abs(b)){
            cout << '<' << endl;
        }
        else{
            cout << '>' << endl;
        }
    }
    else{
        if(a >= 0 && b >= 0){
            if(a < b){
                cout << '<' << endl;
            }
            else{
                cout << '>' << endl;
            }
        }
        else if(a >= 0 && b < 0){
            cout << '>' << endl;
        }
        else if(a < 0 && b >= 0){
            cout << '<' << endl;
        }
        else{
            if(a < b){
                cout << '>' << endl;
            }
            else{
                cout << '<' << endl;
            }
        }
    }
}