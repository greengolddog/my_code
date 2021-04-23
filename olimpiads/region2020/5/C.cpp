#include <bits/stdc++.h>
#define ll long long
#define elif else if
using namespace std;

int main() {
	ll a,b,k,stc,c;
	string str;
	cin >> a >> b >> k;
	vector<int> arr(19, 0);
	arr[k] = 9;
	for (ll i = k+1; i < 19; i++) {
		arr[i] = arr[i-1]*9*2-9;
	}
	
	cout << stc;
}