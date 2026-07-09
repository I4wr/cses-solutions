#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main()
{
	// Optimize standard I/O operations for speed
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n, m;
	long long k;
	if (!(std::cin >> n >> m >> k)) return 0;

	std::vector<long long> applicants(n);
	for (int i = 0; i < n; i++) {
		std::cin >> applicants[i];
	}

	std::vector<long long> apartments(m);
	for (int i = 0; i < m; i++) {
		std::cin >> apartments[i];
	}

	std::sort(applicants.begin(), applicants.end());
	std::sort(apartments.begin(), apartments.end());

	int count = 0;
	int j = 0;
	for (int i = 0; i < n; i++) {
		while (j < m) {
			if (std::abs(applicants[i] - apartments[j]) <= k) {
				count++;
				j++;
				break;
			}
			else if (applicants[i] > apartments[j] + k) {
				// The apartment is too small for applicant i.
				// Since applicants are sorted, this apartment can't fit any future applicant either.
				j++;
			}
			else {
				// The apartment is too large for applicant i.
				// Since apartments are sorted, all subsequent apartments will also be too large for applicant i.
				// Move to next applicant i+1.
				break;
			}
		}
	}

	std::cout << count << "\n";
	return 0;
}
