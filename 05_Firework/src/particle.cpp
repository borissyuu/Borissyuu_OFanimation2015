//
//  particle.cpp
//  05_Firework
//
//  Created by Sin Lung Boris Yu on 2015-03-09.
//
//

#include "particle.h"

particle::particle (ofVec2f _pos) {
    
    pos.set(_pos);
    vel.x = ofRandom(-2, 2);
    vel.y = ofRandom(-1, -5);
    lifespan = 255.0;
}

void particle:: applyForces(ofVec2f force) {

    acc += force;
}

void particle:: resetForces() {
    
    acc *= 0;
}

//void particle::dampingForce(float damping) {
//    ofVec2f dampingForce;
//    dampingForce = vel.getNormalized() * damping * -1;
//}

void particle:: update() {
    
    vel += acc;
    pos += vel;
    
    if (lifespan > 0) lifespan -= 3.0;
    
}

void particle:: draw() {
    
    ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255),lifespan);
    ofCircle(pos, 2);
    
}