# Two Knights

## Goal

For every board size `k` from `1` to `n`, count the number of ways to place two identical knights on a `k x k` chessboard so they do not attack each other.

## Initial Idea

A direct approach is to count every possible pair of knight positions, then subtract every pair where the knights attack each other.

The total number of ways to place two identical knights on a `k x k` board is:

```text
C(k^2, 2) = k^2 * (k^2 - 1) / 2
```

This works because there are `k^2` squares, and after choosing one square there are `k^2 - 1` choices for the other knight. Since the knights are identical, each pair is counted twice, so we divide by `2`.

One brute-force way to count attacking pairs is to visit every square and check the knight moves that stay inside the board. This is useful for understanding the problem, but it does more work than needed.

```cpp
#include <iostream>
#include <vector>

int main()
{
	int n;
	std::cin >> n;

	std::vector<std::vector<int>> moves = {
		{2, 1},
		{2, -1},
		{1, 2},
		{1, -2}
	};

	for (int k = 1; k <= n; k++) {
		long long total = 1LL * k * k * (k * k - 1) / 2;

		for (int row = 0; row < k; row++) {
			for (int col = 0; col < k; col++) {
				for (int move = 0; move < 4; move++) {
					int next_row = row + moves[move][0];
					int next_col = col + moves[move][1];

					if (next_row >= 0 && next_row < k && next_col >= 0 && next_col < k) {
						total--;
					}
				}
			}
		}

		std::cout << total << '\n';
	}

	return 0;
}
```

## Efficient Counting

A knight attack always fits inside either a `2 x 3` rectangle or a `3 x 2` rectangle.

Each such rectangle contains exactly two attacking knight pairs.

On a `k x k` board:

```text
number of 2 x 3 rectangles = (k - 1) * (k - 2)
number of 3 x 2 rectangles = (k - 2) * (k - 1)
```

So the number of attacking pairs is:

```text
2 * ((k - 1) * (k - 2) + (k - 2) * (k - 1))
= 4 * (k - 1) * (k - 2)
```

The answer for each `k` is:

```text
k^2 * (k^2 - 1) / 2 - 4 * (k - 1) * (k - 2)
```

## Final Solution

```cpp
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
```

Time complexity: `O(n)`

Space complexity: `O(1)`
