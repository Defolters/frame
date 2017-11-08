#ifndef BUTTON_H
#define BUTTON_H
#include "Observer.h"
#include <SFML/Graphics.hpp>
class Button : public Observer//, public sf::RectangleShape, public sf::Text
{
public:
    Button(std::string lable);
    ~Button();
    void setPosition(int x, int y);
    virtual void handleEvent(const sf::Event& event) const override;
//private:
    sf::RectangleShape* btn;
};

#endif // BUTTON_H