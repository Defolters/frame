#ifndef OBSERVER_H
#define OBSERVER_H
#include <SFML/Graphics.hpp>
class Observer
{
public:
    virtual void handleEvent(const sf::Event& event) const = 0;
};
#endif // OBSERVER_H