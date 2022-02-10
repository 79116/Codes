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
 freopen("b_avoidingthecrows.out","w",stdout);
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
const int maxn = 205; 
int n, m, k; 
int score[maxn][maxn]; 
bool vs[maxn][maxn]; 
void dfs(int i, int j, int lim) { 
	vs[i][j] = 1; 
	for(int ti: {i, i + 1, i - 1}) { 
		for(int tj: {j - 1, j + 1, j}) { 
			if(abs(ti - i) + abs(tj - j) == 1 and ti >= 1 and ti <= n and tj >= 1 and tj <= m and !vs[ti][tj] and score[i][j] >= lim) dfs(ti, tj, lim); 
		}
	}
}
void solve() {
	cin >> n >> m >> k; 
	fori(i, 1, n) { 
		fori(j, 1, m) { 
			score[i][j] = n + m; 
		}
	}
	fori(d, 1, k) { 
		int x, y; cin >> x >> y; 
		fori(i, 1, n) fori(j, 1, m) score[i][j] = min(score[i][j], abs(i - x) + abs(j - y));
	}
//	fori(i, 1, n) { fori(j, 1, m) cout << score[i][j] << sp; cout << endl; }
	int hi = min(score[1][1], score[n][m]); 
	int lo = 0; 
	while(lo < hi) { 
		int mi = lo + hi + 1 >> 1; 
		fori(i, 1, n) fori(j, 1, m) vs[i][j] = 0; 
		dfs(1, 1, mi); 
		if(vs[n][m]) lo = mi; 
		else hi = mi - 1; 
	}
	cout << lo; 
}

