//
//  ofCircle.cpp
//  03_livingThing
//
//  Created by Sin Lung Boris Yu on 2015-02-22.
//
//

#include "walker.h"

void walker::setup() {
    
    pos.set(ofGetWindowSize()/2);
    
    colorScheme.loadImage("rainbow.jpg");
    
}


void walker::update() {
    
    int choice = ofRandom(6);
    
    if (choice < 3) pos.x++;
    if (choice == 3) pos.x--;
    if (choice == 4) pos.y++;
    if (choice == 5) pos.y--;
}

void walker::draw() {

    ofEnableAlphaBlending();
    ofSetColor(255, 255, 255, 100);
    
    ofVec2f mousePos;
    mousePos.x = ofGetMouseX();
    
    for (int i = 0; i < mousePos.x*3; i++){
        float x = ofNoise(ofGetElapsedTimef()*0.2, i*0.3)*ofGetWidth();
        float y = ofNoise(-ofGetElapsedTimef()*0.2, i*0.3)*ofGetHeight();
    
    ofColor col = getColorForPixel (ofMap(x, 0, ofGetWidth(), 0, colorScheme.width), ofMap(y, 0, ofGetWidth(), 0, colorScheme.height));
    
    //pos.x = getColorForPixel(ofMap(x, 0, ofGetWidth(), 0, colorScheme.width));
    
    pos.x = ofMap(x, 0, 1, 0, getColorForPixel(colorScheme.width.x));For3v3r
    
    col.a = 85;
    ofSetColor(col);
    
    
    ofCircle(pos, ofRandom(4,40));
    //ofCircle(x,y,ofRandom(4,40));
        
    }
}

ofColor walker::getColorForPixel(int _x, int _y) {
    
    if (_x < 0) _x = 0;
    if (_y < 0) _y = 0;
    if (_x >= (colorScheme.width)/2) _x = colorScheme.width-1;
    if (_y >= (colorScheme.height)/2) _y = colorScheme.height-1;
    
    return colorScheme.getColor(_x,_y);
}
