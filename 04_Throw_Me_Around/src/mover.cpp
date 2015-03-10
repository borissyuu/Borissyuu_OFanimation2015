//
//  mover.cpp
//  04_Throw_Me_Around
//
//  Created by Sin Lung Boris Yu on 2015-02-27.
//
//

#include "mover.h"
//
//void mover::setup(ofVec2f _initPos, ofVec2f _finalPos, float _mass) {
////    
////    initPos = _initPos;
////    finalPos = _finalPos;
////    mass = _mass;
//    
//}
//
//void mover::applyForce(ofVec2f force) {
//    
//    acc += force/mass;
//}
//
//void mover::resetForces() {
//    
//    acc+= 0;
//}
//
//void mover::applyDampingForce(float damping) {
//    
//    acc-= vel.getNormalized() * damping;
//}
//
//void mover::update(float _pct) {
//    
//    pct = _pct;
//    currentPos = initPos * (1 - pct) + finalPos * pct;
//    
//    vel += acc;
//    currentPos += vel;
//    
//    if (currentPos.x < 0) {
//        currentPos.x = 0;
//        vel.x *= -1; //so circle knows to go back to the middle
//    }
//    
//    if (currentPos.x > ofGetWidth()) {
//        currentPos.x = ofGetWidth();
//        vel.x *= -1;
//    }
//    
//    if (currentPos.y < 0) {
//        currentPos.y = 0;
//        vel.y *= 1; //so circle knows to go back to the middle
//    }
//    
//    if (currentPos.y > ofGetHeight()) {
//        currentPos.y = ofGetHeight();
//        vel.y *= -1;
//    }
//
//    
//}
//
//void mover::draw() {
//    
//    ofCircle(currentPos, 10 * mass);
//    
//    
//}
//
//void mover::setNewPosition(ofVec2f _newPos) {
//    
//    initPos = currentPos;
//    finalPos = _newPos;
//}






//on press set new position

void mover::setup(float _x, float _y, float _mass) {
    
    pos.set(_x, _y);
    mass = _mass;
}

void mover::resetForces() {
    
    acc*=0;
}

void mover::applyForce(ofVec2f _force) {
    
    acc += _force;
}

void mover::applyDamping(float damping) {
    
    acc -= vel.getNormalized()*damping;
}

void mover::update() {
    
        vel += acc;
        pos += vel;
    
        if (pos.x < 0) {
            pos.x = 0;
            vel.x *= -1; //so circle knows to go back to the middle
        }
    
        if (pos.x > ofGetWidth()) {
            pos.x = ofGetWidth();
            vel.x *= -1;
        }
    
        if (pos.y < 0) {
            pos.y = 0;
            vel.y *= 1; //so circle knows to go back to the middle
        }
    
        if (pos.y > ofGetHeight()) {
            pos.y = ofGetHeight();
            vel.y *= -1;
        }
}

void mover::draw() {
    
    ofCircle(pos, 10 * mass);
    
}