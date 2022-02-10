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
 freopen("territory.out","w",stdout);
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
const int maxn = 100000 + 5, inf = LLONG_MAX / 100ll; 
int n, m, k;
int c[maxn]; 
vector<ii> g[maxn]; 	
int dis[maxn]; 
int mark[maxn]; 
int get_mark(int u) { 
	if(mark[u] == -1) { 
		set<int> diff_marks;  
		bool mr = 0; 
		for(ii e: g[u]) { 
			int v = e.fi, l = e.se; 
			if(dis[v] + l == dis[u]) { 
				int t = get_mark(v); 
				diff_marks.em(t); 
				mr |= t == 0; 
			}
		}
		if(mr or diff_marks.size() > 1 or diff_marks.size() == 0) { 
			mark[u] = 0; 
		}
		else { 
			mark[u] = *diff_marks.begin(); 
		}
	}
	return mark[u]; 
}
void solve() {
	cin >> n >> m >> k; 
	if(k == 1) { 
		fori(i, 1, n) cout << 1 << sp; 
		return; 
	}
	fori(i, 1, k) { 
		cin>> c[i]; 
	}
	fori(i, 1, m) { 
		int u, v, l; 
		cin >> u >> v >> l; 
		g[u].eb(v, l); 
		g[v].eb(u, l); 
	}
	fill(dis + 1, dis + n + 1, inf); 
	priority_queue<ii, vector<ii>, greater<ii> > q; 
	fori(i, 1, k) q.em(0, c[i]), dis[c[i]] = 0; 
	while(q.size() ) { 
		int u = q.top().se, d = q.top().fi; q.pop(); 
		if(d > dis[u]) continue; 
		for(ii e: g[u]) { 
			int v = e.fi, l = e.se; 
			if(dis[v] > dis[u] + l) { 
				dis[v] = dis[u] + l; 
				q.em(dis[v], v);
			}
		}
	}
	fori(i, 1, n) { 
		mark[i] = -1; 
	}
	fori(i, 1, k) { 
		mark[c[i]] = i; 
	}
	fori(i, 1, n) cout << get_mark(i) << sp; 
				
}

