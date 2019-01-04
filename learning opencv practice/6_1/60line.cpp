#include<opencv.hpp>

using namespace cv;


int main(int argc, char* argv[])
{
    Mat img = imread("60∂»œﬂ.png",1);
    imshow("source",img);
    Mat img1;
    Mat ker = (Mat_<char>  (5, 5)<< -1, -1, 2, -1, -1,
                                    0, 0, 0, 0, 0,
                                    -1, 2, -1, -1, -1,
                                    0, 0, 0, 0, 0,
                                    2, -1, -1, -1, -1);
    filter2D(img, img1, CV_8UC1, ker);
  //  printf("%d \n",img1.type());
    threshold(img1, img1, 80, 255,16);
    


    Mat element = getStructuringElement(0,Size(4,4));
    dilate(img1,img1,element);

    Mat img2 = Mat(img.size(), img.type(), Scalar(0, 0, 255));
   // imshow("dst1", img2);
   // printf("%d \n", img2.channels());
   // printf("%d \n", img.channels());

    cvtColor(img1, img1,CV_RGB2GRAY);
    add(img,img2,img,img1);
    imshow("dst", img);
    imshow("dst2", img1);

    waitKey();
    return 0;

}