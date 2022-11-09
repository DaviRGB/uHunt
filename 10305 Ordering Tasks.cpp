#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;
	while(n!=0 || m!=0)
	{
		vector<int>adjlist[n];
		queue<int>q;
		int valor[n];
		for(int i=0;i<n;i++) valor[i] = 0;
		for(int i=0;i<m;i++)
		{
			int a,b; cin >> a >> b;
			a--;
			b--;
			adjlist[a].push_back(b);
			valor[b]++;
		}
		for(int i=0;i<n;i++)
		{
			if(valor[i]==0)
				q.push(i);
		}
		bool ok = false;
		while(!q.empty())
		{
			int u = q.front();
			q.pop();
			if(ok==false)
			{
				cout << u+1;
			}
			else
			{
				cout << " " << u+1;
			}
			ok = true;
			for(int i=0;i<adjlist[u].size();i++)
			{
				valor[adjlist[u][i]]--;
				if(valor[adjlist[u][i]]==0)
				{
					q.push(adjlist[u][i]);
				}
			}
		}
		cout << endl;
		cin >> n >> m;
	}
}
