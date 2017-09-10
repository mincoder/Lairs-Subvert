//
//  rectangle.cpp
//  Lairs Subvert
//
//  Created by Wilma Eklund on 9/10/17.
//  Copyright © 2017 Wilma Eklund. All rights reserved.
//

#include <cmath>
#include <algorithm>
#include "rectangle.hpp"
#include "globals.h"

using std::abs;
using std::min;

bool Rectangle::collidesWith(const Rectangle& other) const {
    return x <= other.x + other.width &&
        other.x <= x + width &&
        y <= other.y + other.height &&
        other.y <= y + height;
}

void Rectangle::moveOutOf(const Rectangle& solid) {
    if (!collidesWith(solid) || frozen) {
        return;
    }

    int topDist = y + height - solid.y;
    int bottomDist = solid.y + solid.height - y;

    int leftDist = x + width - solid.x;
    int rightDist = solid.x + solid.width - x;

    int minDist = min(min(topDist, bottomDist), min(leftDist, rightDist));

    if (minDist == topDist) y -= topDist;
    else if (minDist == bottomDist) y += bottomDist;
    else if (minDist == leftDist) x -= leftDist;
    else if (minDist == rightDist) x += rightDist;
}


void Rectangle::update() {
    if(!frozen) {

        x+=Xvel*elapsed.asSeconds()*400;
        float tmpYForce=Yvel;
        if(Yvel<=-(gravity*8)) {
            tmpYForce=-gravity*8;
        }
        y+=tmpYForce*elapsed.asSeconds()*400;

        if(Yvel<=gravity*2)
            Yvel+=gravity*elapsed.asSeconds()*400;

    }
}
