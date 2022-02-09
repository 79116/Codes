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

#define int long long

void gen() { 
	ofstream cout("bytefest.inp"); 
	int n = 2000, edge_lim = 1e6, m_lim = (n - 1) * edge_lim; 
	vector<ii> E; 
	fori(i, 2, n) E.eb(i, rng() % (i - 1) + 1); 
	int add = rng() % n; 
	for(auto &t: E) { 
		t.fi += add; t.se += add; 
		if(t.fi > n) t.fi -= n; if(t.se > n) t.se -= n; 
	}
	cout << n << sp << rng() % m_lim + 1 << endl; 
	for(auto t: E) { 
		cout << t.fi << sp << t.se << sp << rng() % edge_lim + 1 << sp << rng() % edge_lim + 1 << endl; 
	}
}
int check() {  
	ifstream gc("bytefest.out"), bc("b_bytefest.out"); 
	string g, b; 
	gc >> g; 
	bc >> b; 
	cout << g << sp << b << endl; 
	return b == g; 
}
int32_t main() {
   int test_num = 100;
   fori(test, 1, test_num) {
      gen(); cout << "done" << endl; 
      system("bytefest"); 
//      system("b_bytefest"); 
//      if(check()) cout << "ac" << endl; 
//	  else return cout << "Wa", 0;  
   }
   return 0;
}

