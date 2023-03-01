#include <bits/stdc++.h>

using namespace std;

char mat[12][12];
//bool vis[52][52]; nn nescessario,talvez eu use
int vx[]={0, 1, -1, 0};
int vy[]={1, 0, 0, -1};
bool black,white;

bool ISvalid(int i,int j)
{
    return (i>=0 && i<9 && j>=0 && j<9 && mat[i][j]=='.');
}
int floodfill(int x,int y) //aqui tbm tem um int a e int b //que eu fiz uma função so para verificar ai as variaveis agr e global
{
    //cont++; //posso fazer isso antes de chamar a bfs zerar ele ou o que vou fazer
	int ax;
	int by;
    mat[x][y] = '1';
    int sum = 1;
	for(int i=0;i<4;i++)
	{
		ax = x+vx[i];
		by = y+vy[i];
		if(ISvalid(ax,by) ) //&& !vis[ax][by] nao precisei dessa fez usei mudar matriz
		{
			sum += floodfill(ax,by);
		}
        else{
            if(mat[ax][by]=='X') black = true;
            else{ 
                if(mat[ax][by]=='O') white = true;
				//return;
            }
        }
	}
    return sum;
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
	for(int i=0;i<9;i++)
    {
		for(int j=0;j<9;j++)
		{
			if(mat[i][j]=='.')
			{
				black = white = false;
				int sum = floodfill(i,j);
				if(!black && white) branco+=sum;
				else if(black && !white) preto+=sum;
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
