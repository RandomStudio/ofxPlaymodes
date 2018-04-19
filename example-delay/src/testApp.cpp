#include "testApp.h"
using namespace ofxPm;

//--------------------------------------------------------------
void testApp::setup(){
	grabber.initGrabber(640,480);
	grabber.setFps(30);
	buffer.setup(grabber, 400);
	header.setup(buffer);
	renderer.setup(header);

	ofBackground(0);
}

//--------------------------------------------------------------
void testApp::update(){
	grabber.update();
}

//--------------------------------------------------------------
void testApp::draw(){
	ofSetColor(255);
	renderer.draw();

	header.draw();
	buffer.draw();
	ofDrawBitmapString("VideoFrame pool size: " + ofToString(VideoFrame::getPoolSize(VideoFormat(640,480,3))),20,ofGetHeight()-20);
	ofDrawBitmapStringHighlight("pct: " + ofToString(pct, 3) + ", delay:" + ofToString(header.getDelayMs()), 10, 10);

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	if(key==' '){
		if(buffer.isStopped()){
			buffer.resume();
		}else{
			buffer.stop();
		}
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	pct = float(x)/float(ofGetWidth());
	header.setDelayPct(pct);
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
