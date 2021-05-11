#include <bits/stdc++.h>
#define ll int64_t
#define elif else if

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	srand(time(0));
	ll n = rand()%10+1, m = rand()%21;
	cout << n << ' ' << m << endl;
	for (ll i = 0; i < m; i++) {
		cout << rand()%n+1 << ' ' << rand()%n+1 << ' ' << rand()%11 << endl;
	}
}
