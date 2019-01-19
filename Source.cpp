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

	cv::namedWindow("Face", cv::WINDOW_NORMAL);
	while (vc.isOpened())
	{
		vc >> image;
		detectFaces(image);
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
	cv::Mat faceROI;

	cv::cvtColor(image, gray_image, cv::COLOR_BGR2GRAY);
	face.detectMultiScale(gray_image, faces, 1.1, 2, 0, cv::Size(30, 30));

	for (size_t i = 0; i < faces.size(); i++)
	{
		faceROI = gray_image(faces[i]);
	}

	cv::Mat blank_image(image.size[0], image.size[1], CV_8UC3, cv::Scalar(0, 0, 0));
	if (faceROI.empty())
	{
		cv::imshow("Face", blank_image);
	}
	else
	{
		cv::imshow("Face", faceROI);
	}
}