#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
typedef long double ldb;
typedef unsigned long long ull;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	if (n%2 == 0) {
		cout << "NOT POSSIBLE";
	}
	string s;
	cin >> s;
	string ans1 = "", ans2 = "", ans3 = "";
	for (ll i = 0; i < n/2; i++) {
		ans1 += s[i];
		if (s[i] != s[n/2+i+1]) {
			ans = "";
			break;
		}
	}
	
}
