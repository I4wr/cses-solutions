#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int n;
	int m;
	int k;
	int count = 0;
	std::cin >> n;
	std::cin >> m;
	std::cin >> k;
	std::vector<int> applicants;
	std::vector<int> apartments;

	for (int i = 0; i < n; i++) {
		int s;
		std::cin >> s;
		applicants.push_back(s);
	}
	for (int i = 0; i < m; i++) {
		int d;
		std::cin >> d;
		apartments.push_back(d);
	}
	std::sort(applicants.begin(), applicants.end());
	std::sort(apartments.begin(), apartments.end());

	int j = 0;
	for (int i = 0; i < n; i++) {
		while (j < m) {
			if (applicants[i] >= apartments[j] - k && applicants[i] <= apartments[j] + k) {
				count++;
				j++;
				break;
			}
			else if (applicants[i] > apartments[j] + k) {
				j++;
			}
			else {
				break;
			}
		}
	}
	std::cout << count;
}
