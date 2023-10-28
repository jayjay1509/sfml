#ifdef _WIN32
#define _CRT_SECURE_NO_DEPRECATE
#endif // _WIN32


#include <SFML/Window/Window.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>



#include <SFML/Graphics.hpp>
#include <vector>
#define tilemap_windth 16
#define tilemap_height 12
static bool tilemap[tilemap_windth * tilemap_height] = { 0 };

// pour touve des bonne coulleur collorpicker

void save() 
{
    FILE* f = fopen("level.blabla", "wb");
    fwrite(tilemap, sizeof(tilemap), 1, f);
    fclose(f);
}

void laod()
{
    FILE* f = fopen("level.blabla", "rb");
    fread(tilemap, sizeof(tilemap), 1, f);
    fclose(f);
}

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML shapes", sf::Style::Default, settings);

   
    sf::RectangleShape Arrive(sf::Vector2f(50, 50));
    Arrive.setFillColor(sf::Color::Red);
    Arrive.setOutlineColor(sf::Color::Green);
    Arrive.setOutlineThickness(-3);
    Arrive.setPosition(15 * 50, 11 * 50);
    

    sf::RectangleShape rectangle(sf::Vector2f(50, 50));
    rectangle.setFillColor(sf::Color::Blue);
    rectangle.setOutlineColor(sf::Color::Green);
    rectangle.setOutlineThickness(-3);

    sf::RectangleShape tile_shape(sf::Vector2f(50, 50));
    tile_shape.setFillColor(sf::Color::Green);
    tile_shape.setOutlineColor(sf::Color::Green);
    tile_shape.setOutlineThickness(-3);

    sf::CircleShape shape(25.f);
    shape.setFillColor(sf::Color(100, 45, 0));
    sf::Vector2i shape_postion;


    while (window.isOpen())
    {
     
   

        sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
        sf::Vector2i mouse_tile_coord(mouse_pos.x / 50, mouse_pos.y / 50);

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (mouse_tile_coord.x < 0 || mouse_tile_coord.x >= tilemap_windth || mouse_tile_coord.y < 0 || mouse_tile_coord.y >= tilemap_height) {

            }
            else
            {
                tilemap[mouse_tile_coord.y * tilemap_windth + mouse_tile_coord.x] = true;
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
        {
            if (mouse_tile_coord.x < 0 || mouse_tile_coord.x >= tilemap_windth || mouse_tile_coord.y < 0 || mouse_tile_coord.y >= tilemap_height) {

            }
            else
            {
                tilemap[mouse_tile_coord.y * tilemap_windth + mouse_tile_coord.x] = false;
            }
        }


        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.isOpen();

            if (event.type == sf::Event::KeyPressed)
            {
                sf::Vector2i previous_pos = shape_postion;
                if (event.key.code == sf::Keyboard::Left)
                {
                    shape_postion.x -= 1;
                }
                else if (event.key.code == sf::Keyboard::Right)
                {
                    shape_postion.x += 1;
                }
                else if (event.key.code == sf::Keyboard::Up)
                {
                    shape_postion.y -= 1;
                }
                else if (event.key.code == sf::Keyboard::Down)
                {
                    shape_postion.y += 1;
                }
                // ceci est pour verifier si il sort des limite du jeu 
                if ((shape_postion.x < 0 || shape_postion.x >= tilemap_windth || shape_postion.y < 0 || shape_postion.y >= tilemap_height))
                {
                    shape_postion = previous_pos;
                }
                if (tilemap[shape_postion.y * tilemap_windth + shape_postion.x])
                {
                    shape_postion = previous_pos;
                }
                if (shape_postion.x == 15 && shape_postion.y == 11)
                {
                    window.close();
                }
                if (event.key.code == sf::Keyboard::F5)
                {
                    save();
                } 
                if (event.key.code == sf::Keyboard::F9)
                {
                    laod();
                }
            }

            window.clear(sf::Color::Black);


          

            for (size_t y = 0; y < tilemap_height; y++)
            {
                for (size_t x = 0; x < tilemap_windth; x++)
                {
                    if (tilemap[x + y * tilemap_windth])
                    {
                        tile_shape.setPosition(50 * x, 50 * y);
                        window.draw(tile_shape);
                    }

                }
            }
            std::cout << "la cordonne : " << mouse_tile_coord.x << "," << mouse_tile_coord.y << "\n";

            rectangle.setPosition((mouse_tile_coord.x * 50), mouse_tile_coord.y * 50);
            window.draw(rectangle);
            shape.setPosition(shape_postion.x*50, shape_postion.y*50);
            window.draw(shape);
            window.draw(Arrive);
            window.display();

          
        }
    }
    system("cls");
    std::cout << "\n\n\n\n\n\t\t\t\t\t\tfelicitation vous avez trouve le tresor\n\n\n";

    printf("    *             _____          ..-~---------------- ~-..-~\n");
    printf("   * *           |     |   \~~~\.'                    `./~~~/\n");
    printf("  *   *         ---------   \__/                        \__/\n");
    printf(" *     *       .'  O    \     /               /       \  '\n");
    printf("*       *     (_____,    `._.'               |         }  \/~~~/\n");
    printf("*********      `----.          /       }     |        /    \__/\n");
    printf("*       *            `-.      |       /      |       /      `. ,~~|\n");
    printf("*       *                ~-.__|      /_ - ~ ^|      /- _      `..-'\n");
    printf("*       *                     |     /        |     /     ~-.     `-. _  _  _\n");
    printf("*********                     |_____|        |_____|         ~ - . _ _ _ _ _>\n");
    std::cout << "tu veu rejoue : ";

    std::cout << "bas code moi par ce que je suis pas aassez fort pour faire sa ";

}
