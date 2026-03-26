#include <iostream>


void upper_case(char *str)
{
	int i;
	char c;
	i = 0;
	while(str[i])
	{
		if(str[i] >= 'a' && str[i] <= 'z')
			c = str[i] - 32;
		else 
			c = str[i];
		std::cout << c;
		i++;
	}
}

int main(int argc, char **argv)
{

	if(argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << "\n";
	else
	{
		int i = 1;
		while(argv[i])
		{
			upper_case(argv[i]);
			i++;
		}
		std::cout << "\n";
	}
	return (0);
}