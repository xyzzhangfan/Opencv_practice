//
//  main.cpp
//  halfsize
//
//  Created by Fan on 6/15/17.
//  Copyright © 2017 Fan. All rights reserved.
//

#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

IplImage* doPyrDown(IplImage* in, int filter = CV_GAUSSIAN_5x5){
    assert(in->width%2==0 && in->height%2==0);
    IplImage* out = cvCreateImage(cvSize(in->width/2, in->height/2), in->depth, in->nChannels);
    cvPyrDown(in, out);
    return(out);
}



IplImage* doCanny(IplImage* in, double lowThresh, double highThresh, double aperture){
    if(in->nChannels !=1)
        return(0); // Canny only handles gray scale images
    IplImage* out = cvCreateImage(cvGetSize(in), IPL_DEPTH_8U, 1);
    cvCanny(in, out, lowThresh, highThresh,aperture);
    return (out);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    IplImage* in = cvLoadImage(argv[1],CV_LOAD_IMAGE_GRAYSCALE);
    IplImage* img1 = doPyrDown(in, CV_GAUSSIAN_5x5);
    IplImage* img2 = doPyrDown(img1,CV_GAUSSIAN_5x5);
    IplImage* img3 = doCanny(img2, 10, 100,3);
    cvNamedWindow("canny");
    cvShowImage("canny", img3);
    cvWaitKey(0);
    
    
    
    return 0;
}
