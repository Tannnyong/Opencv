#include<cv.h>
#include<highgui.h>

using namespace cv;

int main(int argc, char* argv[])
{
    IplImage* img = cvLoadImage("1.bmp");
    cvShowImage("src",img);
    int w = img->width;
    int h = img->height;

    IplImage* dst = cvCreateImage(cvGetSize(img),img->depth,img->nChannels);
    cvLogPolar(img, dst,Point(w/2,h/2),60);
    cvShowImage("dst",dst);

    IplImage* img2 = cvLoadImage("2.bmp");
    cvShowImage("src1",img2);
    int w1 = img2->width;
    int w2 = img2->height;

    IplImage* dst2 = cvCreateImage(cvGetSize(img2),img2->depth,img2->nChannels);
    cvLogPolar(img2,dst2,Point(0,0),60);
    cvShowImage("dst2",dst2);


    IplImage* img3 = cvLoadImage("2.bmp");
    //cvShowImage("src1", img3);
    //int w1 = img2->width;
    //int w2 = img2->height;

    IplImage* dst3 = cvCreateImage(cvGetSize(img2), img2->depth, img2->nChannels);
    cvLogPolar(img3, dst3, Point(160, 336), 60);
    cvShowImage("dst3", dst3);

    waitKey();
    return 0;
}