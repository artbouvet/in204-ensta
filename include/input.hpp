#ifndef INPUTHPP
#define INPUTHPP

#include <SFML/Graphics.hpp>
#include "grid.hpp"

using namespace sf;

struct Button {bool left, right, up, down, space;};

class Input{
    private:
        Button button;

    public:
        // Constructeur
        Input() : button{false, false, false, false, false}{}

        Button getButton() const;

        void InputHandler(Event event, RenderWindow &window);
};

#endif