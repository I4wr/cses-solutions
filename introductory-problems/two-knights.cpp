#include <iostream>

int main()
{
	long long n;
	std::cin >> n;

	for (long long k = 1; k <= n; k++) {
		long long squares = k * k;
		long long total = squares * (squares - 1) / 2;
		long long attacking = 4 * (k - 1) * (k - 2);

		std::cout << total - attacking << '\n';
	}

	return 0;
}
