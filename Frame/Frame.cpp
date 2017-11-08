#include "Frame.h"
#include <iostream>

Frame::Frame(int x, int y, std::string title)
    : RenderWindow(sf::VideoMode(x, y), title)
{
    setVerticalSyncEnabled(true);
}

Frame::~Frame()
{}

bool Frame::addComponent(Button& component)
{
    components.push_back(&component);
    addObserver(component);
    /*(*component.btn);
    display();*/
    return false;
}
bool Frame::start()
{
    while (isOpen())
    {
        // три метода // эвент, изменять, рисовать
        sf::Event event;
        while (pollEvent(event))
        {
            notifyAll(event);
            if (event.type == sf::Event::Closed)
            {
                close();
            }
            
        }
        //draw
        for (auto comp : components)
        {
            draw(*comp->btn);
        }
        //display
        display();
    }
    
    return false;
}

bool Frame::addObserver(Observer & observer)
{
    observers.push_back(&observer);
    return false;
}

bool Frame::removeObserver(const Observer & observer)
{
    return false;
}

void Frame::notifyAll(const sf::Event & event) const
{
    for (auto obs : observers)
    {
        obs->handleEvent(event);
    }
}



/*
bool  Frame::addObserver(const Observer& observer)
{
    observers.push_back(obs);
}

bool Frame::removeObserver(const Observer & obs)
{
    // delete obs from vector
    return false;
}

bool Frame::notifyAll(const sf::Event& event) const
{
    for (auto obs : observers)
    {
        obs.handleEvent(event);
    }
}
*/