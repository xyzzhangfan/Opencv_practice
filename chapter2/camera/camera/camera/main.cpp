//
//  main.cpp
//  camera
//
//  Created by Fan on 6/15/17.
//  Copyright © 2017 Fan. All rights reserved.
//

#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

int main(int argc, const char * argv[]) {
    // insert code here...
    cvNamedWindow("Camera");
    CvCapture* capture;
    if(argc == 1){
        capture = cvCreateCameraCapture(0);
    }else{
        capture = cvCreateCameraCapture(*argv[1]);
    }
    assert(capture !=NULL);
    IplImage* frame;
    while(1){
        frame = cvQueryFrame(capture);
        if(!frame) break;
        cvShowImage("Camera", frame);
        char c = cvWaitKey(33);
        if(c==27) break;
        
    }
    cvReleaseCapture(&capture);
    cvDestroyWindow("Camera");
    return 0;
}
