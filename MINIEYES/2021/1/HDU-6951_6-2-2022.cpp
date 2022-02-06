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
// freopen("test.inp","r",stdin);
// freopen("test.out","w",stdout);
   ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   int test_num = 1;
   cin >> test_num; 
   fori(test, 1, test_num) {
      solve();
   }
   return 0;
}

#define ld long double
#define int long long
const ld pi = 4 * atan(1.0), eps = 1e-9;
const int maxn = 2e5 + 5; 
const int inf = INT_MAX; 
int n; 
int x[maxn];
int y[maxn]; 
int val[maxn]; 
int r[maxn]; 
struct pt { 
	int x, y, val, id, on; 
	pt(int _x, int _y, int _val, int _id) : x(_x), y(_y), val(_val), id(_id), on(0) {};
	pt() {}
} 
pts[maxn]; 
struct node { 
	int minx, maxx, miny, maxy, sum, cnt; 
	node(int _minx = inf, int _maxx = -inf, int _miny = inf, int _maxy = -inf) : minx(_minx), maxx(_maxx), miny(_miny), maxy(_maxy), sum(0), cnt(0) {};
} 
nodes[maxn]; 
int pos[maxn]; 
bool by_x(pt &a, pt &b) { return a.x < b.x; }
bool by_y(pt &a, pt &b) { return a.y < b.y; }
void build_kd(int tl, int tr, int tt) { 
	int tm = tl + tr >> 1; 
	nth_element(pts + tl, pts + tm, pts + tr + 1, (tt & 1? by_x: by_y)); 
	nodes[tm] = node(); 
	pos[pts[tm].id] = tm; 
	// normally minx, miny etc should be initialized here, but in this case they will be updated later. 
	if(tl < tm) build_kd(tl, tm - 1, tt ^ 1); 
	if(tm < tr) build_kd(tm + 1, tr, tt ^ 1); 
}
void turn_on(int tl, int tr, int id) { 
	int tm = tl + tr >> 1;
	nodes[tm].minx = min(nodes[tm].minx, x[id]); 
	nodes[tm].maxx = max(nodes[tm].maxx, x[id]); 
	nodes[tm].miny = min(nodes[tm].miny, y[id]); 
	nodes[tm].maxy = max(nodes[tm].maxy, y[id]);  
	nodes[tm].cnt++; 
	nodes[tm].sum += val[id]; 
	if(pos[id] == tm) pts[tm].on = 1; 
	else if(pos[id] < tm) turn_on(tl, tm - 1, id); 
	else turn_on(tm + 1, tr, id); 
}
int sqdis(int xa, int ya, int xb, int yb) { 
	int dx = xa - xb; 
	int dy = ya - yb; 
	return dx * dx + dy * dy; 
}
void get_sum(int tl, int tr, int x, int y, int r, int &ans) {
	int tm = tl + tr >> 1; 
	if(nodes[tm].cnt) {
		int cl_x = x; 
		int cl_y = y; 
		if(x < nodes[tm].minx) cl_x = nodes[tm].minx; 
		if(x > nodes[tm].maxx) cl_x = nodes[tm].maxx; 
		if(y < nodes[tm].miny) cl_y = nodes[tm].miny; 
		if(y > nodes[tm].maxy) cl_y = nodes[tm].maxy; 
		if(sqdis(cl_x, cl_y,x, y) <= r * r) { 
			bool contain = 1; 
			for(int tx: {nodes[tm].minx, nodes[tm].maxx}) { 
				for(int ty: {nodes[tm].miny, nodes[tm].maxy}) { 
					contain &= sqdis(tx, ty, x, y) <= r * r; 
				}
			}
			if(contain) { 
				ans += nodes[tm].sum; 
			}
			else { 
				if(pts[tm].on and sqdis(pts[tm].x, pts[tm].y, x, y) <= r * r) ans += pts[tm].val;
				if(tl < tm) get_sum(tl, tm - 1, x, y, r, ans);  
				if(tm < tr) get_sum(tm + 1, tr, x, y, r, ans); 
			}
		}
	}
}
void solve() {
	cin >> n; 
	fori(i, 1, n) { 
		cin >> x[i] >> y[i] >> val[i] >> r[i];
	}
	fori(i, 1, n) { 
		pts[i] = pt(x[i], y[i], val[i], i); 
	}
	build_kd(1, n, 0); 
	fori(i,1, n) {
		int ans = 0;
		turn_on(1, n, i);
		get_sum(1, n, x[i], y[i], r[i], ans);
		cout << ans << endl; 
	}
}

