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

#define ld long double
#define int long long
int n = 1e9, m = 1e9, k = 2000; 
void gen() { 
	ofstream cout("avoidingthecrows.inp"); 
	cout << n << sp << m << sp << k << endl; 
	fori(i, 1, k) { 
		cout << rng() % n + 1 << sp << rng() % m + 1 << endl; 
	}
}
bool check() { 
	ifstream gc("avoidingthecrows.out"), bc ("b_avoidingthecrows.out"); 
 	int g, b; 
 		gc >> g; bc >> b; 
	return g == b; 
}
int32_t main() {
// freopen("test.inp","r",stdin);
// freopen("test.out","w",stdout);
   int test_num = 10;
   fori(test, 1, test_num) {
      gen(); 
       system("avoidingthecrows"); 
       cout << "done" << endl; 
//       system("b_avoidingthecrows"); 
//       if(check()) cout << "ac" << endl; 
//	   else return cout << "wa", 0;  
   }
   return 0;
}

