#include <SFML/Graphics.hpp>
#include "map.hpp"
#include "resolution.hpp"
#include "Character.hpp"
#include <unistd.h>

gameMap extract_map(char *path);

void draw_tiles(int x, int y, sf::RenderWindow &window, gameMap Field)
{
    sf::Texture tiles;
    tiles.loadFromFile("wood.png");
    sf::Vector2<float> res_tiles(tiles.getSize());
    sf::Sprite s_tiles(tiles);
    s_tiles.setPosition(x * 100, y * 100);
    s_tiles.scale(1000/Field.getSizeX()/res_tiles.x, 1000/Field.getSizeY()/res_tiles.y);
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
           if (Field.getValueCase(x, y) == '1')
            {
                draw_tiles(x, y, window, Field);    
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
    character.loadFromFile("redbrick.png");
    sf::Sprite  s_character(character);
    sf::Vector2<float> resolution_character(character.getSize());
    s_character.setScale(100/resolution_character.x,100/resolution_character.y);


    Character player1;

    float x = 101;
    float y = 101;
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
            player1.increaseHorizonAcceleration(0.2);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            player1.increaseHorizonAcceleration(-0.2);
        else if (((sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && player1.getVerticalAcceleration() == 3) && ((Field.getValueCase(x/100, (y+110)/100) == '1') || (Field.getValueCase((x + 100)/ 100, (y + 110)/100))== '1'))
            player1.increaseVerticalAcceleration(-34);
        else
            player1.divideHorizonAcceleration();
        if (Field.getValueCase((x+player1.getHorizonAcceleration())/100, y/100) != '1' && Field.getValueCase((x + 100 + player1.getHorizonAcceleration())/100, y/100)!= '1')
            x += player1.getHorizonAcceleration();
        
        if (Field.getValueCase(x/100, (y + 100 + player1.getVerticalAcceleration())/100)!= '1' && Field.getValueCase(x/100, (y + player1.getVerticalAcceleration())/100) != '1' 
         && Field.getValueCase((x + 100)/100, (y + 100 + player1.getVerticalAcceleration())/100)!= '1' && Field.getValueCase((x + 100)/100, (y + player1.getVerticalAcceleration())/100) != '1')
            y += player1.getVerticalAcceleration();
        player1.sufferFromGravity();

        std::cout << player1.getVerticalAcceleration() << std::endl;
        usleep(10);
    }

    return 0;
}
