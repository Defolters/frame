#ifndef OBSERVABLE_H
#define OBSERVABLE_H
class Observable
{
public:
    virtual bool addObserver(Observer& observer) = 0;
    virtual bool removeObserver(const Observer& observer) = 0;
    virtual void notifyAll(const sf::Event& event) const = 0;
};

#endif // OBSERVABLE_H
