#include <iostream>

int main()
{
	int n;
	std::cin >> n;

	if (n == 2 || n == 3) {
		std::cout << "NO SOLUTION";
		return 0;
	}

	int odd = n - n / 2;
	int even = n / 2;

	for (int i = 0; i < odd; i++) {
		std::cout << 2 * (odd - (1 + i)) + 1 << ' ';
	}

	for (int i = 0; i < even; i++) {
		std::cout << 2 * (even - i) << ' ';
	}
}
