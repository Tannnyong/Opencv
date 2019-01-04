//#include<cv.h>
//#include<highgui.h>
//#include<iostream>
//
//using namespace cv;
//using namespace std;
//
//
//
//int main()
//{
//    Mat img = imread("1.bmp");
//    imshow("src",img);
//
//    Mat kernel = (Mat_<float>(3, 3) << -1, 0, 1, -2, 0, 2, -1, 0, 1);
//    Mat imgx;
//    Mat imgxx;
//    filter2D(img,imgx,img.depth(),kernel);
//    Sobel(img,imgxx,img.depth(),1,0,3);
//    imshow("dst", imgx);
//    imshow("dst111", imgxx);
//
//    Mat kernel2 = (Mat_<float>(3, 3) << -1, -2, -1, 0, 0, 0, 1, 2, 1);
//    Mat imgy;
//    filter2D(img, imgy, img.depth(), kernel2);
//    imshow("dst2", imgy);
//
//    Mat val = (imgx).mul(imgx) + (imgy).mul(imgy);
//    Mat ValSqrt;
//    val.convertTo(val, CV_32F);
//    ValSqrt.convertTo(ValSqrt, CV_32F);
//   // cout << val.type() << endl;
//   // cout << ValSqrt.type() << endl;
//    sqrt(val, ValSqrt);
//    imshow("dst3", ValSqrt);
//    cvtColor(ValSqrt, ValSqrt,CV_RGB2GRAY);
//
//    Mat val1 = (imgx).mul(imgy);
//    imshow("dst4", val1);
//    val1.convertTo(val1, CV_32F);
//    cvtColor(val1, val1, CV_RGB2GRAY);
//    Mat theta;
//
//    double MAXVAL=0,MINVAL=0;
//    Point max, min;
//    minMaxLoc(ValSqrt, &MINVAL, &MAXVAL, &min, &max);
//    cout << MAXVAL << endl;
//    cout << MINVAL << endl;
//    cout << max << endl;
//    cout << min << endl;
//
//
//    imgxx.convertTo(imgxx, CV_32S);
//    int i,j;
//    for (i = 0; i < 480; i++)
//    {
//        for(j = 0; j < 640; j++)
//        {
//
//            int val000 = imgxx.at<int>(i, j);
//            if (val000 > 0)
//            {
//            cout << val000 << endl;  
//            }
//
//        }
//           
//
//    }
//  
//    //uchar pixel_value = imgx.at<uchar>(379, 23);
//    //float xx = val1.at<uchar>(max.x, max.y);
//    float y = 0;
//    //cvFastArctan(y, xx);
//    
//   // cout << xx << endl;
//    //cout << val1.at<uchar>(max.x, max.y)<< endl;
//
//    waitKey();
//    return 0;
//}





