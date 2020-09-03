#include <iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main( int argc, char* argv[])
{

const char *filename= "/home/aleksei/dev/OpenCV/content/1.png";
Mat img = imread(filename);

double x=5.0,
       y=2.5;

//Scalar intensity = img.at<uchar>(y, x);
//Scalar intensity2 = img.at<uchar>(Point(x, y));

//Vec3b intensity3 = img.at<Vec3b>(y, x);
//uchar blue3 = intensity3.val[0];
//uchar green3 = intensity3.val[1];
//uchar red3 = intensity3.val[2];


//Vec3f intensity4 = img.at<Vec3f>(y, x);
//float blue4 = intensity4.val[0];
//float green4 = intensity4.val[1];
//float red4 = intensity4.val[2];


//vector<Point2f> points;
// //... fill the array
//Mat pointsMat = Mat(points);
////Point2f point = pointsMat.at<Point2f>(0, 0);




std::vector<Point3f> points2;
 // .. fill the array
Mat pointsMat2 = Mat(points2).reshape(1);

Mat img1 = img.clone();

img1 = Scalar(0);
Rect r(10, 10, 100, 100);
Mat smallImg = img(r);


//Mat grey;
//cvtColor(img, grey, COLOR_BGR2GRAY);
//Mat imgConverted;
//img.convertTo(imgConverted, CV_32F);
//namedWindow("image", WINDOW_AUTOSIZE);

Mat grey;
cvtColor(img, grey, COLOR_BGR2GRAY);
Mat sobelx;
Sobel(grey, sobelx, CV_32F, 1, 0);

double minVal, maxVal;
minMaxLoc(sobelx, &minVal, &maxVal); //find minimum and maximum intensities

Mat draw;

sobelx.convertTo(draw, CV_8U, 255.0/(maxVal - minVal), -minVal * 255.0/(maxVal - minVal));
namedWindow("image", WINDOW_AUTOSIZE);
imshow("image", draw);
waitKey();


imshow("image",  img);
imwrite("2.png",  img);
waitKey(0);


return 0;

}
