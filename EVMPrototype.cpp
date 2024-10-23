#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

// Global vote variables
int vote1 = 0, vote2 = 0, vote3 = 0, vote4 = 0, vote5 = 0;

// Function prototypes
void format(sf::RenderWindow &window);
void displayGraph(sf::RenderWindow &window, bool &showResults);

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "EVM Prototype");
    
    // Load a sound buffer and create a sound object
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("click.wav")) {
        std::cerr << "Error loading sound file!" << std::endl;
        return -1;
    }
    sf::Sound clickSound;
    clickSound.setBuffer(buffer);

    bool showResults = false;
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
        return -1;
    }

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                    // Check for candidate buttons
                    if (mousePos.x > 280 && mousePos.x < 480) {
                        if (mousePos.y > 100 && mousePos.y < 130) {
                            vote1++;
                            clickSound.play();
                        } else if (mousePos.y > 150 && mousePos.y < 180) {
                            vote2++;
                            clickSound.play();
                        } else if (mousePos.y > 200 && mousePos.y < 230) {
                            vote3++;
                            clickSound.play();
                        } else if (mousePos.y > 250 && mousePos.y < 280) {
                            vote4++;
                            clickSound.play();
                        } else if (mousePos.y > 300 && mousePos.y < 330) {
                            vote5++;
                            clickSound.play();
                        }
                    }

                    // Check for results button
                    if (mousePos.x > 475 && mousePos.x < 580 && mousePos.y > 350 && mousePos.y < 380) {
                        showResults = true;
                    }
                }
            }
        }

        window.clear(sf::Color::White);

        if (showResults) {
            displayGraph(window, showResults);
        } else {
            format(window);
        }

        window.display();
    }

    return 0;
}

void format(sf::RenderWindow &window) {
    sf::Font font;
    font.loadFromFile("arial.ttf");

    sf::Text title("E V M", font, 40);
    title.setPosition(150, 40);
    window.draw(title);

    // Array of candidate names
    std::string candidates[] = {"Krishna", "Shekhar", "Parmila", "Hackentio", "Subash"};
    
    for (int i = 0; i < 5; ++i) {
        // Create candidate button
        sf::RectangleShape button(sf::Vector2f(200, 30));  // Width 200, height 30 for the buttons
        button.setPosition(280, 100 + i * 50);
        button.setFillColor(sf::Color::Blue);
        window.draw(button);

        // Create candidate name inside the button
        sf::Text candidate(candidates[i], font, 20);
        candidate.setPosition(300, 100 + i * 50);  // Adjust the position to center it inside the button
        window.draw(candidate);
    }

    // Result button
    sf::RectangleShape resultButton(sf::Vector2f(100, 30));
    resultButton.setPosition(475, 350);
    resultButton.setFillColor(sf::Color::Green);
    window.draw(resultButton);

    sf::Text resultText("RESULTS", font, 20);
    resultText.setPosition(485, 350);
    window.draw(resultText);
}

void displayGraph(sf::RenderWindow &window, bool &showResults) {
    int totalVotes = vote1 + vote2 + vote3 + vote4 + vote5;
    if (totalVotes == 0) totalVotes = 1;  // To avoid division by zero

    int percentages[] = {
        (vote1 * 100) / totalVotes,
        (vote2 * 100) / totalVotes,
        (vote3 * 100) / totalVotes,
        (vote4 * 100) / totalVotes,
        (vote5 * 100) / totalVotes
    };

    std::string candidates[] = {"Krishna", "Shekhar", "Parmila", "Hackentio", "Subash"};
    sf::Font font;
    font.loadFromFile("arial.ttf");

    for (int i = 0; i < 5; ++i) {
        // Draw a bar chart for each candidate
        sf::RectangleShape bar(sf::Vector2f(30, percentages[i] * 3));  // Scale by 3 for visual effect
        bar.setPosition(100 + i * 100, 300 - percentages[i] * 3);
        bar.setFillColor(sf::Color::Blue);
        window.draw(bar);

        sf::Text candidate(candidates[i], font, 20);
        candidate.setPosition(100 + i * 100, 310);
        window.draw(candidate);
    }

    // Exit button to reset the voting
    sf::RectangleShape exitButton(sf::Vector2f(100, 30));
    exitButton.setPosition(545, 400);
    exitButton.setFillColor(sf::Color::Red);
    window.draw(exitButton);

    sf::Text exitText("EXIT", font, 20);
    exitText.setPosition(565, 400);
    window.draw(exitText);

    // Mouse click to reset votes and go back to the voting screen
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (mousePos.x > 545 && mousePos.x < 645 && mousePos.y > 400 && mousePos.y < 430) {
                // Reset the voting system
                vote1 = vote2 = vote3 = vote4 = vote5 = 0;
                showResults = false;  // Go back to the voting screen
            }
        }
    }
}
