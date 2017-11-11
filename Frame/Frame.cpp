#include "Frame.h"
#include <iostream>

Frame::Frame(int x, int y, std::string title)
    : RenderWindow(sf::VideoMode(x, y), title)
{
    setVerticalSyncEnabled(true);
}

Frame::~Frame()
{}

void Frame::addComponent(Button& component)
{
    components.push_back(&component);
    addObserver(component);
}

void Frame::start()
{
    while (isOpen())
    {
        // event
        checkEvent();
        // change
        updateFrame();
        // draw
        renderFrame();
        // display
        display();
    }
    
}

void Frame::addObserver(Observer & observer)
{
    observers.push_back(&observer);
}

void Frame::removeObserver( Observer & observer)
{
    std::vector<Observer* >::iterator position = observers.begin();

    for (position = observers.begin(); position != observers.end(); position++) 
    {
        if (*position == &observer) 
        {
            observers.erase(position);
            break;
        }
    }
}

void Frame::notifyAll(const sf::Event & event) const
{
    for (auto obs : observers)
    {
        obs->handleEvent(event);
    }
}

void Frame::checkEvent()
{
    sf::Event e;
    while (pollEvent(e))
    {
        if (e.type == sf::Event::Closed)
        {
            close();
        }
        notifyAll(e);
    }
}

void Frame::updateFrame()
{
}

void Frame::renderFrame()
{
    for (auto& comp : components)
    {
        comp->draw(*this);
    }
}
