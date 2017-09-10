
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

using namespace sf;

class Player {
    
};
Time elapsed;
float unit=0.0;

int main(int, char const**)
{
    
    unit=50.0/16.0;
    
    Sprite backgroundsprite;
    Texture backgroundtexture;
    backgroundtexture.loadFromFile("/Users/Will/Desktop/XCode/Lairs Subvert/Lairs Subvert/background.png");
    backgroundsprite.setTexture(backgroundtexture);
    backgroundsprite.setScale(unit*2, unit*2);
    
    // Create the main window
    RenderWindow window(VideoMode(1440, 900), "Lairs Subvert",Style::Fullscreen);
    
    entity player(50,350,50,100,false,true,"/Users/Will/Desktop/XCode/Lairs Subvert/Lairs Subvert/player.png",0,true);
    
    //entity world[20][20];
    std::vector<std::vector<entity*>> world(50);
    
    for(int i=0;i<50;i++) {
        //world[i].reserve(20);
        for(int j=0;j<50;j++) {
            world[(size_t)i].push_back(new entity(i*50,j*50+450,50,50,true,true,"/Users/Will/Desktop/XCode/Lairs Subvert/Lairs Subvert/dirt.png",0,true));
        }
    }
    
    for(int i=0;i<50;i++) {
        if(!(i>10&&i<26)) {
            world[(size_t)i][0] = new entity(i*50,450,50,50,true,true,"/Users/Will/Desktop/XCode/Lairs Subvert/Lairs Subvert/grass.png",1,true);
        } else {
            world[(size_t)i][0] = new entity(i*50,450,50,50,false,false,"/Users/Will/Desktop/XCode/Lairs Subvert/Lairs Subvert/grass.png",1,false);
        }
    }
    
    for(int i=0;i<50;i++) {
        if(i>10&&i<26) {
            world[(size_t)i][1] = new entity(i*50,500,50,50,true,true,"/Users/Will/Desktop/XCode/Lairs Subvert/Lairs Subvert/grass.png",1,true);
        } else {
            world[(size_t)i][1] = new entity(i*50,500,50,50,true,true,"/Users/Will/Desktop/XCode/Lairs Subvert/Lairs Subvert/dirt.png",1,true);
        }
    }
    
    player.setYForce(-5);
    
    //entity collider(200,200,50,50,false,true,"/Users/Will/Desktop/XCode/Lairs Subvert/Lairs Subvert/grass.png",0);
    const Rectangle floor(200,400,800,100,true);
    
    // Start the game loop
    
    Clock clock;
    int d = 0;
    while (window.isOpen())
    {
        
        window.clear();
        
        elapsed = clock.restart();
        
        window.draw(backgroundsprite);
        
        player.BufferedUpdate();
        
        for(int i=0;i<50;i++) {
            for(int j=0;j<50;j++) {
                player.BufferedCollider((*world[i][j]));
                world[i][j]->BufferedUpdate();
                world[i][j]->render(window);
            }
        }
        
        window.draw(player.sprite);
        
        // Process events
        Event event;
        while (window.pollEvent(event))
        {
            
            // Close window: exit
            if (event.type == Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
                window.close();
            }
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space) {
                player.setYForce(-25);
            }
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Left) {
                player.setXForce(-1);
            }
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Right) {
                player.setXForce(1);
            }
            if (event.type == Event::KeyReleased && (event.key.code == Keyboard::Left || event.key.code == Keyboard::Right)) {
                player.setXForce(0);
            }
            
        }

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
