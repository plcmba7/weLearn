/*  For description look into the help() function. */

#include "opencv\cv.h"  
#include "opencv2/core/core.hpp"
#include "opencv2/opencv.hpp"
#include "opencv\highgui.h"

// other headers 
#include "ImageFactory.h"  
#include <iostream>

using namespace std;
using namespace cv;

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
	namedWindow("edges", 1);
	for (;;)
	{
		Mat frame;
		cap >> frame; // get a new frame from camera
		cvtColor(frame, edges, COLOR_BGR2GRAY);
		cv::GaussianBlur(edges, edges, Size(7, 7), 1.5, 1.5);
		Canny(edges, edges, 0, 30, 3);
		imshow("edges", edges);
		if (waitKey(30) >= 0) break;
	}
	return 0;
}