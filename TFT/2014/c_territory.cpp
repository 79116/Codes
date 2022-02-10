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
const int maxn = 100005; 
int n = 100000, m = 200000, k, edge_lim = 1e9;
int c[maxn];  
int rand_int(int l, int r) { 
	return rng() % (r - l + 1) + l; 
}
void gen() { 
	ofstream cout("territory.inp"); 
	k = rng() % n + 1, 
	cout << n << sp << m << sp << k << endl; 
	fori(i, 1, n) c[i] = i; 
	shuffle(c + 1, c + n + 1, rng); 
	fori(i, 1, k) cout << c[i] << sp; cout << endl;  
	fori(i, 1, m) { 
		cout << rand_int(1, n) << sp << rand_int(1, n) << sp << rand_int(1, edge_lim) << endl; 
	}
}
bool check() { 
	ifstream gc("territory.out"), bc("b_territory.out"); 
	fori(i, 1, n) { 
		int g, b;gc >> g; bc >> b; 
		if(g - b) return 0; 
	}
	return 1; 
}
int32_t main() {
// freopen("test.inp","r",stdin);
// freopen("test.out","w",stdout);
   int test_num = 1;
   fori(test, 1, test_num) {
      gen(); 
//      system("territory"); 
//      system("b_territory"); 
//      if(check()) { 
//      	cout << "AC" << endl; 
//      }
//      else { 
//	      cout << "WA" << endl; 
//	      exit(0); 
//	  }
   }
   return 0;
}

