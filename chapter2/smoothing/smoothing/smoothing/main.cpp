//
//  main.cpp
//  smoothing
//
//  Created by Fan on 6/15/17.
//  Copyright © 2017 Fan. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>


void example2_4 (IplImage* image){
    //create some windows to show the input
    // and output images in
    cvNamedWindow("Example4-in");
    cvNamedWindow("Example4-out");
    IplImage* out = cvCreateImage(cvGetSize(image), IPL_DEPTH_8U, 3);
    //do the smoothing
    cvSmooth(image, out,CV_GAUSSIAN,3,3);
    // show the output
    cvShowImage("Example4-in", image);
    cvShowImage("Example4-out", out);
    
    cvWaitKey(0);
    cvReleaseImage(&out);
    cvReleaseImage(&image);
    cvDestroyWindow("Example4-in");
    cvDestroyWindow("Example4-out");

}
int main(int argc, const char * argv[]) {
    // insert code here...
    IplImage* img = cvLoadImage(argv[1]);
    example2_4(img);
    return 0;
}
