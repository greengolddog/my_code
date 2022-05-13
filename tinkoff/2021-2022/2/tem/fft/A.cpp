#include <bits/stdc++.h>
typedef long long ll;

const ll INF = 9'000'000'000'000'000'000;
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

using namespace std;

vector<complex<double>> fft(vector<ll> arr, complex<double> w) {
	ll n = arr.size();
	if (n == 1) {
		vector<complex<double>> ans;
		ans.push_back(arr[0]);
		return ans;
	} else {
		vector<ll> even, odd;
		for (ll i = 0; i < n; i++) {
			if (i % 2 == 0) {
				even.push_back(arr[i]);
			} else {
				odd.push_back(arr[i]);
			}
		}
		vector<complex<double>> e = fft(even, w * w);
		vector<complex<double>> o = fft(odd, w * w);
		vector<complex<double>> ans(n);
		complex<double> wt = 1;
		ll k = n / 2;
		for (ll i = 0; i < n; i++) {
			ans[i] = e[i % k] + wt * o[i % k];
			wt *= w;
		}
		return ans;
	}
}

vector<complex<double>> fft(vector<ll> arr) {
	ll x = 1;
	while (x < arr.size()) {
		x *= 2;
	}
	arr.resize(x, 0);
	return fft(arr, polar(1., 2 * PI / x));
}

vector<ll> ifft(vector<complex<double>> arr, complex<double> w) {
	ll n = arr.size();
	vector<ll> ans;
	if (arr.size() == 1) {
		ans.push_back(round(real(arr[0])));
	} else {
		vector<complex<double>> e, o;
		complex<double> wt = 1, wk = 1;
		ll k = n / 2;
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

vector<ll> ifft(vector<complex<double>> arr) {
	return ifft(arr, polar(1., 2 * PI / arr.size()));
}

vector<ll> fft(vector<ll> f1, vector<ll> f2) {
	f1.resize(f1.size() + f2.size(), 0);
	f2.resize(f1.size(), 0);
	vector<complex<double>> a1 = fft(f1), a2 = fft(f2), ans;
	ans.resize(a1.size());
	for (ll i = 0; i < a1.size(); i++) {
		ans[i] = a1[i] * a2[i];
	}
	vector<ll> a = ifft(ans);
	while (a.back() == 0) {
		a.pop_back();
	}
	return a;
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	string s1, s2;
	cin >> s1 >> s2;
	if (s1 == "0" || s2 == "0") {
		cout << "0";
		return 0;
	}
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	if ((s1.back() == '-') != (s2.back() == '-')) {
		cout << '-';
	}
	if (s1.back() == '-') {
		s1.pop_back();
	}
	if (s2.back() == '-') {
		s2.pop_back();
	}
	vector<ll> f1(s1.size()), f2(s2.size());
	for (ll i = 0; i < s1.size(); i++) {
		f1[i] = s1[i] - '0';
	}
	for (ll i = 0; i < s2.size(); i++) {
		f2[i] = s2[i] - '0';
	}
	vector<ll> ans = fft(f1, f2);
	for (ll i = 0; i < ans.size() - 1; i++) {
		ans[i + 1] += ans[i] / 10;
		ans[i] %= 10;
	}
	reverse(ans.begin(), ans.end());
	for (auto i : ans) {
		cout << i;
	}
}
