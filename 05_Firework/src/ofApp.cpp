#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(200, 120, 30);
    //pos.set(ofGetWindowSize()/2);
    gravity.set(0.0, 0.1);
    //ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void ofApp::update(){

    for (int i = 0; i < systems.size(); i++) {
        systems[i].update(gravity);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    for (int i = 0; i < systems.size(); i++) {
        systems[i].draw();
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

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

    particleSystem system(ofVec2f(x, y));
    systems.push_back(system);
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
