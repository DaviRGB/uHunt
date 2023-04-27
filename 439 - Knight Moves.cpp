#include <bits/stdc++.h>

using namespace std;

bool vis[8][8];
int dist[8][8];
vector<pair<int,int>> dir {{-2,-1} , {-2,1} , {2,-1} , {2,1} , {-1,-2} , {-1,2} , {1,-2} , {1, 2}};

void limpa() {
  memset(dist,0,sizeof(dist));
	memset(vis,0,sizeof(vis));
}

bool can(int i,int j) {
	return (i>=0 && i<8 && j>=0 && j<8 && !vis[i][j]);
}

int bfs(int in,int in2, int fim,int fim2) {
	queue <pair<int,int>>q;
	q.push({in,in2});
  vis[in][in2] = true;
	dist[in][in2] = 0;
	while(!q.empty()) {
		auto u = q.front(); q.pop();
		if(u.first == fim && u.second == fim2) return dist[fim][fim2];
		for(auto i: dir) {
			int ax = u.first + i.first;
			int by = u.second + i.second;
			if(can(ax,by)) {
				q.push({ax,by});
				vis[ax][by] = 1;
				dist[ax][by] = dist[u.first][u.second]+1;
			}
		}
	}
	//~ return dist[fim][fim2];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string str,str2;
	while(cin >> str >> str2) {
    limpa();
		int in,in2,fim,fim2;
		in = str[0]-'a'; in2 = str[1]-49;
		fim = str2[0]-'a'; fim2 = str2[1]-49;
    int moves = bfs(in,in2,fim,fim2);
    cout << "To get from " << str << " to " << str2 << " takes " << moves << " knight moves.\n";
	}
	return 0;
}
