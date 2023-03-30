#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for(int i = 1; i <= tt; i++) {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<vector<char>> M(n, vector<char> (m, '.'));
    int q;
    cin >> q;
    while(q--) {
      int a, b;
      cin >> a >> b;
      M[a][b] = '#';
    }
    auto can = [&](int a, int b) {
      return a >=0 && a < n && b >= 0 && b < m && M[a][b] != '#';
    };
    vector<pair<int, int>> dir {{x, y}, {x, -y}, {-x, y}, {-x, -y}, {y, x}, {y, -x}, {-y, x}, {-y, -x}};
    pair<int, int> ret = {0, 0};
    auto bfs = [&]() {
      queue<pair<int, int>> q;
      vector<vector<bool>> vis(n, vector<bool> (m));
      q.push({0, 0});
      vis[0][0] = 1;
      while(!q.empty()) {
        auto [a, b] = q.front();
        q.pop();
        int c = 0;
        set<pair<int, int>> occ;
        for(auto [w, k] : dir) {
          int X = a + w;
          int Y = b + k;
          if(can(X, Y) && !occ.count({X, Y})) {
            occ.insert({X, Y});
            c += 1;
            if(!vis[X][Y]) {
              vis[X][Y] = 1;
              q.push({X, Y});
            }
          }
          
        }
        if(c % 2 == 0) {
          ret.first += 1;
        } else {
          ret.second += 1;
        }
      }
    };
    bfs();
    cout << "Case " << i << ": " << ret.first << ' ' << ret.second << '\n';
  }
  return 0;
}
