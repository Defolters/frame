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
        checkEvent();
        // change some
        updateFrame();
        // draw
        renderFrame();
        //display
        display();
    }
    
}

void Frame::addObserver(Observer & observer)
{
    observers.push_back(&observer);
}

void Frame::removeObserver(const Observer & observer)
{
    //remove    // delete obs from vector

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
        notifyAll(e);
        if (e.type == sf::Event::Closed)
        {
            close();
        }
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
