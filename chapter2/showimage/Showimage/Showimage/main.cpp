//
//  main.cpp
//  Showimage
//
//  Created by Fan on 6/15/17.
//  Copyright © 2017 Fan. All rights reserved.
//

#include <iostream>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, const char * argv[]) {
    IplImage* img =cvLoadImage(argv[1]);
    cvNamedWindow("Example1",CV_WINDOW_AUTOSIZE);
    cvShowImage("Example1", img);
    cvWaitKey(0);
    cvReleaseImage(&img);
    cvDestroyWindow("Example1");
    return 0;
}
