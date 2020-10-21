#include <SFML/Window/Event.hpp>

#include "InputManager.h"
#include "DisplayManager.h"
#include "EventKeyboard.h"
#include "EventMouse.h"
#include "LogManager.h"

df::InputManager::InputManager()
{
    setType("InputManager");
}



df::Keyboard::Key df::InputManager::examineKeyCode(sf::Event& Event)
{
    switch (Event.key.code)
    {
    case sf::Keyboard::Key::Unknown:
        return Keyboard::UNDEFINED_KEY;

    case sf::Keyboard::Key::A:
        return Keyboard::A;
    case sf::Keyboard::Key::B:
        return Keyboard::B;
    case sf::Keyboard::Key::C:
        return Keyboard::C;
    case sf::Keyboard::Key::D:
        return Keyboard::D;
    case sf::Keyboard::Key::E:
        return Keyboard::E;
    case sf::Keyboard::Key::F:
        return Keyboard::F;
    case sf::Keyboard::Key::G:
        return Keyboard::G;
    case sf::Keyboard::Key::H:
        return Keyboard::H;
    case sf::Keyboard::Key::I:
        return Keyboard::I;
    case sf::Keyboard::Key::J:
        return Keyboard::J;
    case sf::Keyboard::Key::K:
        return Keyboard::K;
    case sf::Keyboard::Key::L:
        return Keyboard::L;
    case sf::Keyboard::Key::M:
        return Keyboard::M;
    case sf::Keyboard::Key::N:
        return Keyboard::N;
    case sf::Keyboard::Key::O:
        return Keyboard::O;
    case sf::Keyboard::Key::P:
        return Keyboard::P;
    case sf::Keyboard::Key::Q:
        return Keyboard::Q;
    case sf::Keyboard::Key::R:
        return Keyboard::R;
    case sf::Keyboard::Key::S:
        return Keyboard::S;
    case sf::Keyboard::Key::T:
        return Keyboard::T;
    case sf::Keyboard::Key::U:
        return Keyboard::U;
    case sf::Keyboard::Key::V:
        return Keyboard::V;
    case sf::Keyboard::Key::W:
        return Keyboard::W;
    case sf::Keyboard::Key::X:
        return Keyboard::X;
    case sf::Keyboard::Key::Y:
        return Keyboard::Y;
    case sf::Keyboard::Key::Z:
        return Keyboard::Z;

    case sf::Keyboard::Key::Num0:
        return Keyboard::NUM0;
    case sf::Keyboard::Key::Num1:
        return Keyboard::NUM1;
    case sf::Keyboard::Key::Num2:
        return Keyboard::NUM2;
    case sf::Keyboard::Key::Num3:
        return Keyboard::NUM3;
    case sf::Keyboard::Key::Num4:
        return Keyboard::NUM4;
    case sf::Keyboard::Key::Num5:
        return Keyboard::NUM5;
    case sf::Keyboard::Key::Num6:
        return Keyboard::NUM6;
    case sf::Keyboard::Key::Num7:
        return Keyboard::NUM7;
    case sf::Keyboard::Key::Num8:
        return Keyboard::NUM8;
    case sf::Keyboard::Key::Num9:
        return Keyboard::NUM9;

    case sf::Keyboard::Key::F1:
        return Keyboard::F1;
    case sf::Keyboard::Key::F2:
        return Keyboard::F2;
    case sf::Keyboard::Key::F3:
        return Keyboard::F3;
    case sf::Keyboard::Key::F4:
        return Keyboard::F4;
    case sf::Keyboard::Key::F5:
        return Keyboard::F5;
    case sf::Keyboard::Key::F6:
        return Keyboard::F6;
    case sf::Keyboard::Key::F7:
        return Keyboard::F7;
    case sf::Keyboard::Key::F8:
        return Keyboard::F8;
    case sf::Keyboard::Key::F9:
        return Keyboard::F9;
    case sf::Keyboard::Key::F10:
        return Keyboard::F10;
    case sf::Keyboard::Key::F11:
        return Keyboard::F11;
    case sf::Keyboard::Key::F12:
        return Keyboard::F12;

    case sf::Keyboard::Key::Space:
        return Keyboard::SPACE;
    case sf::Keyboard::Key::Enter:
        return Keyboard::RETURN;
    case sf::Keyboard::Key::Escape:
        return Keyboard::ESCAPE;
    case sf::Keyboard::Key::Left:
        return Keyboard::LEFTARROW;
    case sf::Keyboard::Key::Right:
        return Keyboard::RIGHTARROW;
    case sf::Keyboard::Key::Up:
        return Keyboard::UPARROW;
    case sf::Keyboard::Key::Down:
        return Keyboard::DOWNARROW;
    case sf::Keyboard::Key::Pause:
        return Keyboard::PAUSE;
    case sf::Keyboard::Key::Subtract:
        return Keyboard::MINUS;
    case sf::Keyboard::Key::Add:
        return Keyboard::PLUS;
    case sf::Keyboard::Key::Tilde:
        return Keyboard::TILDE;
    case sf::Keyboard::Key::Period:
        return Keyboard::PERIOD;
    case sf::Keyboard::Key::Comma:
        return Keyboard::COMMA;
    case sf::Keyboard::Key::Slash:
        return Keyboard::SLASH;
    case sf::Keyboard::Key::LControl:
        return Keyboard::LEFTCONTROL;
    case sf::Keyboard::Key::RControl:
        return Keyboard::RIGHTCONTROL;
    case sf::Keyboard::Key::LShift:
        return Keyboard::LEFTSHIFT;
    case sf::Keyboard::Key::RShift:
        return Keyboard::RIGHTSHIFT;

    }
    return Keyboard::UNDEFINED_KEY;
}

