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
 freopen("avoidingthecrows.inp","r",stdin);
 freopen("avoidingthecrows.out","w",stdout);
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
const int maxn = 2005; 
int row_num, col_num; 
int n; 
int x[maxn], y[maxn];
vector<pair<int, ii> > E; 
int rt[maxn]; 
int ans; 
int getrt(int i) { 
	return rt[i] < 0? i: rt[i] = getrt(rt[i]); 
}
void join(int i, int j) { 
	i = getrt(i); j = getrt(j); 
	if(i == j) return; 
	if(rt[i] > rt[j]) { 
		swap(i, j); 
	}
	rt[i] = max(rt[i], rt[j] + 1); 
	rt[j] = i; 
}
inline int __abs(int x) { 
	return x < 0? -x: x; 
}
void solve() {
	cin >> row_num >> col_num; 
	cin >> n; 
	fori(i, 1, n) { 
		cin >> x[i] >> y[i];
	}
	fori(i, 1, n) { 
		E.eb(min(row_num - x[i], y[i] - 1), ii(i, 0)); 
		E.eb(min(x[i] - 1, col_num - y[i]), ii(i, n + 1)); 
	}
	fori(i, 1, n) { 
		fori(j, 1, n) { 
			int dis = __abs(x[i] - x[j]) + __abs(y[i] - y[j]), w; 
			if(dis % 2 == 0 and (x[i] != x[j] and y[i] != y[j])) { 
				w = dis / 2 - 1; 
			}
			else { 
				w = dis / 2; 
			}
			E.eb(w, ii(i, j));
		}
	}
	fori(i, 0, n + 1) rt[i] = -1; 
	sort(b_e(E)); 
	for(auto e: E) { 
		int w = e.fi, u = e.se.fi, v = e.se.se; 
		join(u, v); 
		if(getrt(n + 1) == getrt(0)) { 
			ans = w; 	
			break; 
		}
	}
	cout << ans; 
}
/*
3 3 1 
1 3
4 4 2 
1 2
3 2

*/

