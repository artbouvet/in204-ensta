#include "input.hpp"


// Accesseur
Button Input::getButton() const {
    return button;
    }

// Gestion des inputs
void Input::InputHandler(Event event, RenderWindow &window){
    // Fermeture fenêtre si croix cliquée
    if(event.type == Event::Closed){
            window.close();
    }
    if(event.type == Event::KeyPressed){
        switch(event.key.code){
            case Keyboard::Left:
                button.left=true;
                break;
            case Keyboard::Right:
                button.right=true;
                break;
            case Keyboard::Up:
                button.up=true;
                break;
            case Keyboard::Down:
                button.down=true;
                break;
            case Keyboard::Space:
                button.space=true;
                break;
        }
    }
    if(event.type == Event::KeyReleased){
        switch(event.key.code){
            case Keyboard::Left:
                button.left=false;
                break;
            case Keyboard::Right:
                button.right=false;
                break;
            case Keyboard::Up:
                button.up=false;
                break;
            case Keyboard::Down:
                button.down=false;
                break;
            case Keyboard::Space:
                button.space=false;
                break;
        }
    }
}