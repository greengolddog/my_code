#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF = 9'000'000'000'000'000'000;
const db PI = acos(-1);

mt19937 rnd32(time(0));
mt19937_64 rnd64(time(0));

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

vector<cd> fft(vector<ll> arr, cd w) {
	ll n = arr.size();
	vector<cd> ans(n);
	if (n == 1) {
		ans[0] = arr[0];
	} else {
		vector<ll> even, odd;
		for (ll i = 0; i < n; i++) {
			if (i % 2 == 0) {
				even.push_back(arr[i]);
			} else {
				odd.push_back(arr[i]);
			}
		}
		vector<cd> e = fft(even, w * w), o = fft(odd, w * w);
		cd wt = 1;
		ll k = n / 2;
		for (ll i = 0; i < n; i++) {
			ans[i] = e[i % k] + wt * o[i % k];
			wt *= w;
		}
	}
	return ans;
}

vector<cd> fft(vector<ll> arr) {
	ll x = 1;
	while (x < arr.size()) {
		x *= 2;
	}
	arr.resize(x, 0);
	return fft(arr, polar(1., 2 * PI / x));
}

vector<ll> ifft(vector<cd> arr, cd w) {
	ll n = arr.size();
	vector<ll> ans;
	if (n == 1) {
		ans.push_back(round(real(arr[0])));
	} else {
		vector<cd> e, o;
		cd wt = 1, wk = 1;
		ll k = n / 2;
		for (ll i = 0; i < k; i++) {
			wk *= w;
		}
		for (ll i = 0; i < k; i++) {
			o.push_back((arr[i + k] - arr[i]) / (wt * wk - wt));
			e.push_back(arr[i] - o.back() * wt);
			wt *= w;
		}
		vector<ll> even = ifft(e, w * w), odd = ifft(o, w * w);
		for (ll i = 0; i < k; i++) {
			ans.push_back(even[i]);
			ans.push_back(odd[i]);
		}
	}
	return ans;
}

vector<ll> ifft(vector<cd> arr) {
	return ifft(arr, polar(1., 2 * PI / arr.size()));
}

struct col {
	vector<ll> arr;
	col(ll n = 0) {
		ll x = 1;
		while (x < n) {
			x *= 2;
		}
		arr.resize(x, 0);
	}
	void add(ll x) {
		arr[x]++;
	}
	void sub(ll x) {
		arr[x]--;
	}
	void add(col c) {
		for (ll i = 0; i < min(arr.size(), c.arr.size()); i++) {
			arr[i] += c.arr[i];
		}
	}
	void mul(ll x) {
		for (ll i = arr.size(); i > arr.size() / 2; i--) {
			arr[i] = 0;
		}
		for (ll i = arr.size() / 2; i >= 0; i--) {
			arr[i * 2] = arr[i];
			arr[i] = 0;
		}
	}
	void sub(col c) {
		for (ll i = 0; i < min(arr.size(), c.arr.size()); i++) {
			arr[i] -= c.arr[i];
		}
	}
	void div(ll x) {
		for (auto& i : arr) {
			i /= x;
		}
	}
	void mul(col c) {
		vector<cd> f1 = fft(arr), f2 = fft(c.arr);
		for (ll i = 0; i < min(f1.size(), f2.size()); i++) {
			f1[i] *= f2[i];
		}
		arr = ifft(f1);
	}
};

void dfs(ll v, ll p, vector<ll>& dp, vector<bool>& used, vector<vector<ll>>& arr) {
	dp[v] = 1;
	for (auto i : arr[v]) {
		if (i != p && !used[i]) {
			dfs(i, v, dp, used, arr);
			dp[v] += dp[i];
		}
	}
}

ll find_centroid(ll v, ll p, ll all, vector<ll>& size, vector<bool>& used, vector<vector<ll>>& arr) {
	for (auto i : arr[v]) {
		if (i != p && !used[i]) {
			if (size[i] > (all + 1) / 2) {
				return find_centroid(i, v, all, size, used, arr);
			}
		}
	}
	return v;
}

void count_col(ll v, ll p, vector<bool>& used, vector<ll>& dist, vector<vector<ll>>& arr, col& c) {
	dist[v] = dist[p] + 1;
	c.add(dist[v]);
	for (auto i : arr[v]) {
		if (i != p && !used[i]) {
			count_col(i, v, used, dist, arr, c);
		}
	}
}

col centroid(ll root, vector<bool>& used, vector<ll>& size, vector<vector<ll>>& arr) {
	dfs(root, root, size, used, arr);
	col c(size[root] * 2);
	ll sr = size[root];
	root = find_centroid(root, root, size[root], size, used, arr);
	size[root] = -1;
	count_col(root, root, used, size, arr, c);
	c.mul(c);
	used[root] = true;
	for (auto i : arr[root]) {
		if (!used[i]) {
			col c2(sr);
			count_col(i, root, used, size, arr, c2);
			c2.mul(c2);
			c.sub(c2);
		}
	}
	c.div(2);
	for (auto i : arr[root]) {
		if (!used[i]) {
			c.add(centroid(i, used, size, arr));
		}
	}
	return c;
}

void solve() {
	ll n;
	cin >> n;
	vector<vector<ll>> arr(n);
	ll root = 0;
	for (ll i = 1; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	vector<bool> used(n, false);
	vector<ll> size(n, 0);
	col c = centroid(root, used, size, arr);
	c.arr.resize(n, 0);
	for (ll i = 1; i < n; i++) {
		cout << c.arr[i] << ' ';
	}
	cout << '\n';
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t = 1;
	//cin >> t;
	for (ll i = 0; i < t; i++) {
		solve();
	}
}
