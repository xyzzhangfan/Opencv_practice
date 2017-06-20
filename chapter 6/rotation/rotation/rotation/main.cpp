//
//  main.cpp
//  rotation
//
//  Created by Fan on 6/19/17.
//  Copyright © 2017 Fan. All rights reserved.
//  using cv2DRotationMatrix 

#include <iostream>
#include <math.h>
#include <opencv2/highgui//highgui.hpp>
#include <opencv2/opencv.hpp>

void rotateImage(IplImage* img,IplImage* img_rotate, int degree){
    CvPoint2D32f center;
    center.x = float(img->width/2.0+0.5);
    center.y = float(img->height/2.0 + 0.5);
    float m[6];
    CvMat M = cvMat(2, 3, CV_32F,m);
    cv2DRotationMatrix(center, degree, 1, &M);
    cvWarpAffine(img, img_rotate, &M,CV_INTER_LINEAR+CV_WARP_FILL_OUTLIERS,cvScalarAll(0));
}


IplImage* rotateImage_large(IplImage* img, int degree){
    double angle = degree *CV_PI/180;
    double a = sin(angle), b = cos(angle);
    int width = img->width;
    int height = img->height;
    int width_rotate = int(height *fabs(a) + width *fabs(b));
    int height_rotate = int(width *fabs(a) + height*fabs(b));
    float map[6];
    CvMat map_matrix = cvMat(2, 3, CV_32F,map);
    CvPoint2D32f center = cvPoint2D32f(width/2, height/2);
    cv2DRotationMatrix(center, degree, 1.0, &map_matrix);
    map[2]+=(width_rotate -width)/2;
    map[5] += (height_rotate-height)/2;
    IplImage* img_rotate = cvCreateImage(cvSize(width_rotate, height_rotate), 8, 3);
    cvWarpAffine(img, img_rotate, &map_matrix,CV_INTER_LINEAR|CV_WARP_FILL_OUTLIERS,cvScalar(0));
    return img_rotate;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    IplImage* img = cvLoadImage(argv[1]);
    IplImage* img_samesize, *img_large;
    img_samesize = cvCreateImage(cvSize(img->width, img->height), img->depth, img->nChannels);
    rotateImage(img, img_samesize, atoi(argv[2]));
    img_large = rotateImage_large(img, atoi(argv[2]));
    
    cvNamedWindow("Raw");
    cvNamedWindow("Same size");
    cvNamedWindow("large size");
    cvShowImage("Raw", img);
    cvShowImage("Same size", img_samesize);
    cvShowImage("large size", img_large);
    
    
    cvWaitKey(0);
    cvReleaseImage(&img);
    cvReleaseImage(&img_samesize);
    cvReleaseImage(&img_large);
    cvDestroyWindow("large size");
    cvDestroyWindow("Raw");
    cvDestroyWindow("Same size");
    return 0;
}
