#include "Button.h"
#include <iostream>
#include "Frame.h"

Button::Button(std::string label)
{
    shape = new sf::RectangleShape(sf::Vector2f(100, 60));
    shape->setFillColor(sf::Color::Blue);

    font = new sf::Font;
    font->loadFromFile("Mashine.otf");

    this->label = new sf::Text(label, *font);
    this->label->setFillColor(sf::Color::White);
    this->label->setCharacterSize(16);
}

Button::~Button()
{
}

void Button::setPos(int x, int y)
{
    shape->setPosition(x, y);
    float a = x + shape->getSize().x / 2 - label->getGlobalBounds().width/2;
    float b = y + shape->getSize().y / 2 - label->getGlobalBounds().height/2;
    label->setPosition(a, b);
}

void Button::draw(Frame& frame)
{
    frame.draw(*shape);
    frame.draw(*label);
}

void Button::handleEvent(const sf::Event & event)
{
    
    if ((event.type == sf::Event::MouseButtonReleased) && (event.mouseButton.button == sf::Mouse::Left))
    {
        shape->setFillColor(sf::Color::Blue);
    }

    if ((event.type == sf::Event::MouseButtonPressed) && (event.mouseButton.button == sf::Mouse::Left))
    {
            if ((event.mouseButton.x > shape->getPosition().x) && 
                (event.mouseButton.x < shape->getPosition().x + shape->getSize().x) && 
                (event.mouseButton.y > shape->getPosition().y) && 
                (event.mouseButton.y < shape->getPosition().y + shape->getSize().y))
            {
                std::cout << "Button pressed" << std::endl;
                shape->setFillColor(sf::Color::Red);
            }
    }
}
