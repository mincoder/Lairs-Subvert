//
//  entity.hpp
//  Lairs Subvert
//
//  Created by Wilma Eklund on 9/10/17.
//  Copyright © 2017 Wilma Eklund. All rights reserved.
//

#ifndef entity_hpp
#define entity_hpp

#include <stdio.h>
#include "rectangle.hpp"

using namespace std;

struct Entity : public Rectangle {
    
    bool solid;
    string path;
    int id;
    sf::Texture spritetexture;
    sf::Sprite sprite;
    bool visible;
    
    Entity(int x, int y, int width, int height, bool frozen,
            bool solid, string imgpath, int identification, bool visible);
    //entity(const entity& other) : spritetexture(other.spritetexture), sprite(spritetexture),
    Entity(const Entity& other) = delete;
    void operator=(const Entity& other) = delete;

    
    void BufferedCollider(Rectangle collider);
    
    void BufferedUpdate();
    
    void render(sf::RenderWindow& window);
    
    // entity() : Rectangle(0,0,0,0,true){};
};

#endif /* entity_hpp */
