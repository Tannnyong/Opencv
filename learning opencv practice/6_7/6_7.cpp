#include<cv.h>
#include<highgui.h>


using namespace cv;


int main(int argc, char* argv[])
{
    Mat img = imread("1.jpg");
    imshow("src", img);

    double threshold1 = 30;

    Mat dst;
    Canny(img, dst, threshold1, 1.5*threshold1); //30-45
    imshow("dst",dst);

    Mat dst1;
    Canny(img, dst1, threshold1, 2.5*threshold1);//30-75
    imshow("dst1", dst1);

    Mat dst2;
    Canny(img, dst2, threshold1, 4.5*threshold1);//30-130
    imshow("dst2", dst2);

    Mat dst3;
    Canny(img, dst3, threshold1, 6 * threshold1);//30-180
    imshow("dst3", dst3);

    Mat dst4;
    Canny(img, dst4, threshold1, 8 * threshold1);//30-240
    imshow("dst4", dst4);
    waitKey();
    return 0;
}
