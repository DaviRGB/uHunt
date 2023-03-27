#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define entrada freopen("input.txt", "r", stdin);
#define saida freopen("output.txt", "w", stdout);

using namespace std;

vector<int>vec;
vector<int>adjlist[100001];
vector<int> dist;
bool vis[100001];

int bfs(int origem,int destino)
{
	queue<pair<int,int>>q;
	q.push({0,origem});
	vis[origem]=true;
	
	while(!q.empty())
	{
		auto u=q.front();
		if(u.second==destino) return u.f;
		q.pop();
		for(int i = 0 ; i < (int)vec.size(); i++) {
			if(!vis[(vec[i]+u.second)%10000]) {
				vis[(vec[i]+u.second)%10000] = true;
				q.push({u.first+1, (vec[i]+u.second)%10000});
			}
		}
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	//entrada; saida;
	int l , u , r;
	int cases = 0;
	while(cin >> l >> u >> r, l | u | r)
	{
		memset(vis,0,sizeof(vis));
		for(int i = 0 ; i < r; i++)
		{
			int c; cin >> c;
			vec.pb(c);
		}
		int n = bfs(l,u);
		cout << "Case " << ++cases << ": ";
		vec.clear();
		(n == -1 ? cout << "Permanently Locked\n" : cout << n << '\n');
	}
}
