#include <bits/stdc++.h>

using namespace std;

vector<bool>vis;
vector<vector<int>>adj;
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
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
		int cont = 0;
		int v,m; cin >> v >> m;
		adj = vector<vector<int>>(v+1);
		for(int j=0;j<m;j++)
		{
			int a,b; cin >> a >> b; a--; b--;
			adj[a].push_back(b);
		}
		vis.assign(v, false);
		for(int i=0;i<v;i++)
		{
			if(!vis[i]){
				dfs(i);
			}
		}
		vis.assign(v, false);
		while (!mystack.empty())
		{
			auto u = mystack.top(); mystack.pop();
			if(!vis[u]) {
				cont++;
				dfs(u);
			}
		}
		cout << cont << endl;
	}
}
