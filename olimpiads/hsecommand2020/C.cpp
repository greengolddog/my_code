#include <bits/stdc++.h>
#define elif else if
using namespace std;
typedef long long ll;
typedef string str;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	str s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	ll mr = -1, ml = 0;
	for (ll i = 0; i < s1.size(); i++) {
		for (ll j = 0; j < s2.size(); j++) {
			for (ll k = 0; k < s3.size(); k++) {
				for (ll l = 0; l < min(s1.size()-i, min(s2.size()-j, s3.size()-k)); l++) {
					if ((s1[i+l] == s2[j+l]) && (s2[j+l] == s3[k+l])) {
						if (mr-ml <= l) {
							ml = i;
							mr = i+l;
						}
					} else {
						break;
					}
				}
			}
		}
	}
	for (ll i = ml; i <= mr; i++) {
		cout << s1[i];
	}
}
