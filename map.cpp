#include "map.hpp"

gameMap::gameMap()
{
	size_x = 0;
	size_y = 0;
};

gameMap::gameMap(resolution map_size) :size_x(map_size.x), size_y(map_size.y)
{
	map = new char[size_x * size_y];
	map[0] = 0;
}

gameMap::~gameMap()
{

};

void gameMap::addLine(std::string const &line)
{
	int p = 0;
	int i = 0;

	while (map[p])
		p++;
	while (i < line.size())
	{
		map[p + i] = line[i];
		i++;
	}
	map[p + i] = 0;
}

unsigned int gameMap::getSizeY() const
{
	return(this->size_y);
}

unsigned int gameMap::getSizeX() const
{
	return(this->size_x);
}

void gameMap::setSizeX(unsigned int value)
{
	this->size_x = value;
}

void gameMap::showMap() const
{
	for (unsigned int i = 0; i < this->size_x * this->size_y;i++)
	{
		std::cout << map[i];
		if (((i + 1) % size_x) == 0)
			std::cout << std::endl;
	}
}

char gameMap::getValueCase(int x, int y) const
{
	return (map[x + y * size_y]);
}

// void gameMap::stantardizeMap() //Need to finish..
// {
// 	std::vector<char>::iterator it_begin = map.begin();
//
// 	int i = 0;
// 	std::cout << this->findSizeX() << std::endl;
// 	while (it_begin != map.end())
// 	{
// 		if (map[i] == '\n')
// 			map.erase(it_begin);
// 		i++;
// 		if (it_begin != map.end())
// 		it_begin++;
// 	}
// }
