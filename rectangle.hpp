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
    
    //Basic Display Info
    float x;
    float y;
    int width;
    int height;
    
    //Velocities
    float Xvel=0;
    float Yvel=0;
    
    float gravity=0.13f;
    
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
    
    bool collide(const Rectangle& collider) const;
    
    void collideSolid(const Rectangle& collider);

    void update();
};


#endif /* rectangle_hpp */
