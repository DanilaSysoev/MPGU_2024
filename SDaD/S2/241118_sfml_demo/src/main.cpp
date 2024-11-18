#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(200, 200), "My first SFML window");
    // window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    bool showRectangle = false;

    sf::CircleShape circle(20);
    circle.setFillColor(sf::Color::Blue);

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            switch(event.type) {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Button::Left)
                    showRectangle = !showRectangle;
                break;

            case sf::Event::Resized:
                window.setView(
                    sf::View(
                        sf::FloatRect(
                            0, 0, event.size.width, event.size.height
                        )
                    )
                );
            }
        }

        window.clear(sf::Color(128, 128, 128));

        if(showRectangle) {
            sf::RectangleShape rectangle (
                { window.getView().getSize().x / 2,
                  window.getView().getSize().y / 2 }
            );
            rectangle.setFillColor(sf::Color::Red);
            rectangle.setPosition(window.getView().getSize().x / 4,
                                  window.getView().getSize().y / 4);

            window.draw(rectangle);
        }
        
        window.draw(circle);
        window.display();
    }

    return 0;
}