//#include "cv.h"
//
//#include "highgui.h"
//
//#include <iostream>
//
//
//using namespace std;
//
//int main(int argc, char** argv)
//
//{
//
//    const CvSize size = cvSize(512, 512);
//
//    const int aperture[] = { 3, 5, 7 };
//
//    IplImage* src = cvCreateImage(size, 8, 1);
//
//
//
//    cvZero(src);
//
//
//
//    cvLine(src, cvPoint(0, 0), cvPoint(size.width - 1, size.height - 1), CV_RGB(255, 255, 255), 3);
//
//
//
//    cvNamedWindow("src", CV_WINDOW_AUTOSIZE);
//
//    cvShowImage("src", src);
//
//
//
//    IplImage*  deriv_x = cvCreateImage(size, IPL_DEPTH_32F, 1); //x方向导数形成的图像
//
//    IplImage*  deriv_y = cvCreateImage(size, IPL_DEPTH_32F, 1); //y方向导数形成的图像
//
//
//
//    IplImage* angle = cvCreateImage(size, IPL_DEPTH_32F, 1);  //进行极坐标变换后形成的角度图像
//
//    IplImage* magnitude = cvCreateImage(size, IPL_DEPTH_32F, 1);//进行极坐标变换后形成的幅度图像
//
//    IplImage* mask = cvCreateImage(size, IPL_DEPTH_8U, 1);//进行比较过后（选取幅度超过阈值的点）形成的模板图像
//
//
//
//    cvNamedWindow("src", CV_WINDOW_AUTOSIZE);
//
//    cvNamedWindow("mask", CV_WINDOW_AUTOSIZE);
//
//
//
//    for (int i = 0; i<sizeof(aperture) / sizeof(aperture[0]); i++)
//
//    {
//
//        cvSobel(src, deriv_x, 1, 0, aperture[i]);//x求导
//
//        cvSobel(src, deriv_y, 0, 1, aperture[i]);//y求导
//
//
//        cvCartToPolar(deriv_x, deriv_y, magnitude, angle, 1);//极坐标变换
//
//
//
//        cvSave("x.xml", deriv_x);
//
//        cvSave("y.xml", deriv_y);
//
//        cvSave("magnitude.xml", magnitude);
//
//        cvSave("angle.xml", angle);
//
//
//
//        double maxmag, minmag, maxangle, minangle;
//
//        cvMinMaxLoc(magnitude, &minmag, &maxmag);
//
//        cvMinMaxLoc(angle, &minangle, &maxangle);
//
//
//
//        cout << "magnitude: max=" << maxmag << " ,min=" << minmag << endl;
//
//        cout << "angle: max=" << maxmag << " ,min=" << minangle << endl;
//
//
//
//        //生成模板
//
//        cvCmpS(magnitude, maxmag * 3 / 4, mask, CV_CMP_GT);//寻找最大幅值附近的点
//
//        CvScalar scalar = cvAvg(magnitude, mask);
//
//        cout << "aperture=" << aperture[i] << ", line angle =" << scalar.val[0] << endl;
//
//
//
//        cvShowImage("src", src);
//
//        cvShowImage("mask", mask);
//
//
//
//        if (27 == cvWaitKey(0))
//
//        {
//
//            continue;
//
//        }
//
//
//
//    }
//
//
//
//    cvReleaseImage(&src);
//
//    cvReleaseImage(&deriv_x);
//
//    cvReleaseImage(&deriv_y);
//
//    cvReleaseImage(&magnitude);
//
//    cvReleaseImage(&angle);
//
//    cvReleaseImage(&mask);
//
//    cvDestroyAllWindows();
//
//    return 1;
//
//}


#include "cv.h"

#include "highgui.h"

#include "stdio.h"

#include <iostream>

#include "math.h"

using namespace std;

int main(int argc, char **argv[])

{



    IplImage * m_image = cvLoadImage("1.bmp", CV_LOAD_IMAGE_GRAYSCALE);

    IplImage * Sobel_3_x = cvCreateImage(cvGetSize(m_image), IPL_DEPTH_32F, 1);//存放x方向导数

    IplImage * Sobel_3_y = cvCreateImage(cvGetSize(m_image), IPL_DEPTH_32F, 1);//存放y方向导数





    cvSobel(m_image, Sobel_3_x, 1, 0, 3);

    cvSobel(m_image, Sobel_3_y, 0, 1, 3);



    CvMat* m_mat = cvCreateMat(m_image->height, m_image->width, CV_32FC1);  //存放幅值

    cvZero(m_mat);

    double val_max = 0.0;

    double theta = 0.0;

    for (int i = 0; i<m_image->height; i++)

    {

        for (int j = 0; j<m_image->width; j++)

        {

            double x = cvGetReal2D(Sobel_3_x, i, j);

            double y = cvGetReal2D(Sobel_3_y, i, j);

            double val = (double)sqrt((x)*(x)+y*y);              //计算幅值并赋值

            cvSetReal2D(m_mat, i, j, val);

            if (val >= val_max&&val >1)

            {

                val_max = val;

            }





        }

    }

    for (int i = 0; i<m_image->height; i++)

    {

        for (int j = 0; j<m_image->width; j++)

        {

            double x = cvGetReal2D(Sobel_3_x, i, j);

            double y = cvGetReal2D(Sobel_3_y, i, j);

            double val = (double)sqrt((x)*(x)+y*y);              //计算幅值并赋值

            cvSetReal2D(m_mat, i, j, val);

            if (abs(val - val_max)<100)

            {

                if (theta != 0.0)

                {

                    theta = theta + 180 / 3.14*atan2(abs(y), abs(x));      //找幅值附近的值求平均，并记录对应的角度

                    theta = theta / 2.0;

                }

                else

                    theta = 180 / 3.14*atan2(abs(y), abs(x));

            }



        }





    }











    cout << "3*3中孔：" << endl;

    cout << "最大幅值为" << val_max << endl;

    cout << "对应的角度" << theta << endl;



    cvShowImage("CMAT", m_mat);

    cvShowImage("Src", m_image);



    cvWaitKey(0);

    cvReleaseImage(&m_image);

    cvReleaseImage(&Sobel_3_x);

    cvReleaseImage(&Sobel_3_y);

    cvReleaseMat(&m_mat);

    cvDestroyWindow("Src");



    return 0;

}
