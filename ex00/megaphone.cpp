#include <iostream>
#include <string>

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	++av;
	while (*av)
	{
		while (**av)
			std::cout << (char)std::toupper((char)(*(*av)++));
		++av;
	}
	std::cout << std::endl;
	return 0;
}

// int	main(int ac, char **av)
// {
// 	if (ac < 2)
// 	{
// 		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
// 		return 0;
// 	}
// 	++av;
// 	while (*av)
// 	{
// 		while (**av)
// 		{
// 			if (**av >= 'a' && **av <= 'z')
// 				std::cout << (char)(*(*av)++ - ('a' - 'A'));
// 			else
// 				std::cout << (char)(*(*av)++);
// 		}
// 		++av;
// 	}
// 	std::cout << std::endl;
// 	return 0;
// }
