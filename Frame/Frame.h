#ifndef FRAME_H
#define FRAME_H
#include "Observer.h"
#include "Observable.h"
#include "Button.h"
#include "Component.h"
#include <SFML/Graphics.hpp>

class Frame : public sf::RenderWindow, Observable
{
public:
    Frame(int x, int y, std::string title);
    ~Frame();
    void addComponent(Component& component);
    void start();
    

private:
    virtual void addObserver(Observer& observer) override;
    virtual void removeObserver(Observer& observer) override;
    virtual void notifyAll(const sf::Event& event) const override;
    void checkEvent();
    void updateFrame();
    void renderFrame();

    std::vector<Observer* > observers;
    std::vector<Component* > components;
};

#endif //FRAME_H 
