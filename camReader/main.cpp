/*  For description look into the help() function. */

// OpenCV headers
#include "opencv\cv.h"  
#include "opencv2/core/core.hpp"
#include "opencv2/opencv.hpp"
#include "opencv\highgui.h"

// Z-bar header
#include <zbar.h>

// other headers 
#include "ImageFactory.h"  
#include <iostream>

using namespace std;
using namespace cv;
using namespace zbar;

static void help()
{
	cout
		<< "\n--------------------------------------------------------------------------" << endl
		<< "This program shows how to extract the video from the webcamera" << endl
		<< "--------------------------------------------------------------------------" << endl
		<< endl;
}

int main(int, char**)
{
	VideoCapture cap(0); // open the default camera
	if (!cap.isOpened())  // check if we succeeded
		return -1;

	Mat edges;
	//ImageScanner imgscanner;

	namedWindow("camReader", CV_WINDOW_AUTOSIZE);
	//imgscanner.set_config()

	for (;;)
	{
		Mat frame;
		cap >> frame; // get a new frame from camera
		cvtColor(frame, edges, 0); // converts the image one from color space to another
		imshow("camReader", edges);
		if (waitKey(30) >= 0) break;
	}
	return 0;
}