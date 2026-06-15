#include <iostream>

int main()
{
	int tests;
	std::cin >> tests;
	for (int i = 0; i < tests; i++) {
		long long y;
		long long x;
		std::cin >> y;
		std::cin >> x;
		if (y == 1 && x == 1) {
			std::cout << 1 << std::endl;
			continue;
		}
		long long tot = 0;

		if (y >= x) {
			tot = (y % 2 == 0) ? y * y : (y - 1) * (y - 1);
			if (y % 2 == 0) {
				std::cout << tot - (x-1) << std::endl;
			}
			else {
				std::cout << tot + x << std::endl;
			}
			continue;
		}
		else {
			tot = (x % 2 != 0) ? x * x : (x - 1) * (x - 1);
			if (x % 2 == 0) {
				std::cout << tot + y << std::endl;
			}
			else {
				std::cout << tot - (y - 1) << std::endl;
			}			
			continue;
		}
	}
	return 0;

}
