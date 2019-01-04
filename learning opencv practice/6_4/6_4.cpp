#include<cv.h>
#include<highgui.h>


using namespace cv;

/*
帕斯卡三角如下：

            1   0   -1  
        1   2   0   -2  -1
    1   4   5   0   -5  -4  -1
1, 6, 14, 14, 0, -14, -14, -6, -1

            1   2   1
        1   4   6   4   1
    1   6   15  20  15  6   1
1   8   28  56  70  56  28  8  1
*/


int main(int argc, char* argv)
{
    Mat img = imread("1.bmp");
    imshow("src",img);

    Mat img1;
    Mat kernel = (Mat_<float>(3, 3) << -1, 0, 1, -2, 0, 2, -1, 0, 1);
    filter2D(img,img1,img.depth(),kernel);
    imshow("dst",img1);
    Mat img2;
    Mat kernel2 = (Mat_<float>(3, 3) << -1, -2, -1, 0, 0, 0, 1, 2, 1);
    filter2D(img, img2, img.depth(), kernel2);
    imshow("dst2", img2);

    Mat img3;
    Mat kernel3 = (Mat_<float>(5, 5) <<  1, 2, 0, -2, -1,
                                        4, 8, 0, -8, -4, 
                                        6, 12, 0, -12, -6, 
                                        4, 8, 0, -8, -4, 
                                        1, 2, 0, -2, -1);
    filter2D(img, img3, img.depth(), kernel3);
    imshow("dst3", img3);
    Mat img4;
    Mat kernel4=kernel3.t();
    //Mat kernel2 = (Mat_<float>(3, 3) << 1, 2, 0, -2, -1,
    //                                    4, 8, 0, -8, -4,
    //                                    6, 12, 0, -12, -6,
    //                                    4, 8, 0, -8, -4,
    //                                    1, 2, 0, -2, -1);
     filter2D(img, img4, img.depth(), kernel4);
     imshow("dst4", img4);


     Mat kernel5 = (Mat_<float>(1, 9) << 1, 8, 28, 56, 70, 56, 28, 8, 1);
     Mat kernel6 = (Mat_<float>(9, 1) << 1, 6, 14, 14, 0, -14, -14, -6, -1);
     Mat kernel7 = kernel6*kernel5;
     Mat img5;
     filter2D(img, img5, img.depth(), kernel7);
     imshow("dst5", img5);

     Mat kernel8 = kernel7.t();
     Mat img6;
     filter2D(img, img6, img.depth(), kernel8);
     imshow("dst6", img6);

    waitKey();
    return 0;
}




