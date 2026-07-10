#include <iostream>

#include <set>

int main()

{

	std::set<int> set;

	int n;

	std::cin >> n;

	for (int i = 0; i < n; i++) {

		int temp;

		std::cin >> temp;

		set.insert(temp);

	}

	std::cout << set.size();

}
