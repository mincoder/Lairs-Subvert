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
    
    //Forces
    float Xforce=0;
    float Yforce=0;
    
    float gravity=0.13f;
    
    //Bools
    bool frozen;
    
    void addForce(float a, float b) {
        Xforce+=a;
        Yforce+=b;
    }
    
    void setXForce(float a) {
        Xforce=a;
    }
    
    void setYForce(float a) {
        Yforce=a;
    }
    
    Rectangle(int a, int b, int w, int h, bool f) {
        x=a;
        y=b;
        width=w;
        height=h;
        frozen=f;
        
    }
    
    bool collide(const Rectangle& collider) const;
    
    void collideSolid(const Rectangle& collider);

    void update();
};


#endif /* rectangle_hpp */
