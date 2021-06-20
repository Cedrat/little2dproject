#include <SFML/Graphics.hpp>
#include "map.hpp"
#include "resolution.hpp"


gameMap extract_map(char *path);

void draw_tiles(int x, int y, sf::RenderWindow &window)
{
    sf::Texture tiles;
    tiles.loadFromFile("tile69.png");
    sf::Sprite s_tiles(tiles);
    s_tiles.setPosition(x * 100, y * 100);
    s_tiles.scale(8, 8);
    window.draw(s_tiles);
}
void draw_map(gameMap Field, sf::RenderWindow &window)
{
   int x = 0;
   int y = 0;
   int i = 0;

   while (y < Field.getSizeY())
   {
       while (x < Field.getSizeX())
       {
           if (Field.getValueCase(i) == '1')
            {
                draw_tiles(x, y, window);    
            }
            x++;
            i++;
       }
       y++;
       x = 0;
   } 
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
    gameMap Field;

    sf::Image image;
    sf::Texture bg;

    bg.create(1000,1000);
    bg.loadFromFile("mountainbg.png");
    sf::Vector2<float> resolution_image(bg.getSize());
    sf::Sprite bgi(bg);
    bgi.setScale(1000/resolution_image.x, 1000/resolution_image.y);
    Field = extract_map("map.map");

    sf::Texture character;
    character.loadFromFile("tile100.png");
    sf::Sprite  s_character(character);
    s_character.setScale(10,10);

    float x = 0;
    float y = 0;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(bgi);
        s_character.setPosition(x, y);
        window.draw(s_character);
        draw_map(Field, window);
        window.display();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            x+= 1;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            x-= 1; 
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            y+= 1;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            y-= 1;
    }

    return 0;
}
