//
//  bean.cpp
//  practice
//
//  Created by Neil on 10/31/16.
//
//

#include "bean.hpp"

//--------------------------------------------------------------
void bean::setup(string path){
    // load beans images;
    img.load(path);
    
    // set images size
    width = 50;
    height = 50;
    
    // store origin position of beans
    tempPos = pos;
    
    // beans jump;
    velocity = ofVec2f(0, -30);
    acceleration = ofVec2f(0, 3);
    
    // is_bouncing set wether beans is jumping
    is_bouncing = false;
}

//--------------------------------------------------------------
void bean::update(float fft){
    
    // if beans is jumping, update the position of jumping bean
    if(is_bouncing == true){
        //tempPos = pos;
        tempPos += velocity;
        velocity += acceleration;
        
        if(tempPos == pos){
            is_bouncing = false;
            velocity.y = -30;
        }
    }
    
    if(is_dancing == true){
        cout << "begin dancing!!!" << endl;
        cout << "avarage fft: " + ofToString(fft) << endl;
        ofVec2f movement = ofVec2f(ofRandom(-5,5)*fft,ofRandom(-5,5)*fft);
        tempPos += movement;
        cout << "tempPos.x: " + ofToString(tempPos.x) + "  tempPos.y: " + ofToString(tempPos.y) << endl;
    }
}


//--------------------------------------------------------------
void bean::draw(){
    
    img.draw(tempPos.x, tempPos.y, width, height);
}

void bean::bounce(){
    
    is_bouncing = true;
    is_dancing = false;
        
}
void bean::dance(){
    
    is_dancing = true;
    is_bouncing = false;
    
}

void bean::reset(){
    tempPos = pos;
    is_bouncing = false;
    is_dancing = false;
}
