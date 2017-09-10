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

struct entity : public Rectangle{
    
    bool solid=true;
    string path;
    int id;
    sf::Texture spritetexture;
    sf::Sprite sprite;
    bool visible;
    
    entity(int a, int b, int w, int h, bool f,bool collideable, string imgpath, int identidication, bool v);
    //entity(const entity& other) : spritetexture(other.spritetexture), sprite(spritetexture),
    entity(const entity& other) = delete;
    void operator=(const entity& other) = delete;

    
    void BufferedCollider(Rectangle collider);
    
    void BufferedUpdate();
    
    void render(sf::RenderWindow& window);
    
    // entity() : Rectangle(0,0,0,0,true){};
};

#endif /* entity_hpp */
