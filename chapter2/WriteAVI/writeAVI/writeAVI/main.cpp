//
//  main.cpp
//  writeAVI
//
//  Created by Fan on 6/15/17.
//  Copyright © 2017 Fan. All rights reserved.
//convert a video to grayscale
//argv[1] input video file
//argv[2] name of new output


#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

int main(int argc, const char * argv[]) {
    // insert code here...
    CvCapture * capture=0;
    capture = cvCreateFileCapture(argv[1]);
    if(!capture){
        return -1;
    }
    IplImage* bgr_frame =cvQueryFrame(capture);
    double fps = cvGetCaptureProperty(capture, CV_CAP_PROP_FPS);
    CvSize size = cvSize((int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH),(int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT));
    CvVideoWriter *writer = cvCreateVideoWriter(argv[2], CV_FOURCC('M', 'J', 'P', 'G'), fps, size);
    IplImage* logpolar_frame = cvCreateImage(size, IPL_DEPTH_8U, 3);
    
    while((bgr_frame=cvQueryFrame(capture))!=NULL){
        cvLogPolar(bgr_frame, logpolar_frame, cvPoint2D32f(bgr_frame->width/2, bgr_frame->height/2), 40,CV_INTER_LINEAR+CV_WARP_FILL_OUTLIERS);
        cvWriteFrame(writer, logpolar_frame);
    }
    cvReleaseVideoWriter(&writer);
    cvReleaseImage(&logpolar_frame);
    cvReleaseCapture(&capture);
    
    return 0;
}
