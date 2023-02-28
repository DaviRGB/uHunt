#include <bits/stdc++.h>

using namespace std;

char mat[12][12];
//bool vis[52][52]; nn nescessario,talvez eu use
int vx[]={0, 1, -1, 0};
int vy[]={1, 0, 0, -1};
bool black,white;
int cont;

bool ISvalid(int i,int j)
{
    return (i>=0 && i<9 && j>=0 && j<9);
}
void floodfill(int x,int y)
{
	int ax;
	int by;
    mat[x][y] = '1';
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
            if(mat[ax][by]=='X') black = true;
            else{ 
                if(mat[ax][by]=='O') white = true;
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
            else{
                if(mat[i][j]=='.')
                {
                    cont = 0;
                    black = white = false;
                    floodfill(i,j);
                    if(!black && white) branco+=cont;
                    else if(black && !white) preto+=cont;
                }
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
