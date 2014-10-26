#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    attacker    = new Attacker(ofGetWidth()/2, 500, 20, 20);
    shot        = new SimpleShot();

    attacker->setShot(shot);
    
    enemyMng.init();
    
    colMng = CollisionMng();
    colMng.setAttacker(attacker);
    colMng.setShot(shot);
    colMng.setEnemyMng(&enemyMng);
    
    sttViewer.init();
}

//--------------------------------------------------------------
void ofApp::update(){
    // 衝突判定
    colMng.update();
    
    // ショットや自機の動作更新
    shot->update();
    attacker->update();
    enemyMng.update();
    
    sttViewer.update();
    
    // キーボード入力によるショット変更
    changeShot();
}

//--------------------------------------------------------------
void ofApp::draw(){
    shot->draw();
    attacker->draw();
    enemyMng.draw();
    sttViewer.draw();
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
    if(key == 'i'){
        setup();
        cout << "INIT ofApp\n";
    } else if(key == 'v'){
        sttViewer.addScore(100);
    }
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