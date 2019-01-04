#include<cv.h>
#include<highgui.h>

using namespace cv;

int main()
{
    Mat img = imread("1.jpg",0);
    imshow("src", img);

    Mat edge;
    Canny(img, edge, 50, 200, 3);
    imshow("edge",edge);

    vector<Vec2f> lines;
    HoughLines(edge, lines, 1, CV_PI / 180, 120);


    Mat dst1 = img.clone();

    for (size_t i = 0; i < lines.size(); i++)
    {
        float rho = lines[i][0];
        float theta = lines[i][1];//提取出距离和角度
        float a = cos(theta);
        float b = sin(theta);
        line(dst1, Point(cvRound(a*rho + 1000 * b), cvRound(b*rho - 1000 * a)), Point(cvRound(a*rho - 1000 * b), cvRound(b*rho + 1000 * a)), Scalar(0, 0, 255), 2); //1000这个参数控制了所绘制的直线的长度，该值越小，所绘制的直线长度越短
    }
    imshow("dst", dst1);

    vector<Vec4i> lines1;
    HoughLinesP(edge, lines1, 1, CV_PI / 180, 30 ,30,5);
    //dst:边缘检测的输出图像. 它应该是个灰度图,作为我们的输入图像  
    //１：参数极径 r 以像素值为单位的分辨率. 我们使用 1 像素.  
    //CV_PI/180:参数极角 \theta 以弧度为单位的分辨率. 我们使用 1度 (即CV_PI/180)  
    //50:要”检测” 一条直线所需最少的的曲线交点  
    //50:能组成一条直线的最少点的数量. 点数量不足的直线将被抛弃.  
    //10:线段上最近两点之间的阈值,也就是能被认为在一条直线上的亮点的最大距离.


    Mat dst2 = img.clone();
    for (size_t j = 0; j < lines1.size(); j++)
    {
        Vec4i  L = lines1[j];
        line(dst2,Point(L[0],L[1]),Point(L[2],L[3]),Scalar(0,255,0),2);

    }
    imshow("dst1", dst2);

    /*
    image为输入图像，要求是灰度图像		
    circles为输出圆向量，每个向量包括三个浮点型的元素——圆心横坐标，圆心纵坐标和圆半径		
    method为使用霍夫变换圆检测的算法，Opencv2.4.9只实现了2-1霍夫变换，它的参数是CV_HOUGH_GRADIENT		
    dp为第一阶段所使用的霍夫空间的分辨率，dp=1时表示霍夫空间与输入图像空间的大小一致，dp=2时霍夫空间是输入图像空间的一半，以此类推		
    minDist为圆心之间的最小距离，如果检测到的两个圆心之间距离小于该值，则认为它们是同一个圆心

    第六个参数，double类型的param1，有默认值100。它是第三个参数method设置的检测方法的对应的参数。
            对当前唯一的方法霍夫梯度法CV_HOUGH_GRADIENT，它表示传递给canny边缘检测算子的高阈值，
            而低阈值为高阈值的一半。
    第七个参数，double类型的param2，也有默认值100。它是第三个参数method设置的检测方法的对应的参数。
            对当前唯一的方法霍夫梯度法CV_HOUGH_GRADIENT，它表示在检测阶段圆心的累加器阈值。
            它越小的话，就可以检测到更多根本不存在的圆，而它越大的话，能通过检测的圆就更加接近完美的圆形了。
    第八个参数，int类型的minRadius, 有默认值0，表示圆半径的最小值。
    第九个参数，int类型的maxRadius, 也有默认值0，表示圆半径的最大值。需要注意的是，使用此函数可以很容易地检测出圆的圆心，但是它可能找不到合适的圆半径

    */
    vector<Vec3f> circel;
    HoughCircles(edge, circel, CV_HOUGH_GRADIENT, 1, 20, 100, 80, 0, 0);
    Mat dst3 = img.clone();
    for (size_t i = 0; i < circel.size(); i++)
    {
        Vec3f C = circel[i];
        circle(dst3,Point(C[0],C[1]),C[2],Scalar(0,255,0),3);
    }
    imshow("dst2", dst3);

    waitKey();
    return 0;
}

