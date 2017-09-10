
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include <iostream>
#include <vector>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"
#include "rectangle.hpp"
#include "entity.hpp"
#include "globals.h"

using namespace sf;

class Player {

};

float unit = 0.0;

int main(int, char const**)
{

    unit=50.0/16.0;

    Sprite backgroundsprite;
    Texture backgroundtexture;
    backgroundtexture.loadFromFile("background.png");
    backgroundsprite.setTexture(backgroundtexture);
    backgroundsprite.setScale(unit*2, unit*2);

    // Create the main window
    RenderWindow window(VideoMode(1440, 900), "Lairs Subvert",Style::Fullscreen);
    // RenderWindow window(VideoMode(1440, 900), "Lairs Subvert");

    Entity player(50,350,50,100,false,true,"player.png",0,true);

    std::vector<std::vector<Entity*>> world(50);

    for(int i=0;i<50;i++) {
        for(int j=0;j<50;j++) {
            world[(size_t)i].push_back(new Entity(i*50,j*50+450,50,50,true,true,"dirt.png",0,true));
        }
    }

    for(int i=0;i<50;i++) {
        if(!(i>10&&i<26)) {
            world[(size_t)i][0] = new Entity(i*50,450,50,50,true,true,"grass.png",1,true);
        } else {
            world[(size_t)i][0] = new Entity(i*50,450,50,50,false,false,"grass.png",1,false);
        }
    }

    for(int i=0;i<50;i++) {
        if(i>10&&i<26) {
            world[(size_t)i][1] = new Entity(i*50,500,50,50,true,true,"grass.png",1,true);
        } else {
            world[(size_t)i][1] = new Entity(i*50,500,50,50,true,true,"dirt.png",1,true);
        }
    }
    player.setYVel(-5);
    
    player.setYVel(-15);
    
    const Rectangle floor(200,400,800,100,true);

    // Start the game loop

    Clock clock;
    Time lastUpdate;
    while (window.isOpen()) {

        // Process events
        Event event;
        while (window.pollEvent(event)) {

            // Close window: exit
            if (event.type == Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
                window.close();
            }
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space) {
                player.setYVel(-25);
            }
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Left) {
                player.setXVel(-1);
            }
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Right) {
                player.setXVel(1);
            }
            if (event.type == Event::KeyReleased && event.key.code == Keyboard::Left && player.Xvel < 0) {
                player.setXVel(0);
            }
            if (event.type == Event::KeyReleased && event.key.code == Keyboard::Right && player.Xvel > 0) {
                player.setXVel(0);
            }
        }

        while (lastUpdate + seconds(frameTime) <= clock.getElapsedTime()) {
            lastUpdate += seconds(frameTime);

            player.update();

            for(int i=0;i<50;i++) {
                for(int j=0;j<50;j++) {
                    world[i][j]->update();
                    player.BufferedCollider(*world[i][j]);
                }
            }
        }

        window.clear();

        window.draw(backgroundsprite);

        for(int i=0;i<50;i++) {
            for(int j=0;j<50;j++) {
                world[i][j]->render(window);
            }
        }

        player.render(window);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
