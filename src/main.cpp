#include "SnakeGame.hpp"

int main() {
    srand(static_cast<unsigned>(time(NULL))); // Seed for random number generation

    SnakeGame game(800, 600);
    game.run();

    return 0;
}
