#include <bits/stdc++.h>
 
using namespace std;

#define sz(x) ((int)x.size())
#define fin freopen ("input.txt","r",stdin);
#define fout freopen ("output.txt","w",stdout);
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define ff first
#define ss second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

std::mt19937 rng((int) std::chrono ::steady_clock::now().time_since_epoch().count());
std::mt19937_64 rng64((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main () {
	
	fast;
	bool prime[1000001] = {0};//false == prime | true == not prime
	vector<int> v;
	//~ memset(prime,1,sizeof(prime)); onde e true e false
	for(int i = 2; i <= 1000000;i++){
		if(!prime[i]){
			v.push_back(i);
			for(int j = i + i ;j <= 1000000;j += i)
				prime[j] = true;
		}
	}
	int n;
	while(cin >> n, n) {
		int w = upper_bound(v.begin(),v.end(),n) - v.begin();
		int a;
		bool ok = false;
		while(w--) {
			int res = n-v[w];
			a = lower_bound(v.begin() , v.end(),res) - v.begin();
			if(v[a]+v[w] == n) {
				cout << n << " = " << v[a] << " + " << v[w] << '\n';
				ok = true;
				break;
			}
		}
		if(!ok) cout << "Goldbach's conjecture is wrong\n";
	}
	return 0;
}
