#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;
const int INF = 2e9;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    vector<vector<int>> p(h);
    for (int i = 0; i < h; i++){
        cin >> a[i];
        p[i].resize(w);
    }
    if(h == 1 && w == 1){
        cout << "Draw" << endl;
        return 0;
    }
    int i = h - 1;
    int j = w - 1;
    bool is_takahashi = (h + w) % 2;
    while(i + j != 0){
        int y = i;
        int x = j;
        while (y >= 0 && x < w){
            if(is_takahashi){
                if(y == h - 1 && x == w - 1){
                    if (a[y][x] == '+')
                    {
                        p[y][x] = 1;
                    }
                    else
                    {
                        p[y][x] = -1;
                    }
                }
                else{
                    int right = -INF;
                    int bottom = -INF;
                    if (x + 1 < w)
                    {
                        right = p[y][x + 1];
                    }
                    if (y + 1 < h)
                    {
                        bottom = p[y + 1][x];
                    }
                    // cout << right << ' ' << bottom << endl;
                    int ma = max(right, bottom);
                    if (a[y][x] == '+')
                    {
                        ma++;
                    }
                    else
                    {
                        ma--;
                    }
                    p[y][x] = ma;
                }
            }
            else{
                if (y == h - 1 && x == w - 1)
                {
                    if (a[y][x] == '+')
                    {
                        p[y][x] = -1;
                    }
                    else
                    {
                        p[y][x] = 1;
                    }
                }
                else{
                    int right = INF;
                    int bottom = INF;
                    if (x + 1 < w)
                    {
                        right = p[y][x + 1];
                    }
                    if (y + 1 < h)
                    {
                        bottom = p[y + 1][x];
                    }
                    // cout << right << ' ' << bottom << endl;
                    int mi = min(right, bottom);
                    if (a[y][x] == '+')
                    {
                        mi--;
                    }
                    else
                    {
                        mi++;
                    }
                    p[y][x] = mi;
                } 
            }
            x++;
            y--;
        }
        is_takahashi = (is_takahashi + 1) % 2;
        if(j == 0){
            i--;
        }
        else{
            j--;
        }
    }
    int right = -INF;
    int bottom = -INF;
    if(w >= 2){
        right = p[0][1];
    }
    if(h >= 2){
        bottom = p[1][0];
    }
    int point = max(right, bottom);
    if (point > 0)
    {
        cout << "Takahashi" << endl;
    }
    else if (point < 0)
    {
        cout << "Aoki" << endl;
    }
    else
    {
        cout << "Draw" << endl;
    }
    // for (int i = 0; i < h; i++){
    //     for (int j = 0; j < w; j++){
    //         cout << p[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
}