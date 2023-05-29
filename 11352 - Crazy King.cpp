#include <bits/stdc++.h>
 
using namespace std;
 
#define sz(x) ((int)x.size())
#define fin freopen ("input.txt","r",stdin);
#define fout freopen ("output.txt","w",stdout);
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
#define ff first
#define ss second
#define pb push_back
#define mem(x, y) memset(x, y, sizeof(x))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()


bool vis[120][120];
char xadrez[120][120];
int n,m;

bool can (int x, int y) {
	return (x<n && x>=0 && y<m && y >=0 && !vis[x][y]); 
}

void cavalo(int i, int j) {
	vis[i][j] = 1;
	vector<pair<int,int>>horse = {{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
	for(auto x: horse) {
		int ax = i+x.ff;
		int by = j+x.ss;
		if(can(ax,by) && xadrez[ax][by] == '.') {
			vis[ax][by] = 1;
		}
	}
}

int bfs(int i,int j){
	vector<pair<int,int>> king = {{1,0}, {-1,0}, {1,1}, {1,-1} , {-1,1}, {0,1} , {0,-1}, {-1,-1}};
	queue<pair<int,pair<int,int>>> q;
	q.push({i,{j,0}});
	vis[i][j] = 1;
	while(!q.empty()){
		auto u = q.front(); q.pop();
		if(xadrez[u.ff][u.ss.ff] == 'B') return u.ss.ss;
		for(auto i: king) {
			int ax = i.ff + u.ff;
			int by = i.ss + u.ss.ff;
			if(can(ax,by) && xadrez[ax][by] != 'Z'){
				vis[ax][by] = 1;
				q.push({ax,{by,u.ss.ss+1}});
			}
		}
	}
	return -1;
}

int main () {
	
	fast;
	int tt; cin >> tt;
	while(tt--) {
		mem(vis, 0);
		cin >> n >> m;
		for(int i = 0;i < n; i++) {
			for(int j = 0; j < m; j++) {
				cin >> xadrez[i][j];
			}
		}
		int x,y;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(xadrez[i][j] == 'Z') {
					cavalo(i,j);
				}
				else if(xadrez[i][j] == 'A') {
					x = i; y = j;
				}
			}
		}
		int ans = bfs(x,y);
		(ans == -1 ? cout << "King Peter, you can't go now!" : cout << "Minimal possible length of a trip is " << ans);
		cout << '\n';
	}
	return 0;
}
