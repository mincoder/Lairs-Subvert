//
//  rectangle.hpp
//  Lairs Subvert
//
//  Created by Wilma Eklund on 9/10/17.
//  Copyright © 2017 Wilma Eklund. All rights reserved.
//

#ifndef rectangle_hpp
#define rectangle_hpp

#include <stdio.h>

struct Rectangle {

    enum class MoveStop {
        Free, StopX, StopY
    };

    // Compute the most important move stop, given different ones.
    static MoveStop combineStops(MoveStop a, MoveStop b);
    
    //Basic Display Info
    float x;
    float y;
    int width;
    int height;
    
    //Velocities
    float Xvel=0;
    float Yvel=0;
    
    float gravity = 0.013f;
    
    //Bools
    bool frozen;
    
    void addVel(float x, float y) {
        Xvel += x;
        Yvel += y;
    }
    
    void setXVel(float vel) {
        Xvel = vel;
    }
    
    void setYVel(float vel) {
        Yvel = vel;
    }
    
    Rectangle(int x, int y, int width, int height, bool frozen) :
		x(x), y(y), width(width), height(height), frozen(frozen)
	{}
    
    bool collidesWith(const Rectangle& other) const;
    
    MoveStop moveOutOf(const Rectangle& solid);

    void update();
};


#endif /* rectangle_hpp */
