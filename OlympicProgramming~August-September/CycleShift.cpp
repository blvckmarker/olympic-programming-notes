#include "GeometricBase.h"

using namespace std;

inline vector<int> const cycle_shift(vector<int> v, int k) 
{

	k %= v.size();

	for (int i = 0; i < k; ++i) {
		int x = v.back();
		v.pop_back();
		v.insert(v.begin(), x);
	}

	return v;
}

inline void cycle_shift_v2(vector<int>& v, int k) {
	k %= v.size();

	reverse(v.begin(), v.end());
	reverse(v.begin(), v.begin() + k);
	reverse(v.begin() + k, v.end());
}

int main() {

	int n, k;
	cin >> n >> k;

	vector<int> v(n);

	for (auto& x : v) 
		cin >> x;

	auto u = cycle_shift(v, k);

	cycle_shift_v2(v, k);

	for (auto x : u) 
		cout << x << " ";
	cout << "\n";


	for (auto x : v) 
		cout << x << " ";

	cout << "\n";

	return 0;
}