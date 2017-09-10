//
//  rectangle.cpp
//  Lairs Subvert
//
//  Created by Wilma Eklund on 9/10/17.
//  Copyright © 2017 Wilma Eklund. All rights reserved.
//

#include <cmath>
#include "rectangle.hpp"
#include "globals.h"

using std::abs;

bool Rectangle::collide(const Rectangle& other) const {
    return x <= other.x + other.width &&
        other.x <= x + width &&
        y <= other.y + other.height &&
        other.y <= y + height;
}


void Rectangle::collideSolid(const Rectangle& collider) {
    if(collide(collider)&&!frozen) {
        
        /*
         M=me
         B=Bottom
         T=Top
         C=Collider
         L=Left
         R=Right
         D=Distance
         
         mybcytd = me y bottom to collider y top distance
         
         Do not edit unless completly understood.
         */
        int mybcytd = abs(y + height - collider.y);
        int mytcybd = abs(collider.y - y + collider.height);
        
        int mxrcxld = abs(x + width - collider.x);
        int mxlcxrd = abs(x - collider.x + width);
        
        if(mybcytd<mytcybd && mybcytd<mxlcxrd && mybcytd<mxrcxld) {
            
            y-=mybcytd;
            
        } else if(mytcybd<mybcytd && mytcybd<mxlcxrd && mytcybd<mxrcxld){
            
            y+=mytcybd;
            
        } else if(mxlcxrd<mybcytd && mxlcxrd<mytcybd && mxlcxrd<mxrcxld){
            
            x-=mxlcxrd;
            
        } else if(mxrcxld<mybcytd && mxrcxld<mytcybd && mxrcxld<mxlcxrd){
            
            x-=mxlcxrd;
            
        }
    }
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
