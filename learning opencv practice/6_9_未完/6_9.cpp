#include<cv.h>
#include<highgui.h>

using namespace cv;

int main(int argc, char* argv[])
{
    Mat img = imread("1.bmp");
    imshow("img",img);

    Mat dst = img.clone();
    cvtColor(img, img, CV_RGB2GRAY);

    Mat edge;
    Canny(img,edge,50,100);

    vector<Vec4i> P;
    HoughLinesP(edge,P,1,CV_PI/180,30,30,10);

    for (size_t i = 0; i < P.size(); i++)
    {
        Vec4i point = P[i];
        line(dst, Point(point[0],point[1]),Point(point[2],point[3]),Scalar(0,0,255),2 );

    }

    imshow("dst", dst);

    waitKey();
    return 0;
}