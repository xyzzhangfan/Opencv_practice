//
//  main.cpp
//  draw_atom
//
//  Created by Fan on 6/17/17.
//  Copyright © 2017 Fan. All rights reserved.
//

#include <iostream>
#include <opencv2/highgui//highgui.hpp>
#include <opencv2/core.hpp>

int main(int argc, const char * argv[]) {
    // insert code here...
    char atom_window[] = "Drawing 1: Atom";
    int w = 256;
    IplImage* atom_img = cvCreateImage(cvSize(w, w), IPL_DEPTH_8U, 3);
    cvEllipse(atom_img, cvPoint(w/2, w/2), cvSize(w/4, w/16), 45, 0, 360, cvScalar(255,0,0),2,8);
    cvEllipse(atom_img, cvPoint(w/2, w/2), cvSize(w/4, w/16), -45, 0, 360, cvScalar(255,0,0),2,8);
    cvEllipse(atom_img, cvPoint(w/2, w/2), cvSize(w/4, w/16), 90, 0, 360, cvScalar(255,0,0),2,8);
    cvEllipse(atom_img, cvPoint(w/2, w/2), cvSize(w/4, w/16), 0, 0, 360, cvScalar(255,0,0),2,8);
    
    cvCircle(atom_img, cvPoint(w/2, w/2), w/32, cvScalar(0,0,255),-1,8); // -1 thickness to fill the circle.
    cvNamedWindow(atom_window);
    cvShowImage(atom_window, atom_img);
    cvWaitKey(0);
    cvReleaseImage(&atom_img);
    cvDestroyWindow(atom_window);
    
    return 0;
}
