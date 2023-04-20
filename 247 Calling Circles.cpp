#include <bits/stdc++.h>
#define entrada freopen("input.txt", "r", stdin);
#define saida freopen("output.txt", "w", stdout);


using namespace std;

map<string,vector<string>> adj, adj_rev;
map<string,bool> used;
vector<string> order, component;

void dfs1(string v) {
    used[v] = true;

    for (auto u : adj[v])
        if (!used[u])
            dfs1(u);

    order.push_back(v);
}

void dfs2(string v) {
    used[v] = true;
    component.push_back(v);

    for (auto u : adj_rev[v])
        if (!used[u])
            dfs2(u);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    //~ entrada; saida;
    int n,m,v=0;
    int casos = 0;
    while(cin >> n >> m , n && m) {
		if(v++)cout << "\n";
		cout << "Calling circles for data set " << ++casos << ":\n";
		for (int i = 0; i < m ; i++) { //quant de liga
			string a, b; cin >> a >> b;
			adj[a].push_back(b);
			adj_rev[b].push_back(a);
		}
		used.clear();
		for (auto i :adj){ //quant de pessoas
			if (!used[i.first]) {
				dfs1(i.first);
      }
    }
		used.clear();
		reverse(order.begin(), order.end());
		for (auto v : order){
			if (!used[v]) {
				dfs2 (v);
				for(int i = 0 ; i < (int)component.size(); i++) {
					cout << component[i] << (i < (int)component.size()-1 ? ", " : "\n");
				}
				component.clear();
			}
		}
		adj.clear();
		adj_rev.clear();
		order.clear();
	}
}
