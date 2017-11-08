#include "Button.h"
#include <iostream>


Button::Button(std::string lable)// : sf::RectangleShape(sf::Vector2f(40, 40))
{
    btn = new sf::RectangleShape(sf::Vector2f(40, 40));
    btn->setFillColor(sf::Color::Blue);
}

Button::~Button()
{
}

void Button::setPosition(int x, int y)
{
    btn->setPosition(x, y);
}

void Button::handleEvent(const sf::Event & event) const
{
    if ((event.type == sf::Event::MouseButtonPressed) & (event.mouseButton.button == sf::Mouse::Left))
    {
            if ((event.mouseButton.x > btn->getPosition().x) && event.mouseButton.x < btn->getPosition().x + btn->getSize().x)
            {
                if (event.mouseButton.y > btn->getPosition().y && event.mouseButton.y < btn->getPosition().y + btn->getSize().y)
                {
                    std::cout << "Button pressed" << std::endl;
                    btn->setFillColor(sf::Color::Yellow);
                }
            }
    }
}
