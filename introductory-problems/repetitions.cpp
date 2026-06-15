#include <iostream>
#include <string>

int main()
{
	int longest = 0;
	int current = 0;
	std::string sequence;
	std::cin >> sequence;

	char last;
	last = sequence[0];

	for (char c : sequence) {
		if (c == last) {
			current += 1;
		}
		else {
			if (current > longest) {
				longest = current;
			}
			current = 1;
			last = c;
		}
	}
	if (current > longest) {
		longest = current;
	}
	std::cout << longest;
}
