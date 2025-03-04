#include <SFML/Graphics.hpp>
#include <iostream>
struct pix {
    unsigned char r; 
    unsigned char g;
    unsigned char b;
    unsigned char t;
};
int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");
    sf::CircleShape shape(600.f);
    sf::Image image;
    image.loadFromFile("1.bmp");
    sf::Texture texture;
    texture.loadFromImage(image);
    sf::Sprite sprite;
    sprite.setTexture(texture);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}
