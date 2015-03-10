//
//  particleSystem.cpp
//  05_Firework
//
//  Created by Sin Lung Boris Yu on 2015-03-09.
//
//

#include "particleSystem.h"

particleSystem::particleSystem (ofVec2f _pos) {
    
     //pos.set(_pos);
    pos = _pos;
    
    for (int i = 0; i < NUMCIRCLE; i++) { //move for loop back to setup. if it was in update, then upon every mouse release, you would be running the for loop constantly. if it is in setup, it runs only once every time you press it
        
        particle particle(pos);
        particleList.push_back(particle);
    }
}

void particleSystem::update(ofVec2f force) {
    
    for (int i = 0; i < particleList.size(); i++) {
        particleList[i].resetForces();
        particleList[i].applyForces(force);
        particleList[i].update();
    }
    
//    while (particleList.size() > 1000) {
//        particleList.erase(particleList.begin());
//    }
}

void particleSystem::draw() {
    for (int i = 0; i < particleList.size(); i++) {
        particleList[i].draw();
    }
}