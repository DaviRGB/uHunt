#include <bits/stdc++.h>
 
#define sz(x) ((int)x.size())
#define fin freopen ("input.txt","r",stdin);
#define fout freopen ("output.txt","w",stdout);
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
#define ff first
#define ss second
#define pb push_back
#define mem(x, y) memset(x, y, sizeof(x))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;

pair<int , int> robo(int rows, int columns, int columns_i, vector<string>& vec) {

    vector<vector<int>> grid(rows, vector<int>(columns,-1));
    int x = 0, y = columns_i -1; int steps = 0;

    while(x >= 0 && x < rows && y >= 0 && y < columns && grid[x][y] == -1) {
        grid[x][y] = steps;
        if( vec[x][y] == 'N' ) x--;
        else if ( vec[x][y] == 'S' ) x++;
        else if ( vec[x][y] == 'W' ) y--;
        else if ( vec[x][y] == 'E' ) y++;
        steps++;
    }

    if(x < 0 || x >= rows || y < 0 || y >= columns) {
        return { steps, 0 };
    } else {
        return { grid[x][y], steps - grid[x][y] };
    }
}

int main() {

    ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    while (true) {
        int x, y, columns_i;
        cin >> x >> y >> columns_i;
        if (x == 0 && y == 0 && columns_i == 0) break;

        vector<string> vec(x);
        for (int i = 0; i < x; i++) {
            cin >> vec[i];
        }
        pair<int, int> ans = robo(x, y, columns_i, vec);

        if (ans.ss == 0) {
            cout << ans.ff << " step(s) to exit\n";
        } else {
            cout << ans.ff << " step(s) before a loop of " << ans.ss << " step(s)\n";
        }
    }
    return 0;
}