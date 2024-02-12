#include "SnakeGame.hpp"
#include <iostream>
#include <cstdlib> // for rand()
#include <ctime> // for time()


SnakeGame::SnakeGame(unsigned int width, unsigned int height) : window(sf::VideoMode(width, height), "Snake Game") {
    boxSize = 20.f;
    snakeSpeed = 0.15f;
    maxLength = 5;
    direction = sf::Vector2f(boxSize, 0); // Start moving right by default

    // Initialize snake with a single rectangle at the center
    sf::RectangleShape head(sf::Vector2f(boxSize, boxSize));
    head.setFillColor(sf::Color::Green);
    head.setPosition(width / 2.f, height / 2.f);
    snake.push_front(head);

    spawnFood();
}

void SnakeGame::spawnFood() {
    food.setSize(sf::Vector2f(boxSize, boxSize));
    food.setFillColor(sf::Color::Red);

    // Generate random position for food
    foodPosition.x = boxSize * (rand() % (window.getSize().x / int(boxSize)));
    foodPosition.y = boxSize * (rand() % (window.getSize().y / int(boxSize)));

    food.setPosition(foodPosition);
}

void SnakeGame::update() {
    if (clock.getElapsedTime().asSeconds() > snakeSpeed) {
        moveSnake();
        checkCollision();
        clock.restart();
    }
}

void SnakeGame::moveSnake() {
    sf::RectangleShape newHead(snake.front());
    newHead.move(direction);
    snake.push_front(newHead);

    if (snake.front().getPosition() == food.getPosition()) {
        spawnFood();
        maxLength++;
    } else if (snake.size() > static_cast<size_t>(maxLength)) {
        snake.pop_back();
    }
}

void SnakeGame::checkCollision() {
    // Check if snake hits window borders
    if (snake.front().getPosition().x < 0 || snake.front().getPosition().x >= window.getSize().x ||
        snake.front().getPosition().y < 0 || snake.front().getPosition().y >= window.getSize().y) {
        std::cout << "Game Over!" << std::endl;
        window.close();
    }

    // Check if snake hits itself
    for (auto it = std::next(snake.begin()); it != snake.end(); ++it) {
        if (snake.front().getGlobalBounds().intersects(it->getGlobalBounds())) {
            std::cout << "Game Over!" << std::endl;
            window.close();
        }
    }
}

void SnakeGame::handleInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && direction != sf::Vector2f(0, boxSize)) {
        direction = sf::Vector2f(0, -boxSize);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && direction != sf::Vector2f(0, -boxSize)) {
        direction = sf::Vector2f(0, boxSize);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && direction != sf::Vector2f(boxSize, 0)) {
        direction = sf::Vector2f(-boxSize, 0);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && direction != sf::Vector2f(-boxSize, 0)) {
        direction = sf::Vector2f(boxSize, 0);
    }
}

void SnakeGame::render() {
    window.clear();

    // Draw snake
    for (const auto &segment : snake) {
        window.draw(segment);
    }

    // Draw food
    window.draw(food);

    window.display();
}

void SnakeGame::run() {
    while (window.isOpen()) {
        handleInput();
        update();
        render();
    }
}
