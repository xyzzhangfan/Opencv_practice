//
//  main.cpp
//  widthstep
//
//  Created by Fan on 6/16/17.
//  Copyright © 2017 Fan. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui//highgui.hpp>

int main(int argc, const char * argv[]) {
    IplImage* interest_img;
    CvRect interest_rect;
    if( argc == 7 && ((interest_img=cvLoadImage(argv[1],1)) != 0 ))
    {
        interest_rect.x = atoi(argv[2]);
        interest_rect.y = atoi(argv[3]);
        interest_rect.width = atoi(argv[4]);
        interest_rect.height = atoi(argv[5]);
        int add = atoi(argv[6]);
    
    // insert code here...
    IplImage* sub_image = cvCreateImageHeader(cvSize(interest_rect.width, interest_rect.height), interest_img->depth, interest_img->nChannels);
        sub_image->origin = interest_img->origin;
        sub_image->widthStep = interest_img->widthStep;
        sub_image->imageData = interest_img->imageData + interest_rect.y * interest_img->widthStep + interest_rect.x * interest_img->nChannels;
        cvAddS(sub_image, cvScalar(add), sub_image);
        cvReleaseImageHeader(&sub_image);
        
        cvNamedWindow( "Roi_Add", CV_WINDOW_AUTOSIZE );
        cvShowImage( "Roi_Add", interest_img );
        cvWaitKey();
    }
    return 0;
}
