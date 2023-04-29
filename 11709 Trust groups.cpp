#include <bits/stdc++.h>

using namespace std;

vector<bool>vis;
vector<vector<int>>adj , adjRev;
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

void dfs2(int v) {
	vis[v] = true;
	for(auto u : adjRev[v]) {
		if(!vis[u]) {
			dfs2(u);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    while(true) {
		int n,m; cin >> n >> m;
		if(n == 0 && m == 0) break;
		adj = vector<vector<int>>(n+1);
		adjRev = vector<vector<int>>(n+1);
		map<string,int>mp;
		cin.ignore();
		for(int i = 0 ; i < n ; i++) {
			string str; getline(cin , str);
			mp[str] = i;
		}
		for(int i = 0;i < m; i++)
		{
			string a; string b;
			getline(cin , a); getline(cin , b);
			adj[mp[a]].push_back(mp[b]);
			adjRev[mp[b]].push_back(mp[a]);
		}
		vis.assign(n, false);
		for(int i = 0 ; i < n ; i++)
		{
			if(!vis[i]){
				dfs(i);
			}
		}
		vis.assign(n, false);
		int cont = 0;
		while (!mystack.empty())
		{
			auto u = mystack.top(); mystack.pop();
			if(!vis[u]) {
				cont++;
				dfs2(u);
			}
		}
		cout << cont << endl;
	}
}
