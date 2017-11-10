#include "Frame.h"
#include "Button.h"

void main()
{
    Frame frame(320, 480, "Title");
    Button btn("Button!");
    btn.setPos(50, 50);
    //btn..
    frame.addComponent(btn);
    frame.start();
}