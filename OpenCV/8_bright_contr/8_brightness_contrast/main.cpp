#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>


using std::cin;
using std::cout;
using std::endl;

using namespace cv;

int main( int argc, char** argv )
{
    CommandLineParser parser( argc, argv, "{@input | lena.jpg | input image}" );
    Mat image = imread(parser.get<String>( "@input" ));
    if( image.empty() )
    {
      cout << "Could not open or find the image!\n" << endl;
      cout << "Usage: " << argv[0] << " <Input image>" << endl;
      return -1;
    }
    Mat new_image = Mat::zeros( image.size(), image.type() );

    double alpha = 1.0; /*< Simple contrast control */
    int beta = 0;       /*< Simple brightness control */
    cout << " Basic Linear Transforms " << endl;
    cout << "-------------------------" << endl;
    cout << "* Enter the alpha value [1.0-3.0]: "; cin >> alpha;
    cout << "* Enter the beta value [0-100]: ";    cin >> beta;


    double time = getTickCount();

//    for( int y = 0; y < image.rows; y++ ) {
//        for( int x = 0; x < image.cols; x++ ) {
//            for( int c = 0; c < image.channels(); c++ ) {
//                new_image.at<Vec3b>(y,x)[c] =
//                  saturate_cast<uchar>( alpha*image.at<Vec3b>(y,x)[c] + beta );
//            }
//        }
//    }

    image.convertTo(new_image, -1, alpha, beta);

    cout<< "Convert time = " << ((getTickCount() - time)/ getTickFrequency());

    imshow("Original Image", image);
    imshow("New Image", new_image);
    waitKey();
    return 0;
}
