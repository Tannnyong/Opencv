#include<cv.h>
#include<highgui.h>


using namespace cv;


int main()
{
    IplImage* img = cvLoadImage("1.bmp");
    cvShowImage("img",img);

    int w = img->width;
    int h = img->height;

    IplImage* dst = cvCreateImage(cvGetSize(img),img->depth,img->nChannels);
    cvLogPolar(img, dst, Point(w / 2, h / 2), 60, CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS);
    cvShowImage("dst1",dst);


    IplImage* dst1 = cvCreateImage(cvGetSize(img),img->depth,img->nChannels);
    cvLogPolar(dst, dst1, Point(w / 2, h / 2), 60,17);
    cvShowImage("dst2", dst1);

    //Mat kernel = (Mat_<float>(3, 3) << 1 / 16, 1 / 8, 1 / 16, 1 / 8, 1 / 4, 1 / 8, 1 / 16, 1 / 8, 1 / 16);
    //double a[] = { 1 / 16, 1 / 8, 1 / 16, 1 / 8, 1 / 4, 1 / 8, 1 / 16, 1 / 8, 1 / 16 };
    //CvMat* ker = &cvMat(3, 3, CV_32FC1,a);
    //cvZero(ker);
    //cvmSet(ker, 0, 0, 0.0625);
    //cvmSet(ker, 0, 1, 0.125);
    //cvmSet(ker, 0, 2, 0.0625);
    //cvmSet(ker, 1, 0, 0.125);
    //cvmSet(ker, 1, 1, 0.25);
    //cvmSet(ker, 1, 2, 0.125);
    //cvmSet(ker, 2, 0, 0.0625);
    //cvmSet(ker, 2, 1, 0.125);
    //cvmSet(ker, 2, 2, 0.0625);

    Mat kernel;
    kernel = getGaussianKernel(5, 1.5);



    cvFilter2D(dst1, dst1, &(CvMat)kernel);
    cvShowImage("dst3",dst1);


    waitKey();
    return 0;
}