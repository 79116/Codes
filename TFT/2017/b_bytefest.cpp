#include "bits/stdc++.h"

using namespace std;

#define fori(i, a, b) for(int i = (int) (a); i <= (int) (b); ++i)
#define ford(i, a, b) for(int i = (int) (a); i >= (int) (b); --i)
#define forIT(it, begin, end) for(__typeof(end) it = (begin) + ((begin) > (end)); it != (end) - ((begin) > (end)); it += 1 - 2 * ((begin) > (end)))

#define fi first
#define se second
#define b_e(x) begin(x), end(x)
#define ii pair<int, int>
#define vi vector<int> 
#define vvi vector<vi>

#define pb push_back
#define pf push_front
#define eb emplace_back
#define em emplace
#define ob pop_back
#define om pop
#define of pop_front

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand rng
#define endl '\n'
#define sp ' '

void solve();

int32_t main() {
 freopen("bytefest.inp","r",stdin);
 freopen("b_bytefest.out","w",stdout);
   ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   int test_num = 1;
   fori(test, 1, test_num) {
      solve();
   }
   return 0;
}

#define ld long double
#define int long long
const ld pi = 4 * atan(1.0), eps = 1e-9;
const int maxn = 25; 

int n, m; 
int h[maxn]; 
int l[maxn]; 
vector<ii> g[maxn]; 
int vs[maxn]; 
void dfs(int u, int &len, int mask, bool &ok, int &sum) { 
	vs[u] = 1; 
	int deg = 0; 
	for(ii e: g[u]) { 
		int v = e.fi, id = e.se; 
		if(mask >> id - 1 & 1) { 	
			deg++;
			if(!vs[v]) { 
				sum += h[id]; 
				len += l[id]; 
				dfs(v, len, mask, ok, sum); 
			}
		}
	}
	ok &= deg <= 2; 
	ok &= len <= m; 
}
void solve() {
	cin >> n >> m; 
	fori(i, 1, n - 1) { 
		int u, v; cin >> u >> v >> l[i] >> h[i]; 
		g[u].eb(v, i); 
		g[v].eb(u, i); 
	}
	int ans = 0; 
	fori(mask, 0, (1 << n - 1) - 1 ) {
		fori(i, 1, n) vs[i] = 0; 
		int sum = 0; bool ok = 1; 
		fori(i, 1, n) { 
			if(!vs[i]) { 
				int len = 0; 
				dfs(i, len, mask, ok, sum); 
			}
		}
		if(ok) ans = max(ans, sum); //, cout << mask << sp << sum << endl; 
	}
	cout << ans; 
}

