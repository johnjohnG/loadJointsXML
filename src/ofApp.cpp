#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    if(settings.loadFile("joints.xml")){
ofLogError("load!");
        settings.pushTag("joint");
        numberOfSavedPoints = settings.getNumTags("joints");
        for(int i = 0; i < numberOfSavedPoints; i++){
            settings.pushTag("joints", i);
            
            
            h[i].x = settings.getValue("hx", 0);
            h[i].y = settings.getValue("hy", 0);
            
            n[i].x = settings.getValue("nx", 0);
             n[i].y = settings.getValue("ny", 0);
             
             b[i].x = settings.getValue("bx", 0);
             b[i].y = settings.getValue("by", 0);
             
             al[i].x = settings.getValue("alx", 0);
             al[i].y = settings.getValue("aly", 0);
            
            ar[i].x = settings.getValue("arx", 0);
            ar[i].y = settings.getValue("ary", 0);
            
            ll[i].x = settings.getValue("llx", 0);
            ll[i].y = settings.getValue("lly", 0);
            
            rl[i].x = settings.getValue("rlx", 0);
            rl[i].y = settings.getValue("rly", 0);
            
            lf[i].x = settings.getValue("lfx", 0);
            lf[i].y = settings.getValue("lfy", 0);
            
            rf[i].x = settings.getValue("rfx", 0);
            rf[i].y = settings.getValue("rfy", 0);
            
            //   points.push_back(points[i]);
            settings.popTag();
        }
        settings.popTag();//pop position
        
    }
    else{
        ofLogError("Position file did not load!");
        
    }
    
   
    j=0;
    
    head.load("headPink.png");
    body.load("bodyPink.png");
    rightLeg.load("rightLegPink.png");
    leftLeg.load("leftLegPink.png");
    arm.load("armPink.png");
    
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    ofPushMatrix();
    ofTranslate(100,200);
   if( j < numberOfSavedPoints){
        /* ofLog(OF_LOG_NOTICE,"nx "+ofToString(n[j].x)+ "nY" +ofToString(n[j].y));
        ofLog(OF_LOG_NOTICE,"hx"+ofToString(h[j].x)+"hy"+ofToString(h[j].y));
        ofLog(OF_LOG_NOTICE,"bx "+ofToString(b[j].x)+ "bY" +ofToString(b[j].y));
        ofLog(OF_LOG_NOTICE,"alx"+ofToString(al[j].x)+"aly"+ofToString(al[j].y));
        ofLog(OF_LOG_NOTICE,"arx "+ofToString(ar[j].x)+ "arY" +ofToString(ar[j].y));
        ofLog(OF_LOG_NOTICE,"llx"+ofToString(ll[j].x)+"lly"+ofToString(ll[j].y));
        ofLog(OF_LOG_NOTICE,"rlx "+ofToString(rl[j].x)+ "rlY" +ofToString(rl[j].y));
        ofLog(OF_LOG_NOTICE,"lfx"+ofToString(lf[j].x)+"lfy"+ofToString(lf[j].y));
        ofLog(OF_LOG_NOTICE,"rfx"+ofToString(rf[j].x)+"rfy"+ofToString(rf[j].x)+"\n-----------");
           */
        drawHead(b[j].x,b[j].y, h[j].x, h[j].y);
       drawRightArm(b[j].x, b[j].y, ar[j].x, ar[j].y);
       drawLeftArm(b[j].x, b[j].y, al[j].x, al[j].y);
       drawRightLeg(b[j].x, b[j].y, rf[j].x, rf[j].y);
       drawLeftLeg(b[j].x, b[j].y, lf[j].x, lf[j].y);
       drawBody(b[j].x,b[j].y);
       
       
        j++;
   }/*else if( j>=numberOfSavedPoints){
       j--;
       drawHead(n[j].x,n[j].y, h[j].x, h[j].y);
   }*/

    ofPopMatrix();

}
//-------------------draw character-----
void ofApp:: drawHead(int x1, int y1, int x2, int y2){
    float angle = atan2(y2 - y1, x2 - x1);
    ofPushMatrix();
    ofTranslate(x1,y1-60);
    ofRotate(ofRadToDeg(angle/5));
    head.setAnchorPercent(0.5,1);
    head.draw(0,0);
    ofPopMatrix();
}
void ofApp::drawBody(int x, int y){
    ofPushMatrix();
    ofTranslate(x,y);
    body.setAnchorPercent(0.5, 0.5);
    body.draw(0,0);
    ofPopMatrix();
}
//--legs
void ofApp::drawLeftLeg(int x1, int y1, int x2, int y2){
    float angle = atan2(y2 - y1, x2 - x1);
    ofPushMatrix();
    ofTranslate(x1-40,y1+80);
    ofRotate(ofRadToDeg(angle-HALF_PI));
    head.setAnchorPercent(0,0);
    leftLeg.draw(0,0);
    ofPopMatrix();
}
void ofApp::drawRightLeg(int x1, int y1, int x2, int y2){
    float angle = atan2(y2 - y1, x2 - x1);
    ofPushMatrix();
    ofTranslate(x1+30,y1+80);
    ofRotate(ofRadToDeg(angle-HALF_PI));
    head.setAnchorPercent(0,0);
    rightLeg.draw(0,0);
    ofPopMatrix();
}
//----arms--
void ofApp::drawRightArm(int x1, int y1, int x2 , int y2){
    float angle = atan2(y2 - y1, x2 - x1);
    ofPushMatrix();
    ofTranslate(x1,y1);
    ofRotate(ofRadToDeg(angle-HALF_PI));
    head.setAnchorPercent(0.5,1);
    arm.draw(0,0);
    ofPopMatrix();
}
void ofApp::drawLeftArm(int x1, int y1, int x2 , int y2){
    float angle = atan2(y2 - y1, x2 - x1);
    ofPushMatrix();
    ofTranslate(x1,y1);
    ofRotate(ofRadToDeg(angle-HALF_PI));
    head.setAnchorPercent(0.5,1);
    arm.draw(0,0);
    ofPopMatrix();
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

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
