#include "Button.h"
#include <iostream>
#include "Frame.h"

Button::Button(std::string label)
{
    shape = new sf::RectangleShape(sf::Vector2f(100, 60));
    shape->setFillColor(sf::Color::Blue);

    font = new sf::Font;
    font->loadFromFile("COMIC.TTF");

    this->label = new sf::Text(label, *font);
    this->label->setFillColor(sf::Color::White);
    this->label->setCharacterSize(14);
}

Button::~Button()
{
}

void Button::setPos(int x, int y)
{
    shape->setPosition(x, y);
    label->setPosition(x, y);
}

void Button::draw(Frame& frame)
{
    frame.draw(*shape);
    frame.draw(*label);
}

void Button::handleEvent(const sf::Event & event)
{
    if ((event.type == sf::Event::MouseButtonPressed) & (event.mouseButton.button == sf::Mouse::Left))
    {
            if ((event.mouseButton.x > shape->getPosition().x) && event.mouseButton.x < shape->getPosition().x + shape->getSize().x)
            {
                if (event.mouseButton.y > shape->getPosition().y && event.mouseButton.y < shape->getPosition().y + shape->getSize().y)
                {
                    std::cout << "Button pressed" << std::endl;
                    shape->setFillColor(sf::Color::Green);
                }
            }
    }
}
