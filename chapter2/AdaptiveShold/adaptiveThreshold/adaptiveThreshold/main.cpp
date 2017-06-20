//
//  main.cpp
//  adaptiveThreshold
//
//  Created by Fan on 6/19/17.
//  Copyright © 2017 Fan. All rights reserved.
//

#include <iostream>
#include <opencv2/highgui//highgui.hpp>
#include <opencv2/opencv.hpp>
#include <math.h>

IplImage* Igray = 0,*It = 0, *Iat;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cout << argv[1] << argv[2]<< argv[3]<< argv[4]<< argv[5]<< argv[6] ;
    double threshold = (double ) atof(argv[1]);
    int threshold_type = atoi(argv[2])?
        CV_THRESH_BINARY: CV_THRESH_BINARY_INV;
    int adaptive_method = atoi(argv[3])?
        CV_ADAPTIVE_THRESH_MEAN_C:CV_ADAPTIVE_THRESH_GAUSSIAN_C;
    int block_size = atoi(argv[4]);
    double offset = (double) atof(argv[5]);
    
    
    if((Igray = cvLoadImage(argv[6],CV_LOAD_IMAGE_GRAYSCALE)) == 0){
        return -1;
    }
    
    It = cvCreateImage(cvSize(Igray->width, Igray->height), IPL_DEPTH_8U, 1);
    Iat = cvCreateImage(cvSize(Igray->width, Igray->height), IPL_DEPTH_8U, 1);
    
    //Threshold
    cvThreshold(Igray, It, threshold, 255, threshold_type);
    cvAdaptiveThreshold(Igray, Iat, 255, adaptive_method, threshold_type, block_size, offset);
    
    cvNamedWindow("RAW");
    cvNamedWindow("Threshold");
    cvNamedWindow("Adaptive Threshold");
    
    cvShowImage("RAW", Igray);
    cvShowImage("Threshold", It);
    cvShowImage("Adaptive Threshold", Iat);
    
    cvWaitKey(0);
    //clean up
    
    cvReleaseImage(&Igray);
    cvReleaseImage(&It);
    cvReleaseImage(&Iat);
    cvDestroyWindow("RAW");
    cvDestroyWindow("Threshold");
    cvDestroyWindow("Adaptivev Threshold");
    
    
    return 0;
}
