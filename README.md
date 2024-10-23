# EVM Prototype

## Description
The EVM Prototype is a simple voting application built using the SFML (Simple and Fast Multimedia Library). This project allows users to cast votes for candidates, display results in a bar graph format, and restart the voting process. It showcases basic GUI interactions, sound effects, and graphical representations of data.

## Features
- **Voting System**: Users can vote for up to five candidates.
- **Results Display**: After voting, results are shown in a bar graph, illustrating the percentage of votes each candidate received.
- **Sound Effects**: Interactive sound effects play on button clicks.
- **Restart Voting**: Users can restart the voting process after viewing results.

## Technologies Used
- **SFML**: For graphics, audio, and window management.
- **C++**: The programming language used for development.

## Getting Started

### Prerequisites
- Install SFML library on your system. Refer to the [SFML official documentation](https://www.sfml-dev.org/) for installation instructions.
- Ensure you have a C++ compiler installed (GCC, Clang, etc.).

### Cloning the Repository
```bash
git clone https://github.com/Gola-k/EVMPrototype.git
cd evm-prototype
```

### Building the Project
1. Open your terminal/command prompt.
2. Navigate to the project directory.
3. Compile the project using your preferred C++ compiler. For example, using g++:
   ```bash
   g++ main.cpp -o EVMPrototype -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
   ```

   for macos:
   ```bash
   g++ -o EVMPrototype EVMPrototype.cpp -I/opt/homebrew/include -L/opt/homebrew/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
   ```

### Running the Project
Run the compiled executable:
```bash
./EVMPrototype
```

## Assets
- **Audio**: Ensure you have a sound file named `click.wav` in the project directory for sound effects.
- **Fonts**: The project requires `arial.ttf` font file to display text. Make sure it's in the project directory.

## Usage
1. Launch the application. You will see the candidate names displayed as buttons.
2. Click on a candidate's name to cast your vote. A sound effect will play upon clicking.
3. Click the "RESULTS" button to view the voting results in a graphical format.
4. Click the "EXIT" button to restart the voting process.

## Contributions
Feel free to contribute to this project! Open issues or submit pull requests for enhancements, bug fixes, or new features.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contact
For any questions or feedback, please reach out to [my email](mailto:kunalgola9930@gmail.com).
