#include <bits/stdc++.h>

#define IOS ios_base::sync_with_stdio(false);cin.tie(0);
#define entrada freopen("input.txt", "r", stdin);
#define saida freopen("output.txt", "w", stdout);
using namespace std;


class Solution {
public:
	vector<int> topo(int N, vector<int> adj[]) {
		priority_queue<int,vector<int>,greater<int>> q; 
		vector<int> indegree(N, 0); 
		for(int i = 0;i<N;i++) {
			for(auto it: adj[i]) {
				indegree[it]++; 
			}
		}
		for(int i = 0;i<N;i++) {
			if(indegree[i] == 0) {
				q.push(i); 
			}
		}
		vector<int> topo;
		while(!q.empty()) {
			int node = q.top(); q.pop(); 
			topo.push_back(node);
			for(auto it : adj[node]) {
				indegree[it]--;
				if(indegree[it] == 0) {
					q.push(it); 
				}
			}
		}
		return topo;
	}
};

int main() {
	
	int n;
	string str;
	int cases = 0;
	IOS;
	//~ entrada; saida;
	while(cin >> n) {
		map<string,int>mp;
		map<int,string>mpp;
		vector<int>adj[n];
		for(int i = 0 ; i < n ; i++) {
			cin >> str;
			mp[str] = i;
			mpp[i] = str;
		}
		int m; cin >> m;
		for(int i = 0; i < m ; i++) {
			string a,b; cin >> a >> b;
			adj[mp[a]].push_back(mp[b]);
		}
		Solution obj;
		vector<int> v=obj.topo(n, adj);
		//~ if(cases) cout << '\n';
		cout << "Case #" << ++cases << ": Dilbert should drink beverages in this order:";
		for(auto it:v)
			cout << ' '<<mpp[it];
		cout << ".\n\n";
	}
    return 0;
}
