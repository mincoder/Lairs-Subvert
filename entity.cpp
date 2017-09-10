//
//  entity.cpp
//  Lairs Subvert
//
//  Created by Wilma Eklund on 9/10/17.
//  Copyright © 2017 Wilma Eklund. All rights reserved.
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "ResourcePath.hpp"
#include "entity.hpp"
#include "rectangle.hpp"
#include "globals.h"

entity::entity(int a, int b, int w, int h, bool f,bool collideable, string imgpath, int identidication, bool v) : Rectangle(a,b,w,h,f) {
        solid = collideable;
        path=imgpath;
        id=identidication;
        if (!spritetexture.loadFromFile(imgpath)) {
            cout << "Error could not load file: " << imgpath << endl;
        } else  {
            sprite.setTexture(spritetexture);
        }
        sprite.setScale(unit,unit);
        visible=v;
}

void entity::BufferedCollider(Rectangle collider) {
        if(solid) {
            collideSolid(collider);
        }
}

void entity::render(sf::RenderWindow& window) {
    if(visible) {
        window.draw(sprite);
    }
}

void entity::BufferedUpdate() {
    sprite.setPosition(x, y);
    update();
}
