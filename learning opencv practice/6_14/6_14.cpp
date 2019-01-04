#include<cv.h>
#include<highgui.h>


using namespace cv;


int main()
{
    Mat image = imread("2.png");		
    //cvtColor(image,image,CV_RGB2GRAY); 


    //原图像是三通道，积分图也是三通道	
    Mat imageIntegral;	
    integral(image,imageIntegral,CV_32F); 

    //计算积分图	
    normalize(imageIntegral,imageIntegral,0,255,CV_MINMAX);  

    //归一化，方便显示	
    Mat imageIntegralNorm;	
    convertScaleAbs(imageIntegral,imageIntegralNorm); 


    //精度转换为8位int整型	
    imshow("Source Image",image);	
    imshow("Integral Image",imageIntegralNorm);	



    waitKey();
    return 0;
}