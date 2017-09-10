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

bool Rectangle::collide(const Rectangle& collider) const {
    if( (collider.x+collider.width<=x+width) && (collider.x+collider.width>=x) ) {
        
        if( (collider.y+collider.height<=y+height) && (collider.y+collider.height>=y) ) {
            
            return true;
            
        }
        
        if( (collider.y<=y+height) && (collider.y>=y) ) {
            
            return true;
            
        }
        if( (collider.y<=y) && (collider.y>=y+height) ) {
            
            return true;
            
        }
        
    }
    
    if( (collider.x<=x+width) && (collider.x>=x) ) {
        
        if( (collider.y+collider.height<=y+height) && (collider.y+collider.height>=y) ) {
            
            return true;
            
        }
        
        if( (collider.y<=y+height) && (collider.y>=y) ) {
            
            return true;
            
        }
        if( (collider.y<=y) && (collider.y>=y+height) ) {
            
            return true;
            
        }
        
    }
    
    if(collider.x<=x&&collider.x>=x+width) {
        if( (collider.y+collider.height<=y+height) && (collider.y+collider.height>=y) ) {
            
            return true;
            
        }
        
        if( (collider.y<=y+height) && (collider.y>=y) ) {
            
            return true;
            
        }
        if( (collider.y<=y) && (collider.y>=y+height) ) {
            
            return true;
            
        }
    }
    
    if(x==collider.x&&y==collider.y) {
        return true;
    }
    
    return false;
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
        
        x+=Xforce*elapsed.asSeconds()*400;
        float tmpYForce=Yforce;
        if(Yforce<=-(gravity*8)) {
            tmpYForce=-gravity*8;
        }
        y+=tmpYForce*elapsed.asSeconds()*400;
        
        if(Yforce<=gravity*2)
            Yforce+=gravity*elapsed.asSeconds()*400;
        
    }
}
