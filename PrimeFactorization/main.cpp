#include <iostream>

void primeFactors(int number)
{
	while (number % 2 == 0)
	{
		std::cout << 2 << " ";
		number /= 2;
	}

	for (int i = 3; i < sqrt(number); i += 2)
	{
		while (number % i == 0)
		{
			std::cout << i << " ";
			number /= i;
		}
	}

	if (number > 2)
		std::cout << number << " ";
}

int main()
{
	std::cout << "Enter a number to find all its Prime Factors: ";

	int n;

	std::cin >> n;

	primeFactors(n);

	return 0;
}