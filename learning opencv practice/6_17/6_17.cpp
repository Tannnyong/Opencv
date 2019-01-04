#include<cv.h>
#include<highgui.h>

using namespace cv;

int main(int argc, char* argv[])
{
    Mat img = imread("1.jpg");
    imshow("img",img);

    Point2f point1[4], point2[4];

    point1[0].x = 0;
    point1[0].y = 0;
    point1[1].x = img.rows - 1;
    point1[1].y = 0;
    point1[2].x = 0;
    point1[2].y = img.cols - 1;
    point1[3].x = img.rows - 1;
    point1[3].y = img.cols - 1;

    point2[0].x = (img.rows - 1) / 6;
    point2[0].y = (img.cols - 1) / 5;
    point2[1].x = (img.rows - 1) / 2;
    point2[1].y = (img.cols - 1) / 5;
    point2[2].x = (img.rows - 1) / 5;
    point2[2].y = (img.cols - 1) / 2;
    point2[3].x = (img.rows - 1) / 2;
    point2[3].y = (img.cols - 1) / 2;


    Mat m;
    m=getPerspectiveTransform(point1,point2);

    Mat dst;
    warpPerspective(img,dst,m,img.size());
    imshow("dst",dst);

    Point2f point3[3], point4[3];

    point3[0].x = 0;
    point3[0].y = 0;
    point3[1].x = img.rows - 1;
    point3[1].y = 0;
    point3[2].x = 0;
    point3[2].y = img.cols - 1;


    point4[0].x = img.rows - 1;
    point4[0].y = 0;
    point4[1].x = img.rows - 1;
    point4[1].y = img.cols - 1;
    point4[2].x = 0;
    point4[2].y = 0;


    Mat m1;
    m1=getAffineTransform(point3,point4);

    Mat dst2;
    warpAffine(dst, dst2, m1, dst.size());

    imshow("dst1",dst2);

    Mat M = m1 * m;

    Mat dst3;
    warpAffine(img, dst3, M, dst.size());

    imshow("dst2",dst3);


    waitKey();
    return 0;
}