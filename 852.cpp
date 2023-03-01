#include <bits/stdc++.h>

using namespace std;

char mat[12][12];
bool vis[12][12];
int vx[]={0, 1, -1, 0, 1, -1, -1, 1};
int vy[]={1, 0, 0, -1, 1, 1, -1, -1};
bool black,white;
int cont;

bool ISvalid(int i,int j)
{
    return (i>=0 && i<9 && j>=0 && j<9 && !vis[i][j]);
}
void floodfill(int x,int y)
{
	int ax;
	int by;
	vis[x][y] = true;
	for(int i=0;i<4;i++)
	{
		ax = x+vx[i];
		by = y+vy[i];
		if(ISvalid(ax,by) && mat[ax][by]=='.')
		{
            cont++;
            floodfill(ax,by);
		}
        else{
            if(ISvalid(ax,by) && mat[ax][by]=='X') black = true;
            else{ 
                if(ISvalid(ax,by) && mat[ax][by]=='O') white = true;
            }
        }
	}
}


void solve()
{
    int branco = 0,preto = 0;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cin >> mat[i][j];
            if(mat[i][j]=='X') preto++;
            else if(mat[i][j]=='O') branco++;
        }
    }
    cout << '\n';
    for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(mat[i][j]=='.' && !vis[i][j])
			{
				cont = 1; //começa com 1 ou com 0 fora 0 dentro 1
                black = white = false;
                floodfill(i,j);
                for(int k = 0; k < 9; k++) {
					for(int l = 0; l < 9; l++) {
						cout << vis[k][l];
					}
					cout << '\n';
				}
				cout << '\n';
                if(!black && white) branco+=cont;
                else if(black && !white) preto+=cont;
             }
		}
	}
	cout << "Black " << preto << " White " << branco << endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt; cin >> tt;
    while(tt--)
    {
        solve();
    }
}
