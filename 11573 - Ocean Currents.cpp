#include <bits/stdc++.h>
 
using namespace std;
 
#define sz(x) ((int)x.size())
#define fin freopen ("input.txt","r",stdin);
#define fout freopen ("output.txt","w",stdout);
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define INF 1e7
#define ff first
#define ss second
#define pb push_back
#define mem(x, y) memset(x, y, sizeof(x))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

int vx[]={-1,-1, 0, 1, 1, 1, 0, -1};
int vy[]={ 0, 1, 1, 1, 0,-1,-1, -1};
vector<char> d = {'0', '1','2','3','4','5','6','7'};
char mat[1002][1002];
int dist[1002][1002];
int r,c;

bool can(int x, int y) {
	return (x<r && x>=0 && y<c && y >=0); 
}

int bfs(int rs, int cs, int rd, int cd){
	
	using ii = pair<int,int>;
	priority_queue <pair<int, ii>, vector<pair<int,ii>>, greater<pair<int,ii>>>q;
	q.push({0, {rs,cs}});
	dist[rs][cs] = 0;
	
	while(!q.empty()) {
		auto [w, u] = q.top(); 
		q.pop();
		
		if(w > dist[u.ff][u.ss]) continue;
		
		for(int i = 0 ; i < 8; i++) {
			int ax = u.ff + vx[i];
			int by = u.ss + vy[i];
			
			if(!can(ax, by)) continue;
			
			if((mat[u.ff][u.ss] == d[i])) {

				if(dist[ax][by] > dist[u.first][u.second]) {
					dist[ax][by] = dist[u.first][u.second];
					q.push({dist[ax][by], {ax,by}});
				}
			}
			else {
				if(dist[ax][by] > dist[u.ff][u.ss]+1) {
					dist[ax][by] = dist[u.ff][u.ss]+1;
					q.push({dist[ax][by], {ax,by}});
				}
			}
			
		}
	}
	return dist[rd][cd];
}

int main () {	
	fast;
	cin >> r >> c;
	for(int i = 0 ; i < r ; i++) {
		for(int j = 0 ; j < c ; j++) {
			cin >> mat[i][j];
		}
	}
	int t,rs,cs,rd,cd;
	cin >> t;
	while(t--) {
		cin >> rs >> cs >> rd >> cd;
		for(int i = 0 ; i < r ; i++) {
			for(int j = 0 ; j < c; j++)
				dist[i][j] = INF;
		}
		cout << bfs(rs-1,cs-1,rd-1,cd-1) << '\n';
	}
	return 0;
}
