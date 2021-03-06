#include<opencv2/opencv.hpp>
#include<iostream>
#include<vector>

int ipBGMOG2(void)
{
	// Using Inbuilt types for tempFrame stuff
    cv::Mat tempFrame;				// For capture
    cv::Mat Background;				// For Extracted Background
    cv::Mat Foreground;				// Foreground Mask Thingy
	// Capture Video From Camera
    cv::VideoCapture vidDevice(0);

	// Background Extraction Function Object Created.
    cv::BackgroundSubtractorMOG2 bg;
	// bg = cv::BackgroundSubtractorMOG2(200, 10, false);
	bg.set("nmixtures",10);
	// Disable detection of Shadows
	//bg.set("nShadowDetection",false);


	// Create Windows
	cv::namedWindow("Current Frame");
    cv::namedWindow("Extracted Background");

    while(1)
    {
		vidDevice >> tempFrame; 					// Capture Frame
		// Update Background model and Create Binary Mask Of foreground Objects
        bg.operator ()(tempFrame,Foreground);		
        bg.getBackgroundImage(Background);
		// Illimnate Noise
        //cv::erode(Foreground,Foreground,cv::Mat());
        //cv::dilate(Foreground,Foreground,cv::Mat());
		
        cv::imshow("Current Frame",tempFrame);
        cv::imshow("Extracted Background",Background);
        if(cv::waitKey(30) >= 0) break;
    }
    return 0;
}