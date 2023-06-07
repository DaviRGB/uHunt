#include <bits/stdc++.h>
#define pb push_back
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

using namespace std;

vector<vector<int>> adj;
vector<bool>visited;
vector<int> color;

bool bipartite(int v)
{
	for(auto u : adj[v]) {
		if(!visited[u]) {
			visited[u] = true;
			color[u] = !color[v];
			if (!bipartite(u)) return false;
		}
		else if (color[u] == color[v])
			return false;
	}
	return true;
}

int main()
{
	fast;
	int n,m;
	while(cin >> n, n) {
		cin >> m;
		adj = vector<vector<int>>(n+1);
		color = vector<int>(n+1,0);
		visited = vector<bool> (n+1,0);
		for(int i = 0; i < m; i++) {
			int a,b; cin >> a >> b;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		visited[0] = true;
		color[0] = 0;
		if (bipartite(0)) {
			cout << "BICOLORABLE.\n";
		}
		else {
			cout << "NOT BICOLORABLE.\n";
		}
	}
	return 0;
}
