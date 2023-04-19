#include <bits/stdc++.h>
using namespace std;

int grid[105][105];
bool vis[105][105];
int r, c;

bool can(int x,int y){
	return (x >= 0 && x < r && y >= 0 && y < c && grid[x][y] != -1);
}
void dfs(int x, int y, int n, int m)
{
	set<pair<int , int>> occ;
    vis[x][y] = true;
    int vx[] = {n, n, -n, -n, m, m, -m, -m};
    int vy[] = {m, -m, m, -m, n, -n, n, -n};

    for(int i = 0; i < 8; i++)
    {
        int ax = x + vx[i];
        int by = y + vy[i];
        if(can(ax,by) && !occ.count({ax,by}))
        {
			occ.insert({ax,by});
            grid[ax][by]++;
            if(!vis[ax][by])
                dfs(ax, by, n, m);
        }
    }
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    int n, m, w;
    int t; cin >> t;
    for(int tt = 1 ; tt <= t; tt++) {
		cin >> r >> c >> n >> m >> w;
		memset(grid, 0, sizeof(grid));
		memset(vis, 0, sizeof(vis));
		while(w--)
		{
			int x, y;
			cin >> x >> y;
			grid[x][y] = -1;
		}
		dfs(0, 0, n, m);
		int even = 0, odd = 0;
		for(int i = 0; i < r; i++)
		{
			for(int j = 0; j < c; j++)
			{
				if(grid[i][j] > 0) {
					if(grid[i][j]%2==0) {
						odd++;
					}
					else even++;
				}
			}
		}
		if(grid[0][0]==0) odd++;
		cout << "Case " << tt << ": " << odd << " " << even << endl;
	}
    return 0;
}
