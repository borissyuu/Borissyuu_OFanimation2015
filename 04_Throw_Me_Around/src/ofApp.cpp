#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(0);
    
    myMover.setup(ofGetMouseX(), ofGetMouseY(), 1.0);
    gravity.set(0, 0.5);
    wind.set(0, 03.0);
    isThrown = false;
    
//    myMover.setup(ofVec2f(50, 50), ofVec2f(ofGetWindowWidth(), 500), 1.0);
//    gravity.set(0, 0.5);
//    wind.set(0, 0.5);
//    pct = 0;
}

//--------------------------------------------------------------
void ofApp::update(){

    //pct += 0.00;
    //pct = ofMap (ofGetMouseY(), 0, ofGetHeight(), 0, 1);
    
    
    myMover.resetForces();
    myMover.applyForce(gravity*myMover.mass); //need to apply mass to gravity. gravity applies different forces to different objects
    myMover.applyForce(wind); //applies a constant force to objects
    myMover.applyDamping(0.05*myMover.mass);
    myMover.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetColor(255);
    myMover.draw();
    
    if (ofGetMousePressed()) {
        ofLine(initThrow.x, initThrow.y, ofGetMouseX(), ofGetMouseY());
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    if (!isThrown) {
        initThrow.set(ofGetMouseX(), ofGetMouseY());
        isThrown = true;
    }

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

    myMover.pos.set(ofGetMouseX(), ofGetMouseY());
    //ofVec2f initVec;
    
    initVec.x = ofGetMouseX() - initThrow.x;
    initVec.y = ofGetMouseY() - initThrow.y;
    
    myMover.vel = initVec*0.5;
    isThrown = false;
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
