#ifndef BUTTON_H
#define BUTTON_H
#include "Component.h"
//#include "Frame.h" // Ask teacher
#include <SFML/Graphics.hpp>

class Frame;
class Button : public Component 
{
public:
    Button(std::string label);
    ~Button();
    void setPos(int x, int y);
    virtual void draw(Frame& frame) override;

private:
    virtual void handleEvent(const sf::Event& event) override;
    sf::RectangleShape* shape;
    sf::Text* label;
    sf::Font* font;
};

#endif // BUTTON_H