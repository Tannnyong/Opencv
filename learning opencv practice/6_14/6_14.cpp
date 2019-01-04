#include<cv.h>
#include<highgui.h>


using namespace cv;


int main()
{
    Mat image = imread("2.png");		
    //cvtColor(image,image,CV_RGB2GRAY); 


    //ԭͼ������ͨ��������ͼҲ����ͨ��	
    Mat imageIntegral;	
    integral(image,imageIntegral,CV_32F); 

    //�������ͼ	
    normalize(imageIntegral,imageIntegral,0,255,CV_MINMAX);  

    //��һ����������ʾ	
    Mat imageIntegralNorm;	
    convertScaleAbs(imageIntegral,imageIntegralNorm); 


    //����ת��Ϊ8λint����	
    imshow("Source Image",image);	
    imshow("Integral Image",imageIntegralNorm);	



    waitKey();
    return 0;
}