//
//  bean.hpp
//  practice
//
//  Created by Neil on 10/31/16.
//
//

#ifndef bean_hpp
#define bean_hpp

#include <stdio.h>
#include "ofMain.h"

class bean{
public:
    ofPoint pos;
    ofPoint tempPos;
    float width, height;
    ofVec2f velocity;
    ofVec2f acceleration;
    
   // float FFT;
    
    bool is_bouncing;
    bool is_dancing;
    
    
    void setup(string path);
    void update(float fft);
    void draw();
    void reset();
    void bounce();
    void dance();
    
    ofImage img;
    
    
};

#endif /* bean_hpp */
