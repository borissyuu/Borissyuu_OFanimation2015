//
//  particleSystem.h
//  05_Firework
//
//  Created by Sin Lung Boris Yu on 2015-03-09.
//
//

#pragma once    
#include "ofMain.h"
#include "particle.h"

#define NUMCIRCLE 200

class particleSystem {
public:
    
    particleSystem (ofVec2f _pos);
    void update (ofVec2f force);
    void draw();
    
    vector<particle> particleList;
    ofVec2f pos;
    
    
};