#include <bits/stdc++.h>

using namespace std;

char mat[1002][1002];

int vx[8]={0,1,0,-1,1,1,-1,-1};
int vy[8]={1,0,-1,0,1,-1,1,-1};

void foodfill(int x,int y,int &cont,int a,int b)
{
	cont++;
	mat[x][y] = '2'; //da para usar um visited tbm
	int ax;
	int by;
	for(int i=0;i<8;i++)
	{
		ax = x+vx[i];
		by = y+vy[i];
		if(ax>=0 && ax<a && by>=0 && by<b && mat[ax][by]=='1')
		{
			foodfill(ax,by,cont,a,b);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    cin.ignore();
    string str; getline(cin, str);
	while(t--)
	{
        vector<string> salve;
        getline(cin,str);
        while(str!="\0")
        {
            salve.push_back(str);
            getline(cin, str);
		}
		int cont = 0;
		int maior = 0;
        for(int i=0;i<salve.size();i++)
		{
			for(int j=0;j<salve[i].size();j++)
			{
                mat[i][j] = salve[i][j];
            }
        }
		for(int i=0;i<salve.size();i++)
		{
			for(int j=0;j<salve[i].size();j++)
			{
				if(mat[i][j]=='1')
				{
					cont = 0;
                    //cout << salve.size() << " " << salve[i].size() << " " << maior << endl;
					foodfill(i,j,cont,salve.size(),salve[i].size());
					if(maior<cont)
					{
						maior = cont;
					}
				}
			}
		}
		cout << maior << "\n";
        if(t) cout << "\n";
		
	}
}
