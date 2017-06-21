//
//  main.cpp
//  logpolar
//
//  Created by Fan on 6/20/17.
//  Copyright © 2017 Fan. All rights reserved.
//

#include <iostream>
#include <opencv2/highgui//highgui.hpp>
#include <opencv2/opencv.hpp>

int main(int argc, const char * argv[]) {
    // insert code here...
    IplImage* src;
    double M;
    int size = 256;
    CvPoint point_start = cvPoint(2, 2);
    CvPoint point_end = cvPoint(size -2, size -2);
    src = cvCreateImage(cvSize(size, size), IPL_DEPTH_8U, 3);
    cvRectangle(src, point_start, point_end, cvScalar(255,255,255), 3);
    if(argc ==2 &&(src != 0)){
        M = atof(argv[1]);
        IplImage* dst = cvCreateImage(cvGetSize(src), 8, 3);
        IplImage* src2 = cvCreateImage(cvGetSize(src), 8, 3);
        cvLogPolar(src, dst, cvPoint2D32f(src->width/2, src->height/2), M,CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS);
        cvLogPolar(dst, src2, cvPoint2D32f(src->width/2, src->height/2), M,CV_INTER_LINEAR + CV_WARP_INVERSE_MAP);
        cvNamedWindow("log-polar");
        cvShowImage("log-poalr", dst);
        cvNamedWindow("original");
        cvShowImage("original", src);
        cvNamedWindow("inverse");
        cvShowImage("inverse", src2);
        cvWaitKey(0);
        
    }
    return 0;
}
