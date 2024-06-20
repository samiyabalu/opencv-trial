//
//  main.cpp
//  opencv-trial
//
//  Created by Samiya  Balu  on 6/20/24.
//
#include <iostream>
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp> //image processing
#include <opencv2/imgcodecs.hpp> //different ways to store images
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp> //video output i think
#include <opencv2/objdetect.hpp> //using preexisting ml librariesdetection for object detection
/*
int main() {
    std::cout << "this works?\n";
}
*/
using namespace std; //standard stuff lol I don't think I really need this
using namespace cv; //so our code knows where 'imshow' and other OpenCV functions are from

int main(int, char**){
    std::cout << "the code actually working omg\n";
    VideoCapture cap(0); // open whatever camera is default for your computer
    if(!cap.isOpened()) // if cap(ture) boolean value true/worked -> check if we succeeded
        return -1;

for(;;){
    Mat camera; //initialize a matrix (Mat = matrix) with name "frame"
    Mat hsv; //use this matrix to change from rgb -> hsv so its easier to process
    Mat processOut; //processed output image (takes hsv matrix and outputs based on params we put in the processing 'inRange'
    cap.read(camera); //fill matrix 'frame' with input from cap(ture)
    //cap >> frame; does the same thing as above
    cvtColor(camera, hsv, COLOR_RGB2HSV);
    inRange(hsv, Scalar(0,0,0), Scalar(255,255,100), processOut); //Scalar (hue, saturation, vibrance)
    imshow("live video", camera); // imshow parameters (name of window, what matrix you want to display
    imshow("processed", processOut); //display another window with matrix processOut!!
    if(waitKey(1) >= 0) break; //waitKey(X) where X is how many ms before we repeat loop again to display new frame (omg its a video)
}
    
// the camera will be deinitialized automatically in VideoCapture destructor
return 0;

}
