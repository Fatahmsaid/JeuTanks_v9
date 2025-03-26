#include "Slider.h"
#include <algorithm> // Pour std::max et std::min

Slider::Slider(float x, float y, float width, float minValue, float maxValue, const std::string& title, sf::Font& font)
    : minValue(minValue), maxValue(maxValue), value((minValue + maxValue) / 2), isAdjusting(false) {
    bar.setSize(sf::Vector2f(width, 5));
    bar.setPosition(x, y);
    bar.setFillColor(sf::Color::Black);

    knob.setSize(sf::Vector2f(10, 20));
    knob.setPosition(x + (width / 2), y - 5);
    knob.setFillColor(sf::Color::Red);

    titleText.setFont(font);
    titleText.setString(title);
    titleText.setCharacterSize(14);
    titleText.setFillColor(sf::Color::Black);
    titleText.setPosition(x, y - 25);

    valueText.setFont(font);
    valueText.setCharacterSize(14);
    valueText.setFillColor(sf::Color::Black);
    valueText.setPosition(x + width + 10, y - 10);
    updateValueText();
}

void Slider::update(sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            float mouseX = static_cast<float>(event.mouseButton.x);
            float mouseY = static_cast<float>(event.mouseButton.y);

            if (mouseX >= knob.getPosition().x && mouseX <= knob.getPosition().x + knob.getSize().x &&
                mouseY >= knob.getPosition().y && mouseY <= knob.getPosition().y + knob.getSize().y) {
                isAdjusting = true;
            }
        }
    } else if (event.type == sf::Event::MouseButtonReleased) {
        isAdjusting = false;
    } else if (event.type == sf::Event::MouseMoved && isAdjusting) {
        float mouseX = static_cast<float>(event.mouseMove.x);
        float newX = std::max(bar.getPosition().x, std::min(mouseX, bar.getPosition().x + bar.getSize().x - knob.getSize().x));
        knob.setPosition(newX, knob.getPosition().y);
        value = minValue + ((newX - bar.getPosition().x) / (bar.getSize().x - knob.getSize().x)) * (maxValue - minValue);
        updateValueText();
    }
}

void Slider::updateValueText() {
    valueText.setString(std::to_string(static_cast<int>(value)));
}

void Slider::draw(sf::RenderWindow& window) {
    window.draw(bar);
    window.draw(knob);
    window.draw(titleText);
    window.draw(valueText);
}


// Slider class for adjustable parameters
// class Slider {
// public:
//     sf::RectangleShape bar;
//     sf::RectangleShape knob;
//     sf::Text titleText;
//     sf::Text valueText;
//     float minValue, maxValue, value;
//     bool isAdjusting;

//     Slider(float x, float y, float width, float minValue, float maxValue, const std::string& title, sf::Font& font)
//         : minValue(minValue), maxValue(maxValue), value((minValue + maxValue) / 2), isAdjusting(false) {
//         bar.setSize(sf::Vector2f(width, 5));
//         bar.setPosition(x, y);
//         bar.setFillColor(sf::Color::Black);

//         knob.setSize(sf::Vector2f(10, 20));
//         knob.setPosition(x + (width / 2), y - 5);
//         knob.setFillColor(sf::Color::Red);

//         titleText.setFont(font);
//         titleText.setString(title);
//         titleText.setCharacterSize(14);
//         titleText.setFillColor(sf::Color::Black);
//         titleText.setPosition(x, y - 25);

//         valueText.setFont(font);
//         valueText.setCharacterSize(14);
//         valueText.setFillColor(sf::Color::Black);
//         valueText.setPosition(x + width + 10, y - 10);
//         updateValueText();
//     }

//     // void update(sf::Event& event) {
//     //     if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
//     //         float mouseX = static_cast<float>(event.mouseButton.x);
//     //         if (mouseX >= knob.getPosition().x && mouseX <= knob.getPosition().x + knob.getSize().x) {
//     //             isAdjusting = true;
//     //         }
//     //     } else if (event.type == sf::Event::MouseButtonReleased) {
//     //         isAdjusting = false;
//     //     } else if (event.type == sf::Event::MouseMoved && isAdjusting) {
//     //         float mouseX = static_cast<float>(event.mouseMove.x);
//     //         float newX = std::max(bar.getPosition().x, std::min(mouseX, bar.getPosition().x + bar.getSize().x - knob.getSize().x));
//     //         knob.setPosition(newX, knob.getPosition().y);
//     //         value = minValue + ((newX - bar.getPosition().x) / (bar.getSize().x - knob.getSize().x)) * (maxValue - minValue);
//     //         updateValueText();
//     //     }
//     // }

//     void update(sf::Event& event) {
//         if (event.type == sf::Event::MouseButtonPressed) {
//             if (event.mouseButton.button == sf::Mouse::Left) {
//                 float mouseX = static_cast<float>(event.mouseButton.x);
//                 float mouseY = static_cast<float>(event.mouseButton.y);

//                 // Activer uniquement si la souris est sur ce curseur
//                 if (mouseX >= knob.getPosition().x && mouseX <= knob.getPosition().x + knob.getSize().x &&
//                     mouseY >= knob.getPosition().y && mouseY <= knob.getPosition().y + knob.getSize().y) {
//                     isAdjusting = true;
//                 }
//             }
//         } else if (event.type == sf::Event::MouseButtonReleased) {
//             isAdjusting = false; // Désactiver le réglage une fois le bouton relâché
//         } else if (event.type == sf::Event::MouseMoved && isAdjusting) {
//             float mouseX = static_cast<float>(event.mouseMove.x);
//             float newX = std::max(bar.getPosition().x, std::min(mouseX, bar.getPosition().x + bar.getSize().x - knob.getSize().x));
//             knob.setPosition(newX, knob.getPosition().y);

//             // Calculer la nouvelle valeur en fonction de la position
//             value = minValue + ((newX - bar.getPosition().x) / (bar.getSize().x - knob.getSize().x)) * (maxValue - minValue);
//             updateValueText(); // Mettre à jour le texte affichant la valeur
//         }
//     }


//     void updateValueText() {
//         valueText.setString(std::to_string(static_cast<int>(value)));
//     }

//     void draw(sf::RenderWindow& window) {
//         window.draw(bar);
//         window.draw(knob);
//         window.draw(titleText);
//         window.draw(valueText);
//     }
// };