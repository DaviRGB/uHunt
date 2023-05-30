#include <bits/stdc++.h>
 
using namespace std;
 
#define sz(x) ((int)x.size())
#define fin freopen ("input.txt","r",stdin);
#define fout freopen ("output.txt","w",stdout);
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define ff first
#define ss second
#define pb push_back
#define mem(x, y) memset(x, y, sizeof(x))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define N 10

bool vis[N][N];
int dist[N][N];

bool can (int x, int y) {
	return (x<8 && x>=0 && y<8 && y >=0 && !vis[x][y]); 
}

void bfs(int inx,int iny, int fx, int fy){
	vector<pair<int,int>> king = {{1,0}, {-1,0}, {1,1}, {1,-1} , {-1,1}, {0,1} , {0,-1}, {-1,-1}};
    queue <pair<int,int>>q;
    q.push({inx, iny});
    vis[inx][iny] = 1;
    dist[inx][iny] = 0;
	while(!q.empty()){
		auto u = q.front(); q.pop();
    if(u.ff == fx && u.ss == fy) break;
		for(auto i: king) {
			int ax = i.ff + u.ff;
			int by = i.ss + u.ss;
			if(can(ax,by) ){
				vis[ax][by] = 1;
        dist[ax][by] = dist[u.ff][u.ss] + 1;
				q.push({ax, by});
			}
		}
	}
}

int main () {
	
    fast;
    int inx,iny,fx,fy,c3,r3;
    int cases = 0;
    while(cin >> inx >> iny >> fx >> fy >> c3 >> r3) {
        mem(vis,0);
        mem(dist,-1);
        vis[c3-1][r3-1] = true;
        bfs(inx-1, iny-1 , fx-1, fy-1);
        cout << "Case " << ++cases << ": "<< dist[fx-1][fy-1] << endl;
    }
	  return 0;
}
