//
//  main.cpp
//  OpenCV example
//
//  Created by Fan on 6/15/17.
//  Copyright © 2017 Fan. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv/cvaux.hpp>
#include <fstream>
using namespace std;
#define BYTE unsigned char

int main(int argc, const char * argv[]) {
    IplImage* img =cvLoadImage("/Users/fan/Desktop/Opencv_practice/using terminal to show a image/1.jpg",1);
    cvNamedWindow("picture",1);
    cvShowImage("picture", img);
    cvWaitKey(0);
    cvReleaseImage(&img);
    cvDestroyWindow("picture");
    
    return 0;
}
