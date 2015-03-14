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
    vel.y = ofRandom(5, -5);
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
    
    if (lifespan > 0) lifespan -= 5.0;
    
    tail.push_back(pos); //pos = position of the particle, we are adding the posiiton of the particle to the empty vector storage
    
    if (tail.size() > 100) {
        tail.erase(tail.begin());
    }
    
}

void particle:: draw() {
    
    ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255),lifespan);
    ofCircle(pos, 2);
    
    ofNoFill();
    ofSetLineWidth(5);
    ofBeginShape();
    for (ofPoint firetail : tail) { //same as for (firetail = 0; firetail < tail.size; firetail++)
        ofVertex(firetail); //ofVertex created by ofPoint
    }
    ofEndShape();
    
}