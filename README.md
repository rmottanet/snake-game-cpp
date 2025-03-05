# Snake Game 2D

Welcome to Snake Game 2D! This is a classic arcade-style game where you control a snake, guiding it to eat food and grow while avoiding collisions with walls and its own tail. This project utilizes C++ and the SFML library for graphics rendering and user input handling.

## Requirements

To compile and run Snake Game 2D, you need the following:

- **SFML (Simple and Fast Multimedia Library):** SFML is a cross-platform and easy-to-use library for developing multimedia applications and games in C++. It handles graphical rendering, keyboard input, and window events.
  
- **iostream:** Standard C++ library for input and output operations, used for printing messages to the console, such as "Game Over".
  
- **cstdlib and ctime:** Standard C++ libraries for time manipulation and random number generation, utilized for generating random positions for food and obtaining the current time.
  
- **deque:** Standard C++ double-ended queue data structure used for storing the segments of the snake in the game.

## Dependencies

Snake Game 2D depends on the following SFML libraries:

- `sfml-graphics`
- `sfml-window`
- `sfml-system`

## Usage

To compile the Snake Game 2D, you need to follow these steps:

1. **Create Directories:** Create `/bin` and `/build` directories in the root of the repository. You can do this using the following commands:

    ```bash
    mkdir bin
    mkdir build
    ```

2. **Compile with Makefile:** Navigate to the root directory of the project and run the following command in your terminal:

    ```bash
    make
    ```

    This command will compile the source files and link them with the necessary SFML libraries. After successful compilation, the executable will be placed in the `/bin` directory.

3. **Run the Game:** Execute the generated executable file located in the `/bin` directory:

    ```bash
    ./bin/snake_game
    ```

Enjoy playing Snake Game 2D!

---

Thank you for choosing Snake Game 2D! If you have any questions, issues, or suggestions, please don't hesitate to reach out. Happy gaming! 🐍🎮

<br />
<br />
<div align="center">
  <a href="https://bitbucket.org/rmottalabs/"><img alt="Static Badge" src="https://img.shields.io/badge/-Bitbucket?style=social&logo=bitbucket&logoSize=auto&label=Bitbucket&link=https%3A%2F%2Fbitbucket.org%2Frmottalabs%2Fworkspace%2Foverview%2F"></a>
  <a href="https://gitlab.com/rmottanet"><img alt="Static Badge" src="https://img.shields.io/badge/-Gitlab?style=social&logo=gitlab&logoSize=auto&label=Gitlab&link=https%3A%2F%2Fgitlab.com%2Frmottanet"></a>
  <a href="https://github.com/rmottanet"><img alt="Static Badge" src="https://img.shields.io/badge/-Github?style=social&logo=github&logoSize=auto&label=Github&link=https%3A%2F%2Fgithub.com%2Frmottanet"></a>
  <a href="https://hub.docker.com/"><img alt="Static Badge" src="https://img.shields.io/badge/-DockerHub?style=social&logo=docker&logoSize=auto&label=DockerHub&link=https%3A%2F%2Fhub.docker.com%2Fu%2Frmottanet"></a>
</div>
