/// Entry point of the system

// OpenCV headers
#include <opencv\cv.h>   
#include <opencv2/opencv.hpp>
#include <opencv\highgui.h>

// local headers 
#include "ImageFactory.h"  

using namespace cv;

int main(int argc, char *argv[])
{
	/*
	Mat image;          //Create Matrix to store image
	VideoCapture cap;          //initialize capture
	cap.open(0);
	namedWindow("window", 1);          //create window to show image
	while (1) {
		cap >> image;          //copy webcam stream to image
		imshow("window", image);          //print image to screen
		waitKey(33);          //delay 33ms
	}
	*/

	VideoCapture cap(0); // open the default camera
	if (!cap.isOpened())  // check if we succeeded
		return -1;

	Mat edges;
	namedWindow("edges", 1);
	for (;;)
	{
		Mat frame;
		cap >> frame; // get a new frame from camera
		cvtColor(frame, edges, CV_BGR2GRAY);
		GaussianBlur(edges, edges, Size(1, 1), 1.5, 1.5);
		Canny(edges, edges, 0, 30, 3);
		imshow("edges", edges);
		if (waitKey(30) >= 0) break;
	}
	return 0;
}