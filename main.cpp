#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;

vvi f;

enum class Direction
{
	H,
	V,
	D
};

void solve(int n, int y, int x, const Direction& d) {
	++f[y][x];

	if (d == Direction::H || d == Direction::D) {
		if (x < n && -1 != f[y][x + 1]) {
			solve(n, y, x + 1, Direction::H);
		}
	}

	if (d == Direction::V || d == Direction::D) {
		if (y < n && -1 != f[y + 1][x]) {
			solve(n, y + 1, x, Direction::V);
		}
	}

	if (x < n && y < n &&
		-1 != f[y][x + 1] && -1 != f[y + 1][x] && -1 != f[y + 1][x + 1]) {
		solve(n, y + 1, x + 1, Direction::D);
	}
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	cin >> n;

	f = vvi(n + 1, vi(n + 1, 0));
	for (auto i = 1; i <= n; ++i) {
		for (auto j = 1; j <= n; ++j) {
			int x;
			cin >> x;

			if (1 == x) {
				f[i][j] = -1;
			}
		}
	}

	solve(n, 1, 2, Direction::H);

	cout << (-1 == f[n][n] ? 0 : f[n][n]);

	return 0;
}