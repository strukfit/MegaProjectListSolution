#include <iostream>
#include <vector>


int main()
{
	std::cout << "Enter the number up to which the Fibonacci sequence will be generated: ";
	
	int n;

	std::cin >> n;

	switch (n)
	{
	case 0:
		std::cout << "0\n";
		break;
	case 1:
		std::cout << "0 1 1\n";
		break;
	default:
		int f;

		std::vector<int> fibonacci{ 0, 1 };

		std::cout << "0 1 ";

		for (int i = 2; ; i++)
		{

			f = fibonacci[i - 1] + fibonacci[i - 2];

			if (f > n)
				break;

			fibonacci.push_back(f);

			std::cout << f << " ";
		}
		std::cout << "\n";
	}

	return 0;
}