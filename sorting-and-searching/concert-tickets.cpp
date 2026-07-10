#include <iostream>
#include <vector>
#include <set>
#include <iterator>

int main()
{
	int n;
	int m;

	std::cin >> n;
	std::cin >> m;

	std::multiset<int> price;
	std::vector<int> budget;

	for (int i = 0; i < n; i++) {
		int s;
		std::cin >> s;
		price.insert(s);
	}
	for (int i = 0; i < m; i++) {
		int s;
		std::cin >> s;
		budget.push_back(s);
	}
	for (int i = 0; i < m; i++) {
		auto it = price.upper_bound(budget[i]);
		if (it == price.begin()) {
			std::cout << -1 << ' ';
		}
		else {
			it--;
			std::cout << *it << ' ';
			price.erase(it);
		}
	}
}

