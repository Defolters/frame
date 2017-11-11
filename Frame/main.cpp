#include "Frame.h"
#include "Button.h"

void main()
{
    Frame frame(320, 480, "Title");
    Button btn("Button!");
    btn.setPos(50, 50);
    //btn..
    frame.addComponent(btn);
    Button btn1("Button2");
    btn1.setPos(150, 150);
    //btn..
    frame.addComponent(btn1);
    frame.start();
}