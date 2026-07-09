#include <iostream>
#include <vector>

int main()
{
	// Optimize standard I/O operations for speed
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	long long n;
	if (!(std::cin >> n)) return 0;

	// Sum from 1 to n is n * (n + 1) / 2.
	// If this sum is odd, we cannot divide it into two equal integer sum sets.
	// This happens when n % 4 == 1 or n % 4 == 2.
	if (n % 4 == 1 || n % 4 == 2) {
		std::cout << "NO\n";
	}
	else {
		std::cout << "YES\n";
		std::vector<long long> set1;
		std::vector<long long> set2;

		if (n % 4 == 0) {
			// Pair elements (i, n - i + 1) to form equal sums
			for (long long i = 1; i <= n / 2; i++) {
				if (i % 2 != 0) {
					set1.push_back(i);
					set1.push_back(n - i + 1);
				}
				else {
					set2.push_back(i);
					set2.push_back(n - i + 1);
				}
			}
		}
		else {
			// n % 4 == 3
			// First 3 elements are grouped as: set1 = {1, 2}, set2 = {3} (both sum to 3)
			set1.push_back(1);
			set1.push_back(2);
			set2.push_back(3);

			// Remaining elements from 4 to n are paired as (4 + i, n - i)
			long long remaining = n - 3;
			for (long long i = 0; i < remaining / 2; i++) {
				if (i % 2 == 0) {
					set1.push_back(4 + i);
					set1.push_back(n - i);
				}
				else {
					set2.push_back(4 + i);
					set2.push_back(n - i);
				}
			}
		}

		// Output Set 1
		std::cout << set1.size() << "\n";
		for (size_t i = 0; i < set1.size(); i++) {
			std::cout << set1[i] << (i + 1 == set1.size() ? "" : " ");
		}
		std::cout << "\n";

		// Output Set 2
		std::cout << set2.size() << "\n";
		for (size_t i = 0; i < set2.size(); i++) {
			std::cout << set2[i] << (i + 1 == set2.size() ? "" : " ");
		}
		std::cout << "\n";
	}

	return 0;
}
