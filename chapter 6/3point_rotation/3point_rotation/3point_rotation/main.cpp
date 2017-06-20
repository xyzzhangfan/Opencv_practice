//
//  main.cpp
//  3point_rotation
//
//  Created by Fan on 6/19/17.
//  Copyright © 2017 Fan. All rights reserved.
//

#include <iostream>
#include <opencv2/highgui//highgui.hpp>
#include <opencv2/opencv.hpp>


int main(int argc, const char * argv[]) {
    // insert code here...
    CvPoint2D32f srcTric[3], dstTri[3];
    CvMat* rot_mat = cvCreateMat(2, 3, CV_32FC1);
    CvMat* warp_mat = cvCreateMat(2, 3, CV_32FC1);
    IplImage* src, *dst;
    
    if(argc==2 && ((src = cvLoadImage(argv[1])) !=0)){
        dst = cvCloneImage(src);
        dst->origin = src->origin;
        cvZero(dst);
        
        srcTric[0].x = 0;
        srcTric[0].y = 0;
        srcTric[1].x = src->width - 1;
        srcTric[1].y = 0;
        srcTric[2].x = 0;
        srcTric[2].y = src->height - 1;
        
        dstTri[0].x = src->width *0.0;
        dstTri[0].y = src->height * 0.33;
        dstTri[1].x = src->width * 0.85;
        dstTri[1].y = src->height * 0.25;
        dstTri[2].x = src->width * 0.15;
        dstTri[2].y = src->height * 0.7;
        
        cvGetAffineTransform(srcTric, dstTri, warp_mat);
        cvWarpAffine(src, dst, warp_mat);
        //cvCopy(dst, src);
        
        
        CvPoint2D32f center = cvPoint2D32f(src->width/2, src->height/2);
        double angle = 45;
        double scale = 1;
        cv2DRotationMatrix(center, angle, scale, rot_mat);
        cvWarpAffine(src, dst, rot_mat);
        cvNamedWindow("affine_transform");
        cvShowImage("affine_transform", dst);
        cvWaitKey(0);
        cvReleaseImage(&dst);
        cvDestroyWindow("affine_transform");
    }
    return 0;
}
