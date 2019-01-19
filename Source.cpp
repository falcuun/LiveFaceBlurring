#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
	cv::VideoCapture vc(0);

	if (!vc.isOpened())
		return 0;

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