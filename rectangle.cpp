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

Rectangle::MoveStop Rectangle::combineStops(Rectangle::MoveStop a, Rectangle::MoveStop b) {
    if (a == MoveStop::Free) {
        return b;
    }
    if (b == MoveStop::Free) {
        return a;
    }
    if (a == MoveStop::StopX) {
        return b;
    }
    return a;
}

bool Rectangle::collidesWith(const Rectangle& other) const {
    return x <= other.x + other.width &&
        other.x <= x + width &&
        y <= other.y + other.height &&
        other.y <= y + height;
}

Rectangle::MoveStop Rectangle::moveOutOf(const Rectangle& solid) {
    if (!collidesWith(solid) || frozen) {
        return MoveStop::Free;
    }

    int topDist = y + height - solid.y;
    int bottomDist = solid.y + solid.height - y;

    int leftDist = x + width - solid.x;
    int rightDist = solid.x + solid.width - x;

    int minDist = min(min(topDist, bottomDist), min(leftDist, rightDist));

    if (minDist == topDist) {
        y -= topDist;
        return MoveStop::StopY;
    } else if (minDist == bottomDist) {
        y += bottomDist;
        return MoveStop::StopY;
    } else if (minDist == leftDist) {
        x -= leftDist;
        return MoveStop::StopX;
    } else if (minDist == rightDist) {
        x += rightDist;
        return MoveStop::StopX;
    }
    return MoveStop::Free;
}

void Rectangle::update() {
    if (frozen) return;

    x += Xvel * frameTime * 400;

    Yvel += gravity;
    y += Yvel;

    /*
    float tmpYForce = Yvel;
    if (Yvel <= -gravity*8) {
        tmpYForce = -gravity*8;
    }
    y += tmpYForce * frameTime * 400;

    if (Yvel <= gravity*2)
        Yvel += gravity * frameTime * 400;
        */
}
