#include <iostream>
#include <vector>

bool isPrime(int n)
{
	if (n <= 1) return false;
	if (n <= 3) return true;

	if (n % 2 == 0 || n % 3 == 0) return false;

	for (int i = 5; i * i <= n; i += 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;
	
	return true;
}

int main()
{
	std::vector<int> prime_numbers;

	while (true)
	{
		std::cout << "Do you want to see Prime Number? (Y/N): ";

		char choice;

		std::cin >> choice;

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		choice = tolower(choice);

		switch (choice)
		{
		case 'y':

			if (prime_numbers.empty())
			{
				prime_numbers.push_back(3);
				std::cout << "3\n";
			}
			else 
			{
				for (int i = prime_numbers.back() + 1; ; i++)
				{
					if (isPrime(i))
					{
						prime_numbers.push_back(i);
						break;
					}
				}

				for (int n : prime_numbers)
				{
					std::cout << n << " ";
				}
				std::cout << '\n';
			}

			break;
		case 'n':
			exit(0);
			break;
		default:
			std::cout << "Enter Y or N.\n";
			break;
		}
	}

	return 0;
}