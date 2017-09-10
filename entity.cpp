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

Entity::Entity(int x, int y, int width, int height, bool frozen,
		bool solid, string imgpath, int identification, bool visible) :
	Rectangle(x, y, width, height, frozen),
	solid(solid), id(identification), visible(visible)
{
	path = imgpath;
	if (!spritetexture.loadFromFile(imgpath)) {
		cout << "Error: could not load file: " << imgpath << endl;
		abort();
	} else  {
		sprite.setTexture(spritetexture);
	}
	sprite.setScale(unit,unit);
}

void Entity::BufferedCollider(Rectangle collider) {
	if(solid) {
		collideSolid(collider);
	}
}

void Entity::render(sf::RenderWindow& window) {
    if(visible) {
        window.draw(sprite);
    }
}

void Entity::BufferedUpdate() {
    sprite.setPosition(x, y);
    update();
}
