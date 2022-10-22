#include <bits/stdc++.h>

using namespace std;

char mat[102][102];
bool vis[102][102];
int vx[]={0, 1, -1, 0};
int vy[]={1, 0, 0, -1};

void foodfill(int x,int y,int a,int b)
{
	int ax;
	int by;
    vis[x][y] = true;
	for(int i=0;i<4;i++)
	{
		ax = x+vx[i];
		by = y+vy[i];
		if(ax>=0 && ax<a && by>=0 && by<b && (mat[ax][by] == 'x' || mat[ax][by] == '@') && !vis[ax][by])
		{
			foodfill(ax,by,a,b);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n; cin >> t;
    int cases = 0;
	while(t--)
	{
        cin >> n;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin >> mat[i][j];
                vis[i][j] = false;
			}
		}
        int res = 0;
        for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
                if((mat[i][j] == 'x') && !vis[i][j])
                {
                    //cont =0;
                    foodfill(i,j,n,n);
                    res++;
                }
			}
		}
        cout << "Case "<< ++cases << ": "<< res << endl;
	}
}
