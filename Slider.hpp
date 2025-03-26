#ifndef SLIDER_H
#define SLIDER_H

#include <SFML/Graphics.hpp>
#include <string>

// Slider pour ajuster la puissance et la vitesse
class Slider {
public:
    sf::RectangleShape bar;
    sf::RectangleShape knob;
    sf::Text titleText;
    sf::Text valueText;
    float minValue, maxValue, value;
    bool isAdjusting;

    Slider(float x, float y, float width, float minValue, float maxValue, const std::string& title, sf::Font& font);
    void update(sf::Event& event);
    void draw(sf::RenderWindow& window);
    void updateValueText();
};

#endif // SLIDER_H
