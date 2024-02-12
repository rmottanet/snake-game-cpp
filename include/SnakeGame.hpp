#ifndef SNAKEGAME_HPP
#define SNAKEGAME_HPP

#include <SFML/Graphics.hpp>
#include <deque>

class SnakeGame {
private:
    sf::RenderWindow window;
    sf::Clock clock;
    sf::Time elapsedTime;
    sf::RectangleShape food;
    sf::Vector2f foodPosition;
    std::deque<sf::RectangleShape> snake;
    sf::Vector2f direction;
    float boxSize;
    float snakeSpeed;
    int maxLength;

public:
    SnakeGame(unsigned int width, unsigned int height);
    void spawnFood();
    void update();
    void moveSnake();
    void checkCollision();
    void handleInput();
    void render();
    void run();
};

#endif // SNAKEGAME_HPP
