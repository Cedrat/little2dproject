#include <vector>
#include <string>
#include <iostream>
#include <array>
#include "resolution.hpp"

class gameMap
{
	public :
		gameMap();
		gameMap(resolution);
		~gameMap();

		void 			addLine(std::string const &line);
		unsigned int	getSizeY() const;
		unsigned int	getSizeX() const;
		unsigned int	findSizeX() const;
		void 			setSizeX(unsigned int value);
		// void 			stantardizeMap();
		void 			showMap() const;
		char getValueCase(int x, int y)const;


	private:
		size_t size_x;
		size_t size_y;
		char *map;
};
