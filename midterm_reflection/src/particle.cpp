//
//  particle.cpp
//  midterm_reflection
//
//  Created by Sin Lung Boris Yu on 2015-03-12.
//
//

#include "Particle.h"

void Particle::setup(float x, float y, float z) {
    
    pos.x = x;
    pos.y = y;
    pos.z = z;
}


void Particle::applyForce(ofVec3f force) {
    
    acc += force;
}


void Particle::resetForce() {
    
    acc += 0;
}


void Particle::applyDampingForce(float damping) {
 
    dampingForce = vel.getNormalized() * damping * -1;
    acc += dampingForce;
}


void Particle::update() {
    
    vel += acc;
    pos += vel;
}


void Particle::draw() {
    
    ofSetColor(255);
    ofCircle(pos, 1);
    
}
