#ifndef OBSERVABLE_H
#define OBSERVABLE_H

class Observable
{
public:
    virtual void addObserver(Observer& observer) = 0;
    virtual void removeObserver(const Observer& observer) = 0;
    virtual void notifyAll(const sf::Event& event) const = 0;
};

#endif // OBSERVABLE_H
