#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    ofBackground(0);
    
    mesh.setMode(OF_PRIMITIVE_POINTS);
    
//VIDEO GRABBER CODE//
    
//initialize vidGrabber
    vidGrabber.setVerbose(true);
    
//storing the cam Width and Height
    camWidth 		= 320;	// try to grab at this size.
    camHeight 		= 240;
    
//changed to 1 to get feed from webcam
    vidGrabber.setDeviceID(1);
    //vidGrabber.setDesiredFrameRate(60);
    vidGrabber.initGrabber(camWidth,camHeight);
    
//video grabber code//
    
//PARTICLE CODE//
    for (int i = 0; i < camWidth; i++) { //particles = pixels
        for (int j = 0; j < camHeight; j++) {
            
            Particle myParticle;
        
            float x = ofRandomWidth();
            float y = ofRandomHeight();
            myParticle.setup(x, y, 0);
        
            particleList.push_back(myParticle);
        }
    }
//PARTICLE CODE//
    
    
//SET UP MESH//
    for (int i = 0; i < particleList.size(); i++) {
        for (int j = 0; j < particleList.size(); j++) {
        
            mesh.addVertex(particleList[i].pos);
            mesh.addVertex(particleList[j].pos);
            //offsets.push_back(ofVec3f(ofRandom(10), ofRandom(10), 1));
        
            }
        }
//SET UP MESH//
        
////ADD INDEXES//
//        float connectionDistance = 10;
//        int numVerts = mesh.getNumVertices();
//        
//        for (int a = 0; a < numVerts; a++) {
//            ofVec3f verta = mesh.getVertex(a);
//            for (int b = a+ 1; b < numVerts; b++) {
//                ofVec3f vertb = mesh.getVertex(b);
//                float distance = verta.distance(vertb);
//                if (distance <= connectionDistance) {
//                    mesh.addIndex(a);
//                    mesh.addIndex(b);
//            }
//        }
//        
//    }
    
    for (int i = 0; i < particleList.size(); i++) {
        for (int j = 0; j < particleList.size(); j++) {
            
            mesh.addIndex(i + j * camWidth);
            mesh.addIndex((i + 1) + j * camWidth);
            mesh.addIndex(i + (j + 1) * camWidth);
            
            mesh.addIndex((i + 1) + j * camWidth);
            mesh.addIndex((i + 1) + (j + 1) * camWidth);
            mesh.addIndex(i + ( j+ 1) * camWidth);
            
            mesh.addColor(ofFloatColor(0, 0, 0));

            
        }
        
    }
    
    cam.setScale(1, -1, 1);
}

//--------------------------------------------------------------
void ofApp::update(){
    
//VIDEO GRABBER CODE//
    
//grabs a new frame
    vidGrabber.update();
    
    if (vidGrabber.isFrameNew()){
//        int totalPixels = camWidth*camHeight*3;
//        unsigned char * pixels = vidGrabber.getPixels();
//        for (int i = 0; i < totalPixels; i++){
//            videoInverted[i] = 255 - pixels[i];
//        }
//        videoTexture.loadData(videoInverted, camWidth,camHeight, GL_RGB);
        
        for (int k = 0; k < vidGrabber.getWidth() * vidGrabber.getHeight(); k++) {
            ofFloatColor sampleColor (vidGrabber.getPixels()[k*3]/255.f,
                                      vidGrabber.getPixels()[k*3+1]/255.f,			                            vidGrabber.getPixels()[k*3+2]/255.f);
            mesh.setColor(k, sampleColor);
        }
    }
    
    float rotateAmount = ofMap(ofGetMouseY(), 0, ofGetHeight(), 0, 360);

    ofVec3f camDirection(0,0,1);
    ofVec3f centre(vidGrabber.getWidth()/2.f,vidGrabber.getHeight()/2.f, 255/2.f);
    ofVec3f camDirectionRotated = camDirection.rotated(rotateAmount, ofVec3f(1,0,0));
    ofVec3f camPosition = centre + camDirectionRotated;
    
    cam.setPosition(camPosition);
    cam.lookAt(centre);
//VIDEO GRABBER CODE//

//particle code
    
    for (int i = 0; i < particleList.size(); i++) {
        for (int j = 0; j < particleList.size(); j++) {
            
            mesh.setVertex(i, particleList[i].pos);
            mesh.setVertex(j, particleList[j].pos);
            
            ofVec3f diff = camPosition - particleList[i].pos;
            attraction.set(diff.getNormalized()*2);
            repulsion.set(attraction * -1);
            
            particleList[i].resetForce();
            particleList[j].resetForce();
            
            particleList[i].applyDampingForce(0.005);
            particleList[j].applyDampingForce(0.005);
            
            particleList[i].update();
            particleList[j].update();
        
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
////video grabber code//
//    ofSetHexColor(0xffffff);
//    vidGrabber.draw(20,20);
//    videoTexture.draw(20+camWidth,20,camWidth,camHeight);
////video grabber code//
    
    ofDisableDepthTest();
    ofEnableDepthTest();
    cam.begin();
    
    for (int i = 0; i <particleList.size(); i++) {
        for (int j = 0; j <particleList.size(); i++) {
            particleList[i].draw();
            particleList[j].draw();
        }
    }
    
    mesh.drawFaces();
    cam.end();
    
    ofSetColor(255);
    string msg = "fps: " + ofToString(ofGetFrameRate(), 2);
    ofDrawBitmapString(msg, 10, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
//video grabber code//
    // in fullscreen mode, on a pc at least, the
    // first time video settings the come up
    // they come up *under* the fullscreen window
    // use alt-tab to navigate to the settings
    // window. we are working on a fix for this...
    
    // Video settings no longer works in 10.7
    // You'll need to compile with the 10.6 SDK for this
    // For Xcode 4.4 and greater, see this forum post on instructions on installing the SDK
    // http://forum.openframeworks.cc/index.php?topic=10343
    if (key == 's' || key == 'S'){
        vidGrabber.videoSettings();
    }
//video grabber code//

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
