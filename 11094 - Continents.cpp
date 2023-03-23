#include <bits/stdc++.h>

using namespace std;

int vx[]={0, 1, -1, 0};
int vy[]={1, 0, 0, -1};
int cont;
char mat[25][25];
bool vis[25][25];
bool ISvalid(int i,int j,int n,int m)
{
    return (i>=0 && i<n && j>=0 && j<m);
}
void dfs(int x,int y,int n,int m,char a, char b)
{
	int ax;
	int by;
  vis[x][y] = true;
  cont++;
	for(int i=0;i<4;i++)
	{
		ax = x+vx[i];
		by = y+vy[i];
    cout << by << endl;
    if(by<0){
      by+=m;
    }
		if(ISvalid(ax,by,n,m) && !vis[ax][by] && mat[ax][by]==a)
		{
			dfs(ax,by,n,m,a,b);
		}
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char a,b;
    int n,m;
    while(cin >> n >> m){
      int mx = 0;
      for(int i = 0;i < n;i++){
        for(int j=0;j < m;j++){
          cin >> mat[i][j];
          vis[i][j] = false;
        }
      }
      int x,y; cin >> x >> y;
      a = mat[x][y];
      b = a-1;
      dfs(x,y,n,m,a,b);
      cont = 0;
      for(int i = 0;i < n;i++){
        for(int j=0;j < m;j++){
          if(mat[i][j]==a && !vis[i][j]){
            dfs(i,j,n,m,a,b);
            if(cont > mx){
              mx = cont;
            }
            cont = 0;
          }
        }
      }
      cout << mx << endl;
    }
}
