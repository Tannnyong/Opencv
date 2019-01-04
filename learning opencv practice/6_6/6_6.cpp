#include<cv.h>
#include<highgui.h>


using namespace cv;

int main()
{
    Mat img = imread("1.jpg");
    imshow("img",img);

    Mat imgx;
    Mat imgy;
    Sobel(img, imgx, img.depth(), 1, 0, 3);
    Sobel(img, imgy, img.depth(), 0, 1, 3);
    imshow("img1",imgx);
    imshow("img2",imgy);

    Mat img3;
    Laplacian(img, img3, img.depth(), 5);
    imshow("img3",img3);

    cvtColor(img3,img3,CV_RGB2GRAY);
    imshow("img4", img3);


    Mat element = getStructuringElement(CV_SHAPE_RECT,Size (3,3));
    morphologyEx(img3, img3, CV_MOP_CLOSE,element,Point(-1,-1),13);
    imshow("img5", img3);


    waitKey();
    return 0;
}