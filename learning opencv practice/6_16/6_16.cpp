#include<cv.h>
#include<highgui.h>


using namespace cv;


int main()
{
    Mat img = imread("1.jpg",0);
    imshow("img",img);

    Mat dst;
    equalizeHist(img,dst);
    imshow("dst",dst);

    waitKey();
    return 0;
}