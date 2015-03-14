//
//  particle.h
//  midterm_reflection
//
//  Created by Sin Lung Boris Yu on 2015-03-12.
//
//

#pragma once
#include "ofMain.h"

class Particle {
public:
    
    void setup(float x, float y, float z);
    
    void applyForce(ofVec3f force);
    void resetForce();
    void applyDampingForce(float damping);
    
    void update();
    void draw();
    
    ofVec3f pos, vel, acc, dampingForce;
};