#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

vector<string>word;
vector<int> dist;

int bfs(int a, int b)
{
	queue<int>q;
	q.push(a);
	dist[a] = 0;
	
	while(!q.empty())
	{
		int u=q.front();
		if(u==b) return dist[b];
		q.pop();
		for(int i=0;i<word.size();i++){
			int c = 0;
			if(word[i].size() > word[u].size() + 1 || dist[i] != INF) continue;
			for(int j=0;j<word[i].size();j++){
				if(word[i][j]!=word[u][j]){
					c++;
				}
			}
			if(c != 1) continue;
			dist[i] = dist[u] + 1;
			q.push(i);
		}
	}
	return -1;
}

int index(string item) {

    for (auto i = 0; i < word.size(); ++i) {
        if (word[i] == item)
            return i;
    }

    return -1;
}

int main()
{
	int casos; cin >> casos;
	string str,str2,s,in,fi;
	for(int i=0;i<casos;i++){
		word.clear();
		while(cin >> str2 && str2!="*")
		{
			word.push_back(str2);
		}
		cin.ignore();
		while(getline(cin,s) && s.size())
		{
			dist.assign(1e5, INF);
			stringstream token(s);
			token >> in >> fi;
			int t = index(in);
			int tt = index(fi);
			cout << in << " " << fi << " " << bfs(t,tt) << endl;
		}
		if(i+1 < casos) cout << endl;
	}
}
