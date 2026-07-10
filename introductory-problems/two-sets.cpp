#include <iostream>
#include <vector>
int main()
{
	int n;
	std::cin >> n;

	if (n % 4 == 1 || n % 4 == 2) {
		std::cout << "NO";
	}
	else {
		std::cout << "YES" << std::endl;
		std::vector<int> set1;
		std::vector<int> set2;
		if (n % 4 == 0) {
			for (int i = 0; i < n / 2; i++) {
				if (i % 2 == 0) {
					set1.push_back(1 + i);
					set1.push_back(n - i);
				}
				else {
					set2.push_back(1 + i);
					set2.push_back(n - i);
				}
			}
			std::cout << set1.size() << std::endl;
			for (int val : set1) {
				std::cout << val << " ";
			}
			std::cout << std::endl;
			std::cout << set2.size() << std::endl;
			for (int val : set2) {
				std::cout << val << " ";
			}
		}
		else {
			set1.push_back(1);
			set1.push_back(2);
			set2.push_back(3);
			if (n > 3) {
				for (int i = 0; i < (n - 3) / 2; i++) {
					if (i % 2 == 0) {
						set1.push_back(4 + i);
						set1.push_back(n - i);
					}
					else {
						set2.push_back(4 + i);
						set2.push_back(n - i);
					}
				}
			}
			std::cout << set1.size() << std::endl;
			for (int val : set1) {
				std::cout << val << " ";
			}
			std::cout << std::endl;
			std::cout << set2.size() << std::endl;
			for (int val : set2) {
				std::cout << val << " ";
			}
		}
	}

	return 0;

}
