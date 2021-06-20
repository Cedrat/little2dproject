#include "map.hpp"
#include <iostream>
#include <fstream>
#include <array>

resolution get_map_resolution(std::string path);

int main()
{
	resolution map_size = get_map_resolution("map.map");

	gameMap Field(map_size);
	std::ifstream 	my_map;
	std::string 	line;
	my_map.open("map.map");
	if (my_map.is_open())
	{
		while (std::getline(my_map, line))
		{
			Field.addLine(line);
		}
		my_map.close();
	}
	Field.showMap();
}

resolution get_map_resolution(std::string path)
{
	resolution 		map_res;
	std::string 	line;
	std::ifstream 	my_map;

	map_res.x = 0;
	map_res.y = 0;
	my_map.open(path);
	if (my_map.is_open())
	{
		while (std::getline(my_map, line))
		{
			map_res.y++;
			if (line.size() > map_res.x)
				map_res.x = line.size();
		}
		my_map.close();
	}
	return map_res;
}
