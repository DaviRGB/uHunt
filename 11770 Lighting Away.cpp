#include <bits/stdc++.h>

using namespace std;

vector<bool>vis;
vector<vector<int>>adj, adjRev;
stack<int>mystack;

void dfs(int v)
{
    vis[v]=true;
    for(auto u: adj[v]) {
		if(!vis[u]) {
			dfs(u);
		}
	}
	mystack.push(v);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;	
    for(int k = 1 ; k <= t ; k++) {
		int n,m; cin >> n >> m;
		adj = vector<vector<int>>(n+1);
		for(int i = 0 ; i < m; i++) {
			int a,b; cin >> a >> b; a--; b--;
			adj[a].push_back(b);
		}
		vis.assign(n, false);
		for(int i = 0 ; i < n ; i++) {
			if(!vis[i]) {
				dfs(i);
			}
		}
		vis.assign(n, false);
		int cont = 0;
		while (!mystack.empty()) {
			auto u = mystack.top(); mystack.pop();
			if(!vis[u]) {
				cont++;
				dfs(u);
			}
		}
		cout << "Case " << k  << ": "<< cont << '\n';
	}
}