df::InputManager& df::InputManager::getInstance()
{
    static InputManager inputManager;
    return inputManager;
}

int df::InputManager::startUp()
{
    if (DM.isStarted())
    {
        auto Window = DM.getWindow();
        if (Window)
        {
            Window->setKeyRepeatEnabled(false);
            Manager::startUp();
        }
    }
    else
    {
        return -1;
    }

    return 0;
}

void df::InputManager::shutDown()
{
    auto Window = DM.getWindow();
    if (Window)
    {
        Window->setKeyRepeatEnabled(true);
        Manager::shutDown();
    }
}



void df::InputManager::getInput()
{
    auto Window = DM.getWindow();
    if (Window)
    {
        sf::Event event;
        while (Window->pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed)
            {
                EventKeyboard newEvent;
                newEvent.setKeyboardAction(EventKeyboardAction::KEY_PRESSED);
                newEvent.setKey(examineKeyCode(event));
                onEvent(&newEvent);

                //LM.writeLog("KeyPress: %i", examineKeyCode(event));
                
                //sent to all objects;
            }

            if (event.type == sf::Event::KeyReleased)
            {
                EventKeyboard newEvent;
                newEvent.setKeyboardAction(EventKeyboardAction::KEY_RELEASED);
                newEvent.setKey(examineKeyCode(event));
                onEvent(&newEvent);
                //sent to all objects;
            }

            if (event.type == sf::Event::MouseMoved)
            {
                EventMouse newEvent;
                newEvent.setMouseAction(EventMouseAction::MOVED);
                df::Vector mousePosition (event.mouseMove.x, event.mouseMove.y);
                newEvent.setMousePosition(mousePosition);
                onEvent(&newEvent);
                //sent to all objects;
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    //sent to all objects;
                    EventMouse newEvent;
                    newEvent.setMouseAction(EventMouseAction::PRESSED);
                    newEvent.setMouseButton(Mouse::Button::RIGHT);
                    onEvent(&newEvent);

                    LM.writeLog("LMB");

                }
            }
        }

        //check specific keys
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            EventKeyboard newEvent;
            newEvent.setKeyboardAction(EventKeyboardAction::KEY_PRESSED);
            newEvent.setKey(Keyboard::Key::LEFTARROW);
            onEvent(&newEvent);
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            EventMouse newEvent;
            newEvent.setMouseAction(EventMouseAction::PRESSED);
            newEvent.setMouseButton(Mouse::Button::LEFT);
            onEvent(&newEvent);
        }
    }
}
