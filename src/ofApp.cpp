#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    attacker    = new Attacker(200, 200, 20, 20);
    shot        = new SimpleShot();
    enemy       = new SimpleEnemy(ofGetWidth()/2, 100, 50, 50);
    
    attacker->setShot(shot);
    
    colMng = CollisionMng();
    colMng.setAttacker(attacker);
    colMng.setShot(shot);
    colMng.setEnemy(enemy);
}

//--------------------------------------------------------------
void ofApp::update(){
    // 衝突判定
    colMng.update();
    
    // ショットや自機の動作更新
    shot->update();
    attacker->update();
    enemy->update();
    
    // キーボード入力によるショット変更
    changeShot();
}

//--------------------------------------------------------------
void ofApp::draw(){
    shot->draw();
    attacker->draw();
    enemy->draw();
}

//--------------------------------------------------------------
void ofApp::changeShot(){
    if(ofGetKeyPressed('s')){
        shot = new SimpleShot();
        attacker->setShot(shot);
        colMng.setShot(shot);
        // cout << "CHANGE : SIMPLE SHOT\n";
    } else if(ofGetKeyPressed('d')){
        shot = new DoubleShot();
        attacker->setShot(shot);
        colMng.setShot(shot);
        // cout << "CHANGE : DOUBLE SHOT\n";
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // cout << "KEY : " << key << "\n";
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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