#include <iostream>
#include <vector>

int main()
{
	unsigned long long moves = 0;
	unsigned long long n;
	std::cin >> n;

	std::vector<unsigned long long> arr(n);
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}

	for (int i = 1; i < n; i++) {
		if (arr[i - 1] > arr[i]) {
			moves += arr[i - 1] - arr[i];
			arr[i] = arr[i - 1];
		}
	}
	std::cout << moves;
}
