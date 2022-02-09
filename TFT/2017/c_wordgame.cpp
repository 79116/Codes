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


int val_lim = 10; 
int n = 40;
void gen() { 
	ofstream cout("wordgame.inp"); 
	cout << n << endl; 
	fori(i, 1, n) { 
		fori(j, 1, n) { 
			cout << rng() % val_lim + 1 << sp; 
		}
		cout << endl; 
	}
}
bool check() { 
	ifstream gc("wordgame.out"), bc("b_wordgame.out"); 
	int g, b; 
	gc >> g; bc >> b;
	cout << g << sp << b << endl; 
	return g == b; 
}

int32_t main() {
// freopen("test.inp","r",stdin);
// freopen("test.out","w",stdout);
//   ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   int test_num = 100;
   fori(test, 1, test_num) {
      gen(); 
      system("wordgame"); 
      system("b_wordgame"); 
      if(check()) cout << "ac" << endl; 
	  else  { 
	  	cout << "wa" << endl;  
	  	return 0; 
	  }
   }
   return 0;
}

