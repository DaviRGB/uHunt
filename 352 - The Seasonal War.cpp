#include <bits/stdc++.h>

using namespace std;

char mat[1000][1000];
bool visited[1000][1000];

int vx[]={0, 1, -1, 0, 1, -1, -1, 1};
int vy[]={1, 0, 0, -1, 1, -1, 1, -1};

void foodfill(int x,int y,int a,int b) //int *cont
{
	//cont++;
	mat[x][y] = '2';
	int ax;
	int by;
	for(int i=0;i<8;i++)
	{
		ax = x+vx[i];
		by = y+vy[i];
		if(ax>=0 && ax<a && by>=0 && by<b && mat[ax][by]=='1')
		{
			foodfill(ax,by,a,b); //cont
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cases = 0;
    int n;
	while(cin >> n)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin >> mat[i][j];
			}
		}
        int res = 0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(mat[i][j]=='1')
				{
                    res++;
					foodfill(i,j,n,n);
				}
			}
		}
		cout << "Image number " << ++cases << " contains " << res << " war eagles.\n";
	}
}
