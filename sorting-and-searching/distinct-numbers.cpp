#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	// Optimize standard I/O operations for speed
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n;
	if (!(std::cin >> n)) return 0;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	// Sort elements in-place to count unique values in O(1) auxiliary space
	std::sort(a.begin(), a.end());

	int distinct_count = 0;
	if (n > 0) {
		distinct_count = 1;
		for (int i = 1; i < n; i++) {
			if (a[i] != a[i - 1]) {
				distinct_count++;
			}
		}
	}

	std::cout << distinct_count << "\n";
	return 0;
}
