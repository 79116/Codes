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
   fori(test, 1, test_num) {
      solve();
   }
   return 0;
}

#define ld long double
#define int long long
const ld pi = 4 * atan(1.0), eps = 1e-9;
const int maxn = 1e7 + 7; 
bool ispr[maxn]; 
int ans[maxn]; 
void solve() {
	fill(ispr + 2, ispr + maxn, 1); 
	fori(i, 2, maxn - 1) { 
		if(ispr[i]) { 
			for(int j = i * i; j < maxn; j += i) { 
				ispr[j] = 0; 
			}
		}
	}
	fori(i, 3, maxn - 1) { 
		ans[i] = ans[i - 1] + i + ispr[i] * i; 
	}
	int q; 
	cin >> q; 
	fori(id, 1, q) { 
		int n; 
		cin >> n; 
		cout << ans[n] << endl; 
	}
}

