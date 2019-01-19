#include <iostream>
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

void detectFaces(cv::Mat image);

cv::CascadeClassifier face;

int main()
{
	cv::VideoCapture vc(0);

	if (!vc.isOpened())
		return 0;
	face.load("haarcascade_frontalface_alt.xml");

	cv::Mat image;

	cv::namedWindow("Image", cv::WINDOW_NORMAL);
	while (vc.isOpened())
	{
		vc >> image;

		cv::imshow("Image", image);
		if (cv::waitKey(30) == 27)
		{
			vc.release();
			break;
		}
	}
}

void detectFaces(cv::Mat image)
{
	std::vector<cv::Rect> faces;
	cv::Mat gray_image;

	cv::cvtColor(image, gray_image, cv::COLOR_BGR2GRAY);

	face.detectMultiScale(gray_image, faces, 1.1, 2, 0, cv::Size(30, 30));

	for (size_t i = 0; i < faces.size(); i++)
	{
		cv::Point center(faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5);
		
		cv::Mat faceROI = gray_image(faces[i]);
	}
}