#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;
const int INF = 2e9;

int h, w;
vector<string> a;
int takahashi(int, int);
int aoki(int, int);

int takahashi(int i, int j){
    if (i >= h || j >= w)
    {
        return INF;
    }
    if(i == h - 1 && j == w - 1){
        if (a[i][j] == '-')
        {
            return -1;
        }
        else if (a[i][j] == '+')
        {
            return 1;
        }
    }
    int right = aoki(i, j + 1);
    int bottom = aoki(i + 1, j);
    int ma = max(right, bottom);
    if(a[i][j] == '-'){
        ma--;
    }
    else if(a[i][j] == '+'){
        ma++;
    }
    return ma;
}

int aoki(int i, int j)
{
    if (i >= h || j >= w)
    {
        return -INF;
    }
    if (i == h - 1 && j == w - 1)
    {
        if (a[i][j] == '-')
        {
            return 1;
        }
        else if (a[i][j] == '+')
        {
            return -1;
        }
    }
    int right = takahashi(i, j + 1);
    int bottom = takahashi(i + 1, j);
    int mi = min(right, bottom);
    if (a[i][j] == '-')
    {
        mi++;
    }
    else if (a[i][j] == '+')
    {
        mi--;
    }
    return mi;
}

int main()
{
    cin >> h >> w;
    a.resize(h);
    for (int i = 0; i < h; i++){
        cin >> a[i];
    }
    if(h == 1 && w == 1){
        cout << "Draw" << endl;
        return 0;
    }
    int right = takahashi(0, 1);
    int bottom = takahashi(1, 0);
    int p = max(right, bottom);
    // cout << right << ' ' << bottom << ' ' << p << endl;
    if(p > 0){
        cout << "Takahashi" << endl;
    }
    else if(p < 0){
        cout << "Aoki" << endl;
    }
    else{
        cout << "Draw" << endl;
    }
}