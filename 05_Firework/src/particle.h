//
//  particle.h
//  05_Firework
//
//  Created by Sin Lung Boris Yu on 2015-03-09.
//
//

#pragma once
#include "ofMain.h"

class particle {
public:
    
    particle (ofVec2f _pos);
    
    void applyForces(ofVec2f force);
    void resetForces();
    //void dampingForce (float damping);
    
    void update();
    void draw();
    
    ofVec2f pos, acc, vel;
    
    vector<ofVec2f> tail; //create a vector storage for the tail 
    float lifespan;
    
    ofPoint firetail;
    
};