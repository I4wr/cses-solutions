#include <iostream>

#include <vector>

#include <algorithm>

int main()

{

	int nChildren;

	int limit;

	int count = 0;

	std::cin >> nChildren;

	std::cin >> limit;

	std::vector<int> weight;

	for (int i = 0; i < nChildren; i++) {

		int s;

		std::cin >> s;

		if (s <= limit) {

			weight.push_back(s);

		}

	}

	std::sort(weight.begin(), weight.end());

	int i = 0;

	int j = nChildren-1;

	while (i <= j) {

		count++;

		if (weight[i] + weight[j] <= limit) {

			i++;

			j--;

		}

		else if (weight[i] + weight[j] > limit) {

			j--;

		}

	}

	std::cout << count;

}
