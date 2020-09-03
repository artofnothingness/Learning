
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
using namespace cv;
// we're NOT "using namespace std;" here, to avoid collisions between the beta variable and std::beta in c++17
using std::cin;
using std::cout;
using std::endl;
int main( void )
{
    double alpha = 0.5; double beta; double input;
    Mat src1, src2, dst;

    cout << " Simple Linear Blender " << endl;
    cout << "-----------------------" << endl;
    cout << "* Enter alpha [0.0-1.0]: ";
    cin >> input;
    // We use the alpha provided by the user if it is between 0 and 1
    if(input >= 0 && input <= 1 )
        {
            alpha = input;
            beta = ( 1.0 - alpha);
        }

    src1 = imread("/home/aleksei/dev/OpenCV/content/win.jpg");
    src2 = imread("/home/aleksei/dev/OpenCV/content/lin.jpg");
    if( src1.empty() ) { cout << "Error loading src1" << endl; return EXIT_FAILURE; }
    if( src2.empty() ) { cout << "Error loading src2" << endl; return EXIT_FAILURE; }

    addWeighted( src1, alpha, src2, beta, 0.0, dst);
    imshow( "Linear Blend", dst );
    waitKey(0);
    return 0;
}