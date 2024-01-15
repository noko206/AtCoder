#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 2e9;

int main()
{
    string n;
    bool is_return = false;
    bool is_ok = true;
    int j = 0;
    cin >> n;
    for (int i = n.length() - 1; i >= 0; i--){
        if(n[i] != '0'){
            is_return = true;
        }
        if(is_return){
            if(n[j] != n[i]){
                is_ok = false;
                break;
            }
            j++;
        }
    }
    if(is_ok){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}