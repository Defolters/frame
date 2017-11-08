#ifndef FRAME_H
#define FRAME_H
#include <SFML/Graphics.hpp>
#include "Observer.h"
#include "Observable.h"
#include "Button.h"
class Frame : sf::RenderWindow, Observable
{
public:
    Frame(int x, int y, std::string title);
    ~Frame();
    bool addComponent(Button& component);
    bool start();

    virtual bool addObserver(Observer& observer) override;
    virtual bool removeObserver(const Observer& observer) override;
    virtual void notifyAll(const sf::Event& event) const override;

private:
    std::vector<Observer* > observers;
    std::vector<Button* > components;

};
#endif //FRAME_H 
