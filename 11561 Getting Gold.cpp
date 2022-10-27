#include <bits/stdc++.h>

using namespace std;

char mat[52][52];
bool vis[52][52];
int vx[]={0, 1, -1, 0};
int vy[]={1, 0, 0, -1};
int w,h,cont;

bool ISvalid(int i,int j)
{
    return (i>=0 && i<h && j>=0 && j<w);
}
void floodfill(int x,int y) //aqui tbm tem um int a e int b //que eu fiz uma função so para verificar ai as variaveis agr e global
{
	int ax;
	int by;
    vis[x][y] = true;
    cout << "x: " << x << "y: " << y <<"mat[x][y]: "<<mat[x][y] << endl;
    if(mat[x][y]=='G') cont++;
    for(int i=0;i<4;i++)
	{
		ax = x+vx[i];
		by = y+vy[i];
		if(ISvalid(ax,by) && mat[ax][by] == 'T') return; //&& !vis[ax][by]
	}
	for(int i=0;i<4;i++)
	{
		ax = x+vx[i];
		by = y+vy[i];
		if(ISvalid(ax,by) && (mat[ax][by] == 'G' || mat[ax][by] == '.') && !vis[ax][by])
		{
			floodfill(ax,by);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int cases = 0;
	while(cin >> w >> h)
	{
		for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
			{
				cin >> mat[i][j];
                vis[i][j] = false;
			}
		}
        //int res = 0;
        for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
			{
                if(mat[i][j] == 'P')
                {
                    //cont =0;
                    floodfill(i,j);
                    //res++;
                }
			}
		}
        cout << cont << endl;
        //cout << "Case "<< ++cases << ": "<< res << endl;
	}
}
