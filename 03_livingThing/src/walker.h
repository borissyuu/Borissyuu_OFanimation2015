//
//  ofCircle.h
//  03_livingThing
//
//  Created by Sin Lung Boris Yu on 2015-02-22.
//
//

#pragma once
#include "ofMain.h"

class walker {
public:
    
    void setup();
    void update();
    void draw();

    ofVec2f pos;
    
    float position;
    
    ofImage colorScheme;
    
    ofColor getColorForPixel(int _x, int _y);
    
};
