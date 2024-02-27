#include <iostream>
#include <exception>

double askDouble(const char* prompt)
{
	while (!std::cin.eof())
	{
		std::cout << prompt;
		double answer;
		if (std::cin >> answer)
		{
			return answer;
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	throw new std::exception("Reading value error.");
}

int main()
{
	try
	{
		double costPerPack = askDouble("Enter value of 1 pack of tiles: ");
		double areaPerPack = askDouble("Now enter the square metres covered by the pack: ");
		double width = askDouble("Enter the width of your floor: ");
		double height = askDouble("Now enter the height: ");

		double area = width * height;

		std::cout << "You need to cover a total of " << area << " square metres.\n"
			"The total will be: " << area / areaPerPack * costPerPack << '\n';
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << '\n';
	}

	return 0;
}