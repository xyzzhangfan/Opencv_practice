//
//  main.cpp
//  button
//
//  Created by Fan on 6/18/17.
//  Copyright © 2017 Fan. All rights reserved.
//

#include <iostream>
#include <opencv2/highgui//highgui.hpp>
#include <opencv2/opencv.hpp>

void switch_off_function(){}
void switch_on_function(){};

int g_switch_value = 0;
void switch_callback(int position){
    if(position == 0){
        switch_off_function();
    }else{
        switch_on_function();
    }
}



int main(int argc, const char * argv[]) {
    // insert code here...
    cvNamedWindow("button");
    cvCreateTrackbar("Switch", "button", &g_switch_value, 1,switch_callback);
    while(1){
        if(cvWaitKey(15)==27) break;
    }
    return 0;
}
