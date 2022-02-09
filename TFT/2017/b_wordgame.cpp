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
 freopen("wordgame.inp","r",stdin);
 freopen("b_wordgame.out","w",stdout);
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
const int maxn = 2505; 
int n; 
int g[maxn][maxn];
int ans = 0;  

void solve() {
	cin >> n; 
	fori(i, 1, n) fori(j, 1, n) { 
		cin >> g[i][j]; 
	}
	fori(row, 1, n) { 
		fori(c1, 1, n) { 
			fori(c2, c1 + 1, n) { 
				bool ok = 1; fori(cm, c1 + 1, c2 - 1) ok &= g[row][cm] >= max(g[row][c1], g[row][c2]); 
				ans += ok; 
			}
		}
	}
	fori(col, 1, n) { 
		fori(r1, 1, n) fori(r2, r1 + 1, n) { 
			bool ok = 1; fori(rm, r1 + 1, r2 - 1) ok &= g[rm][col] >= max(g[r1][col], g[r2][col]); 
			ans += ok; 
		}
	}
	cout << ans; 
}

