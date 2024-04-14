#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <chrono>
#include <thread>
#include <vector>
#include <string>

// Need to add something here to wait until the user presses play to move on to the next screen.
// They must press play after changing the playback device on their spotify deivce. 


std::string getHardwareID()
{
    std::ifstream file("../temp_files/hardware_id.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening hardware_id.txt file.\n";
        return "";
    }
    std::string line;
    for (int i = 0; i < 1 && std::getline(file, line); ++i) {
        file.close();
        return line;
    }

    file.close();
    return "";
}


bool getRemote()
{
    // Read the remote file, if there is a play in the remote, then return true. Else, return false. 
    std::ifstream file("../temp_files/remote.txt");
    if(!file.is_open())
    {
        std::cerr << "Error opening remote.txt file.\n";
    }
    std::string line;
    for(int i = 0; i < 1 && std::getline(file, line); ++i) {
        file.close();
    }
    if(line == "play")
    {
        std::ofstream clear_file("../temp_files/remote.txt",std::ios::out | std::ofstream::trunc);
        std::cout << "Cleared remote file in welcome screen. \n";
        clear_file.close();
        return true;
    }
    else
        std::ofstream clear_file("../temp_files/remote.txt",std::ios::out | std::ofstream::trunc);
        std::cout << "Cleared remote file in welcome screen. \n";
        clear_file.close();
        return false;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode().width + 100, sf::VideoMode::getDesktopMode().height), "The Modern Jukebox");
    window.setFramerateLimit(60); // Limit frame rate
    window.clear(sf::Color{0x240A09FF});

    sf::Clock clock;

    // Set the font
    sf::Font font;
    if(!font.loadFromFile("dependencies/DMSans_36pt-Regular.ttf"))
    {
        std::cerr << "Error loading font" << std::endl;
    }

    std::string firstLine = "Welcome to The Modern Jukebox";
    sf::Text firstLine_sprite;
    firstLine_sprite.setString("Welcome to The Modern Jukebox");
    firstLine_sprite.setFillColor(sf::Color{0xF9A217FF});
    firstLine_sprite.setFont(font);
    firstLine_sprite.setCharacterSize(75);

    sf::FloatRect textRect = firstLine_sprite.getLocalBounds();
    firstLine_sprite.setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
    firstLine_sprite.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width/2.0f, sf::VideoMode::getDesktopMode().height/2.0f));


    sf::Text secondLine_sprite;
    secondLine_sprite.setString("Please Change Playback on Spotify to 'Raspodify'");
    secondLine_sprite.setFillColor(sf::Color{0xF9A217FF});
    secondLine_sprite.setFont(font);
    secondLine_sprite.setCharacterSize(40);

    sf::FloatRect textRect2 = secondLine_sprite.getLocalBounds();
    secondLine_sprite.setOrigin(textRect2.left + textRect2.width/2.0f, textRect2.top + textRect2.height/2.0f);
    secondLine_sprite.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width/2.0f, sf::VideoMode::getDesktopMode().height/2.0f + 100));


    sf::Text hardware_id_sprite;
    hardware_id_sprite.setString("Hardware ID: " + getHardwareID());
    hardware_id_sprite.setFillColor(sf::Color{0xFFFFFFFF});
    hardware_id_sprite.setFont(font);
    hardware_id_sprite.setCharacterSize(50);

    sf::FloatRect textRect3 = hardware_id_sprite.getLocalBounds();
    hardware_id_sprite.setOrigin(textRect3.left + textRect3.width/2.0f, textRect3.top + textRect3.height/2.0f);
    hardware_id_sprite.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width/2.0f, sf::VideoMode::getDesktopMode().height/2.0f + 300));

    sf::Text move_on_sprite;
    move_on_sprite.setString("Once done, press play to continue");
    move_on_sprite.setFillColor(sf::Color{0xF9A217FF});
    move_on_sprite.setFont(font);
    move_on_sprite.setCharacterSize(40);

    sf::FloatRect textRect4 = move_on_sprite.getLocalBounds();
    move_on_sprite.setOrigin(textRect4.left + textRect4.width/2.0f, textRect4.top + textRect4.height/2.0f);
    move_on_sprite.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width/2.0f, sf::VideoMode::getDesktopMode().height/2.0f + 200));

    bool end = false;

    // while (clock.getElapsedTime().asSeconds() <= 10) {
    while (!end) {
        
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::Resized) {
                window.setSize(sf::Vector2u(event.size.width, event.size.height));

            }
        }

       
        window.clear(sf::Color{0x240A09FF});
        window.draw(firstLine_sprite);
        window.draw(secondLine_sprite);
        window.draw(hardware_id_sprite);
        window.draw(move_on_sprite);
        window.display();

        // check for the play button being pressed:
        end = getRemote();
        
    }

    return 0;
}
