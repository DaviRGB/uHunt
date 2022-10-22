#include <bits/stdc++.h>

using namespace std;
bool vis[30]={0};
vector<int>adjlist[30];

void dfs(int u)
{
    vis[u]=true;
    for(int v:adjlist[u])
    {
		if(!vis[v]){
			dfs(v);
		}
	}
}
//falta um negocio
int main()
{
	//freopen("output.txt","w",stdout);
    	int N; cin >> N;
    	char s;
    	string str;
    	cin.ignore();
    	for(int k=0;k<N;k++)
	{
		cin >> s;
		int e = s-64;
        	cin.ignore();
        	getline(cin, str);
		while(str!="\0")
		{
		    adjlist[str[0]-65].push_back(str[1]-65);
		    adjlist[str[1]-65].push_back(str[0]-65);
		    getline(cin,str);
		}
		int res = 0;
		for(int i=0;i<e;i++)
		{
			if(!vis[i]){
				res++;
				dfs(i);
			}
		}
		cout << res << endl;
		if(k<N-1){
            	cout << endl;
        }
	for(int i=0;i<e;i++)
	{
		adjlist[i].clear();
		vis[i] = false;
	}
    }
}

