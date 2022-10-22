#include <bits/stdc++.h>

using namespace std;

char mat[102][102];
bool vis[102][102];

int vx[]={0, 1, -1, 0, 1, -1, -1, 1};
int vy[]={1, 0, 0, -1, 1, -1, 1, -1};

bool ok;

void foodfill(int x,int y,int a,int b) //int *cont
{
	int ax; 
	int by;
    //mat[x][y] = 2;
    vis[x][y] = true;
    //cout << x << " " << y << endl;
    //if(vis[4][4]) ok = true;
	for(int i=0;i<8;i++)
	{
		ax = x+vx[i];
		by = y+vy[i];
		if(ax>=0 && ax<a && by>=0 && by<b && mat[ax][by] == '@' && !vis[ax][by])
		{
			foodfill(ax,by,a,b);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n;
	while(cin >> m >> n &&(m!=0 && n!=0))
	{
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin >> mat[i][j];
                vis[i][j] = false;
			}
		}
        int res = 0;
        for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
                if(mat[i][j] == '@' && !vis[i][j])
                {
                    res++;
                    foodfill(i,j,m,n);
                }
			}
		}
        cout << res << endl;
		//for(int i=0;i<m;i++) //apenas para mim ver
		//{
		//	for(int j=0;j<n;j++)
		//	{
		//		cout << mat[i][j] << " ";
		//	}
		//	cout << endl;
		//}
		//cout << endl;
	}
}
