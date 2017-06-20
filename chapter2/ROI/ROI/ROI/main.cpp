//
//  main.cpp
//  ROI
//
//  Created by Fan on 6/16/17.
//  Copyright © 2017 Fan. All rights reserved.
//

#include <iostream>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/opencv.hpp>

int main(int argc, const char * argv[]) {
    // insert code here...
    IplImage* src;
    if(argc == 7 && ((src = cvLoadImage(argv[1],1))!=0)){
        int x = atoi(argv[2]);
        int y = atoi(argv[3]);
        int width = atoi(argv[4]);
        int height = atoi(argv[5]);
        int add = atoi(argv[6]);
        cvSetImageROI(src, cvRect(x, y, width, height));
        cvAddS(src, cvScalar(add), src);
        cvResetImageROI(src);
        cvNamedWindow("ROI_add");
        cvShowImage("ROI_add", src);
        cvWaitKey(0);
    }
    return 0;
}
