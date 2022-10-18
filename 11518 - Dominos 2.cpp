#include <bits/stdc++.h>

using namespace std;
bool vis[100002]={0};
vector<int>adjlist[1000002];

int cont = 0;
void dfs(int u)
{
	cont++;
    vis[u]=true;
    for(int v:adjlist[u])
    {
		if(!vis[v]){
			cont++;
			dfs(v);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    int vet[10000];
    while(t--) {
		int v,a,l; cin >> v >> a >> l;
		for(int j=0;j<a;j++)
		{
			int b,c; cin >> b >> c;
			adjlist[b].push_back(c); //e direcionado
		}
		for(int i=0;i<l;i++)
		{
			int der; cin >> der;
			vet[i] = der;
		}
		for(int i=0;i<l;i++)
		{
			if(!vis[vet[i]]){
				dfs(vet[i]);
			}
		}
		cout << cont << endl;
		for(int i=0;i<=v;i++)
		{
			adjlist[i].clear();
			vis[i] = false;
		}
		cont = 0;
	}
}
