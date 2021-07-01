#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	ll ans1 = 0, ans2 = 0;
	while (s1.size() != 0 && s3.size() != 0 && s1.back() == s3.back()) {
		ans1++;
		s1.pop_back();
		s3.pop_back();
	}
	while (s2.size() != 0 && s4.size() != 0 && s2.back() == s4.back()) {
		ans2++;
		s2.pop_back();
		s4.pop_back();
	}
	cout << max(ans1, ans2);
}
