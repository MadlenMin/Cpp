#include "Zombie.hpp"

int main()
{
	int N = 4;
	Zombie* horde = zombieHorde(N, "Davide");
	if (horde == NULL)
	{
		std::cout << "Failed to create zombie horde" << '\n';
		return 1;
	}

	for (int i = 0; i < N; ++i)
	{
		horde[i].announce();
	}
	std::cout << "Destroying the horde" << '\n';
	delete[] horde;
	return 0;
}