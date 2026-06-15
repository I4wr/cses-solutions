#include <iostream>

int main()
{
	long long n;
	std::cin >> n;

	long long expected = n * (n + 1) / 2;

	long long m = 0;
	long long temp;
	for (int i = 0; i < n - 1; i++) {
		std::cin >> temp;
		m += temp;
	}
	std::cout << expected - m;

}
