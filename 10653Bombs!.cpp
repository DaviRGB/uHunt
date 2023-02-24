#include <bits/stdc++.h>

using namespace std;

int mat[1060][1060];
bool vis[1060][1060];
int m,n;
int vx[4] = {0,1,0,-1};
int vy[4] = {-1,0,1,0};

int bfs(int origemx,int origemy,int destinox,int destinoy)
{
	queue<pair<int,pair<int,int>>>q;
	q.push({0,{origemx,origemy}});
	vis[origemx][origemy]=true;
	
	while(!q.empty())
	{
		auto u=q.front();
		if(u.second.first==destinox &&u.second.second==destinoy) return u.first;
		q.pop();
		for(int i=0;i<4;i++){
			int ax=u.second.first+vx[i];
			int by=u.second.second+vy[i];
			if(ax>=0 && ax<m && by>=0 && by<n && mat[ax][by]==0 && !vis[ax][by]){
				vis[ax][by]=true;
				q.push({u.first+1,{ax,by}});
			}
		}
	}
	return -1;
}


int main()
{
	while(cin >> m >> n && (m!=0 || n!=0))
	{
		memset(mat,0,sizeof(mat));
		memset(vis,0,sizeof(vis));
		int l; cin >> l;
		for(int i =0;i<l;i++)
		{
			int a; cin >> a;
			int b; cin >> b;
			for(int j=0;j<b;j++)
			{
				int c;cin >>c; 
				mat[a][c] = 1;
			}
		}
		int i,j; cin >> i >> j;
		int fi,fim; cin >> fi >> fim;
		cout << bfs(i,j,fi,fim) << endl;
	}
}
