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
 freopen("applerace.inp","r",stdin);
 freopen("applerace.out","w",stdout);
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

/* 
voi moi loai chi quan tam thang 1 dau tien va thang 2 dau tien. 

case 1: toan 1. 
-> chon k thang dau tien. 
voi moi thang no chi lay 1 lan: 1 hoac 2 -> chia thanh 2 tap? 
neu f1[i] < f2[i] -> f2[i] khong bh dc chon. 
neu f1[i] > f2[i] -> 
khi di den i, nhat dc mot so thang 1, mot so thang 2. Ta cu chon 1 nhieu nhat co the. ko du thi sao? con 1 so thang 2. ta chon thang 2 co 1 tuong ung xa nhat. 
*/
const int maxn = 2e5 + 5; 
int n, k;
char tp[maxn]; 
int c[maxn]; 
int fi[maxn]; 
int se[maxn]; 
int chal[maxn]; 
int ans; 
int cur; 
multiset<ii> cur_keys; 
int key[maxn]; 
int on[maxn]; 
vector<int> picks; 
void solve() {
	cin >> n >> k;
	fori(i, 1, k) { 
		fi[i] = se[i] = n + 1;  
	}
	fori(i, 1, n) { 
		cin >> tp[i] >> c[i]; 
		if(tp[i] == 'S') fi[c[i]] = min(fi[c[i]], i); 
		else se[c[i]] = min(se[c[i]], i); 
	}
	fori(i, 1, k) { 
		int p; 
		cin >> p; 
		chal[p] = i; 
	}
	fori(i, 1, k) on[fi[i]]++, key[se[i]] = fi[i]; 
	int ans = k; 
	fori(i, 1, n) { 
		cur += on[i]; fori(tt, 1, on[i]) picks.eb(i); 
		on[i] = 0; 
		if(key[i]) cur_keys.em(key[i], i); 
		while(cur < chal[i]) { 
			if(cur_keys.empty()) { 
				cout << "Lose"; 
				return; 
			}
			else {
				auto it = prev(cur_keys.end()); 
				if(it->fi > i) { 
					cur++;
					ans++; 
					picks.eb(it->se); 
					on[it->fi]--; 
				}
				cur_keys.erase(it);
			}
		}
	}
	sort(b_e(picks)); 
	cout << ans << sp << picks.size() << endl; 
	for(int p: picks) cout << p << sp;
}
/* 
6 3 
T 1 
T 2
T 3
S 1
S 2
S 3
1 2 3
```````````
5 2 
T 1 
T 2
T 1
S 1
T 1
2 5
``````````
6 4
T 1
T 2
T 4
S 1
S 2
S 3
3 5 5 6
```````````
6 4
T 1
T 2
T 3
S 1
S 2
S 3
4 5 6 6
*/
