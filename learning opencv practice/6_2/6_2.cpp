#include<opencv.hpp>
#include<cv.h>
#include<highgui.h>

using namespace cv;
using namespace std;



int main(int argc, char* argv)
{
    Mat img = imread("1.bmp");
    imshow("src",img);

    Mat kern = (Mat_<float>(3, 3) << 0.0625, 0.125, 0.0625, 0.125, 0.25, 0.125, 0.0625, 0.125, 0.0625);
    Mat img1;
    filter2D(img,img1,img.depth(),kern);
    imshow("dst",img1);

    Mat kern1 = (Mat_<float>(1, 3) << 0.25, 0.5, 0.25);
    Mat kern2 = (Mat_<float>(3, 1) << 0.25, 0.5, 0.25);
    Mat img2;
    Mat img3;
    filter2D(img, img2, img.depth(), kern1);
    filter2D(img2, img3, img2.depth(),kern2);
    imshow("dst1", img2);
    imshow("dst2", img3);
    /*
    CvMat* mat_b = cvCreateMat(1, 3, CV_32FC1);
    cvmSet(mat_b, 0, 0, 1);
    cvmSet(mat_b, 0, 1, 2);
    cvmSet(mat_b, 0, 2, 1);
   
    CvMat* mat_b_2 = cvCreateMat(3, 1, CV_32FC1);
    cvmSet(mat_b_2, 0, 0, 1);
    cvmSet(mat_b_2, 1, 0, 2);
    cvmSet(mat_b_2, 2, 0, 1);

    int x = mat_b_2->height;
    int y = mat_b_2->width;

    printf("%d %d \n", x, y);
    float t = cvmGet(mat_b_2, 0,0 );
    float t1 = cvmGet(mat_b_2, 1, 0);
    float t2 = cvmGet(mat_b_2, 2, 0);
    cout << t << endl;
    cout << t1 << endl;
    cout << t2 << endl;
    */

    waitKey();
    return 0;
}