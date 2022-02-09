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
 freopen("territory.inp","r",stdin);
 freopen("b_territory.out","w",stdout);
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
const int maxn = 104, inf = LLONG_MAX / 100ll; 
int dis[maxn][maxn]; 
int c[maxn]; 
int ans[maxn]; 
int n, m, k; 
void solve() {
	cin >> n >> m >> k; 
	fori(i, 1, k) cin >> c[i]; 
	fori(i, 1, n) fori(j, 1, n) dis[i][j] = (i == j? 0: inf); 
	fori(i, 1, m) { 
		int u, v, l; cin >> u >> v  >> l; 
		dis[u][v] = dis[v][u] = min(dis[u][v], l); 
	}
	fori(k, 1, n) { 
		fori(i, 1, n) { 
			fori(j, 1, n) { 
				dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);
			}
		}
	}
	fori(i, 1, n) {
		ans[i] = -1; 
		vector<ii> al; 
		fori(j, 1, k) { 
			al.eb(dis[c[j]][i], j); 
		}
		sort(b_e(al)); 
		if(al.size() >= 2 and al[0].fi==al[1].fi) ans[i] = 0; 
		else ans[i] = al[0].se; 
		cout << ans[i] << endl; 
	}
}

