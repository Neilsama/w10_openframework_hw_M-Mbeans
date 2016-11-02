#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // load background image;
    background.load("bg.jpg");
    
    myFont.load("SuperClarendon.ttc", 40);
   
    // load music;
    soundPlayer.load("demo.mp3");
    
    nBandsToGet = 128;
    
    
    //set beans position according to keyboard;
    for(int i = 0; i < 30; i++){
        // first line beans
        if(i < 10){
            beans[i].pos = ofVec2f(260+i*50, 400);
            beans[i].setup(ofToString(i+1)+".png");
        }
        // second line beans
        if( i >= 10 && i < 21){
            beans[i].pos= ofVec2f(235+(i-10)*50, 460);
            beans[i].setup(ofToString(i+1)+".png");
        }
        // thrid line beans
        if( i >= 21 ){
            beans[i].pos= ofVec2f(288+(i-21)*50, 520);
            beans[i].setup(ofToString(i+1)+".png");
        }
    }
    
    
}
//--------------------------------------------------------------
void ofApp::update(){
    
    // update beans position
    for(int i = 0; i < 30; i++){
        beans[i].update(avgFFT);
    }
    
    ofSoundUpdate();

    valFFT = ofSoundGetSpectrum(nBandsToGet);
    
    // calculate average fft;
    float temp;
    for(int i = 0; i < nBandsToGet; i++){
        //cout << "fft: " + ofToString(valFFT[i]) << endl;
        temp += valFFT[i];
    }
    
    avgFFT = temp/nBandsToGet * 10;
    
    cout << "avgFFT: " + ofToString(avgFFT) << endl;
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // draw background image;
    background.draw(0, 0);
    
    // draw all beans;
    for(int i = 0; i < 30; i++){
        beans[i].draw();
    }
    
    if(soundPlayer.isPlaying()){
        myFont.drawString("M&M Beans Go Grazy!!", 170, 200);
    }
    
  }

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == ' '){
        if(!soundPlayer.isPlaying()){
            soundPlayer.play();
            beginDance();
        }
        else{
            soundPlayer.stop();
            background.load("bg.jpg");
            for(int i = 0; i < 30; i++){
                beans[i].reset();
            }
        }
    }
    if(!soundPlayer.isPlaying()){
    if(key == 'q'){
    beans[0].bounce();
    }
    if(key == 'w'){
        beans[1].bounce();
    }
    if(key == 'e'){
        beans[2].bounce();
    }
    if(key == 'r'){
        beans[3].bounce();
    }
    if(key == 't'){
        beans[4].bounce();
    }
    if(key == 'y'){
        beans[5].bounce();
    }
    if(key == 'u'){
        beans[6].bounce();
    }
    if(key == 'i'){
        beans[7].bounce();
    }
    if(key == 'o'){
        beans[8].bounce();
    }
    if(key == 'p'){
    beans[9].bounce();
    }
    if(key == OF_KEY_LEFT_SUPER){
        beans[10].bounce();
    }
    if(key == 'a'){
    beans[11].bounce();
    }
    if(key == 's'){
        beans[12].bounce();
    }
    if(key == 'd'){
        beans[13].bounce();
    }
    if(key == 'f'){
        beans[14].bounce();
    }
    if(key == 'g'){
        beans[15].bounce();
    }
    if(key == 'h'){
        beans[16].bounce();
    }
    if(key == 'j'){
        beans[17].bounce();
    }
    if(key == 'k'){
        beans[18].bounce();
    }
    if(key == 'l'){
        beans[19].bounce();
    }
    if(key == OF_KEY_RETURN){
        beans[20].bounce();
    }
    if(key == OF_KEY_LEFT_SHIFT){
        beans[21].bounce();
    }
    if(key == 'z'){
        beans[22].bounce();
    }
    if(key == 'x'){
        beans[23].bounce();
    }
    if(key == 'c'){
        beans[24].bounce();
    }
    if(key == 'v'){
        beans[25].bounce();
    }
    if(key == 'b'){
        beans[26].bounce();
    }
    if(key == 'n'){
        beans[27].bounce();
    }
    if(key == 'm'){
        beans[28].bounce();
    }
    if(key == OF_KEY_RIGHT_SHIFT){
        beans[29].bounce();
    }
    }

    
}

void ofApp::beginDance(){
    background.load("bg2.jpg");
    
    // beans move
    for(int i = 0; i < 30; i++){
        beans[i].dance();
    }
    
    
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
