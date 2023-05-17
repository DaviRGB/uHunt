#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back

using namespace std;

vector<vector<pair<int,long long int>>>adj;
vector<bool>visited;

int dfs(int v, int mx) {
	int cont = 1;
	visited[v] = 1;
	for(auto i : adj[v]) {
		if(mx == i.s && !visited[i.f]) {
			cont +=dfs(i.f,mx);
		}
	}
	return cont;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n,m;
	while(1) {
		cin >> n >> m;
		if(n==0 && m==0) break;
		adj = vector<vector<pair<int,long long int>>>(n+1);
		visited.assign(n+1,0);
		int a,v;
		long long int p, mx = INT_MIN;
		int ans = 0;
		for(int i = 0; i < m ; i++) {
			cin >> a >> v >> p; a--; v--;
			adj[a].pb({v,p});
			adj[v].pb({a,p});
			mx = max(mx,p);
		}
		for(int i = 0 ; i < n; i++) {
			if(!visited[i]) {
				ans = max(ans,dfs(i,mx));
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
