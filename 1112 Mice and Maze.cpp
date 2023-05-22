#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define INF 0x3f3f3f3f
#define entrada freopen("in.txt", "r", stdin)
#define saida freopen("out.txt", "w", stdout)

using namespace std;

vector<vector<pair<int,int>>>adj;
vector<bool>visited;
vector<int>dist;

void bfs(int start) {
	
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	pq.push({0,start});
	dist[start] = 0;
	while(!pq.empty()) {
		auto u = pq.top(); pq.pop();
		if(dist[u.s]!=u.f) continue;
		for(auto v: adj[u.s]) {
			if(dist[v.f] > u.f+v.s) {
				dist[v.f] = u.f+v.s;
				pq.push({u.f+v.s,v.f});
			}
		}
	}
}

int main () {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//~ entrada; saida;
	int t, r = 0;
	cin >> t;
	while(t--) {
		if(r++) cout << endl;
		int n,out,time,m;
		cin >> n >> out >> time >> m;
		adj = vector<vector<pair<int,int>>>(n+1);
		dist.assign(n+1,INF);
		for(int i = 0 ; i < m ; i++) {
			int a,b,p; cin >> a >> b >> p;
			a--; b--;
			adj[b].pb({a,p});
		}
		int cont = 0;
		out--;
		bfs(out);
		for(int i = 0; i < n; i++) {
			if(dist[i] <= time) cont++;
		}
		cout << cont << '\n';
	}
	return 0;
}
