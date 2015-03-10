//
//  mover.h
//  04_Throw_Me_Around
//
//  Created by Sin Lung Boris Yu on 2015-02-27.
//
//

#pragma once
#include "ofMain.h"

class mover {
    
public:
    
//    void setup(ofVec2f _initPos, ofVec2f _finalPos, float _mass);
//    void update(float _pct);
//    void draw();
//    
//    void setNewPosition(ofVec2f _newPos);
//    //void setPointA (float _x, float _y);
//    
//    //Forces
//    void resetForces(); //to reset forces in the next frames
//    void applyForce(ofVec2f force);
//    void applyDampingForce(float damping);
//    
//    //ofVec2f vel, acc;
//    float mass;
//    
////private:
//    ofVec2f initPos, finalPos, currentPos, vel, acc;
//    float pct;
    
    void setup(float _x, float _y, float _mass);
    void update();
    void draw();
    
    void applyForce(ofVec2f _force);
    void resetForces();
    void applyDamping (float damping);
    
    ofVec2f pos, acc, vel;
    float mass;
    
    
};


