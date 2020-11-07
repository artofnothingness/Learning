#include <opencv2/opencv.hpp>

using namespace cv;
int main( int argc, char** argv )
{
 String imageName = "4.jpg";

 Mat image;
 image = imread(imageName, IMREAD_COLOR);

 if( image.empty() )
 {
   printf( " No image data \n " );
   return -1;
 }

 Mat gray_image;

 cvtColor( image, gray_image, COLOR_RGB2GRAY );
 imwrite( "4_gray.jpg", gray_image );

 namedWindow( imageName, WINDOW_AUTOSIZE );
 namedWindow( "Gray image", WINDOW_AUTOSIZE );

 imshow( imageName, image );
 imshow( "Gray image", gray_image );
 waitKey(0);
 return 0;
}
