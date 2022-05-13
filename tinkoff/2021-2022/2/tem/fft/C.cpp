#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef int ll;
typedef complex<double> cd;

const ll INF = 1'000'000'000;
const double PI = acos(-1);

template<typename T>
bool assign_max(T& a, T b) {
	if (b > a) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool assign_min(T& a, T b) {
	if (b < a) {
		a = b;
		return true;
	}
	return false;
}


vector<cd> fft(vector<ll>& arr, cd w) {
	ll n = arr.size();
	vector<cd> ans(n);
	if (n == 1) {
		ans[0] = arr[0];
	} else {
		vector<ll> odd, even;
		for (ll i = 0; i < n; i++) {
			if (i % 2 == 0) {
				even.push_back(arr[i]);
			} else {
				odd.push_back(arr[i]);
			}
		}
		vector<cd> e = fft(even, w * w);
		vector<cd> o = fft(odd, w * w);
		cd wt = 1;
		ll k = n / 2;
		for (ll i = 0; i < n; i++) {
			ans[i] = e[i % k] + wt * o[i % k];
			wt *= w;
		}
	}
	return ans;
}

vector<cd> fft(vector<ll>& arr) {
	ll x = 1;
	while (x < arr.size()) {
		x *= 2;
	}
	arr.resize(x, 0);
	return fft(arr, polar(1., 2 * PI / x));
}

vector<ll> ifft(vector<cd>& arr, cd w) {
	ll n = arr.size();
	vector<ll> ans;
	if (n == 1) {
		ans.push_back(round(real(arr[0])));
	} else {
		ll k = n / 2;
		cd wt = 1, wk = 1;
		vector<cd> o, e;
		for (ll i = 0; i < k; i++) {
			wk *= w;
		}
		for (ll i = 0; i < k; i++) {
			o.push_back((arr[i + k] - arr[i]) / (wt * wk - wt));
			e.push_back(arr[i] - o.back() * wt);
			wt *= w;
		}
		vector<ll> even = ifft(e, w * w);
		vector<ll> odd = ifft(o, w * w);
		for (ll i = 0; i < k; i++) {
			ans.push_back(even[i]);
			ans.push_back(odd[i]);
		}
	}
	return ans;
}

vector<ll> ifft(vector<cd>& arr) {
	vector<ll> ans = ifft(arr, polar(1., 2 * PI / arr.size()));
	return ans;
}

string to_binary(char c) {
	if (c == '0') {
		return "0000";
	}
	if (c == '1') {
		return "0001";
	}
	if (c == '2') {
		return "0010";
	}
	if (c == '3') {
		return "0011";
	}
	if (c == '4') {
		return "0100";
	}
	if (c == '5') {
		return "0101";
	}
	if (c == '6') {
		return "0110";
	}
	if (c == '7') {
		return "0111";
	}
	if (c == '8') {
		return "1000";
	}
	if (c == '9') {
		return "1001";
	}
	if (c == 'A') {
		return "1010";
	}
	if (c == 'B') {
		return "1011";
	}
	if (c == 'C') {
		return "1100";
	}
	if (c == 'D') {
		return "1101";
	}
	if (c == 'E') {
		return "1110";
	}
	if (c == 'F') {
		return "1111";
	}
	return "ABOBA";
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	string s1, s2;
	cin >> s1 >> s2;
	string s1b = "";
	for (auto i : s1) {
		s1b += to_binary(i);
	}
	vector<cd> ans(s1.size() / 2, 0);
	for (ll i = 0; i < 8; i++) {
		vector<ll> s11, s10, s21, s20;
		for (ll j = i; j < s1b.size(); j += 8) {
			s11.push_back(s1b[j] == '1');
			s10.push_back(s1b[j] == '0');
		}
		reverse(s11.begin(), s11.end());
		reverse(s10.begin(), s10.end());
		for (ll j = i; j < s2.size(); j += 8) {
			s21.push_back(s2[j] != '0');
			s20.push_back(s2[j] != '1');
		}
		s21.resize(ans.size(), 0);
		s20.resize(ans.size(), 0);
		vector<cd> n11 = fft(s11), n10 = fft(s10), n21 = fft(s21), n20 = fft(s20);
		ans.resize(n11.size(), 0);
		for (ll j = 0; j < ans.size(); j++) {
			ans[j] += n11[j] * n21[j] + n10[j] * n20[j];
		}
	}
	vector<ll> col = ifft(ans);
	col.resize(s1.size() / 2);
	reverse(col.begin(), col.end());
	for (ll i = 0; i < (s1.size() / 2 - s2.size() / 8 + 1); i++) {
		cout << col[i] << ' ';
	}
}
