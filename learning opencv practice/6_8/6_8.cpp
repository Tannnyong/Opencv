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
        float theta = lines[i][1];//��ȡ������ͽǶ�
        float a = cos(theta);
        float b = sin(theta);
        line(dst1, Point(cvRound(a*rho + 1000 * b), cvRound(b*rho - 1000 * a)), Point(cvRound(a*rho - 1000 * b), cvRound(b*rho + 1000 * a)), Scalar(0, 0, 255), 2); //1000������������������Ƶ�ֱ�ߵĳ��ȣ���ֵԽС�������Ƶ�ֱ�߳���Խ��
    }
    imshow("dst", dst1);

    vector<Vec4i> lines1;
    HoughLinesP(edge, lines1, 1, CV_PI / 180, 30 ,30,5);
    //dst:��Ե�������ͼ��. ��Ӧ���Ǹ��Ҷ�ͼ,��Ϊ���ǵ�����ͼ��  
    //������������ r ������ֵΪ��λ�ķֱ���. ����ʹ�� 1 ����.  
    //CV_PI/180:�������� \theta �Ի���Ϊ��λ�ķֱ���. ����ʹ�� 1�� (��CV_PI/180)  
    //50:Ҫ����⡱ һ��ֱ���������ٵĵ����߽���  
    //50:�����һ��ֱ�ߵ����ٵ������. �����������ֱ�߽�������.  
    //10:�߶����������֮�����ֵ,Ҳ�����ܱ���Ϊ��һ��ֱ���ϵ������������.


    Mat dst2 = img.clone();
    for (size_t j = 0; j < lines1.size(); j++)
    {
        Vec4i  L = lines1[j];
        line(dst2,Point(L[0],L[1]),Point(L[2],L[3]),Scalar(0,255,0),2);

    }
    imshow("dst1", dst2);

    /*
    imageΪ����ͼ��Ҫ���ǻҶ�ͼ��		
    circlesΪ���Բ������ÿ�������������������͵�Ԫ�ء���Բ�ĺ����꣬Բ���������Բ�뾶		
    methodΪʹ�û���任Բ�����㷨��Opencv2.4.9ֻʵ����2-1����任�����Ĳ�����CV_HOUGH_GRADIENT		
    dpΪ��һ�׶���ʹ�õĻ���ռ�ķֱ��ʣ�dp=1ʱ��ʾ����ռ�������ͼ��ռ�Ĵ�Сһ�£�dp=2ʱ����ռ�������ͼ��ռ��һ�룬�Դ�����		
    minDistΪԲ��֮�����С���룬�����⵽������Բ��֮�����С�ڸ�ֵ������Ϊ������ͬһ��Բ��

    ������������double���͵�param1����Ĭ��ֵ100�����ǵ���������method���õļ�ⷽ���Ķ�Ӧ�Ĳ�����
            �Ե�ǰΨһ�ķ��������ݶȷ�CV_HOUGH_GRADIENT������ʾ���ݸ�canny��Ե������ӵĸ���ֵ��
            ������ֵΪ����ֵ��һ�롣
    ���߸�������double���͵�param2��Ҳ��Ĭ��ֵ100�����ǵ���������method���õļ�ⷽ���Ķ�Ӧ�Ĳ�����
            �Ե�ǰΨһ�ķ��������ݶȷ�CV_HOUGH_GRADIENT������ʾ�ڼ��׶�Բ�ĵ��ۼ�����ֵ��
            ��ԽС�Ļ����Ϳ��Լ�⵽������������ڵ�Բ������Խ��Ļ�����ͨ������Բ�͸��ӽӽ�������Բ���ˡ�
    �ڰ˸�������int���͵�minRadius, ��Ĭ��ֵ0����ʾԲ�뾶����Сֵ��
    �ھŸ�������int���͵�maxRadius, Ҳ��Ĭ��ֵ0����ʾԲ�뾶�����ֵ����Ҫע����ǣ�ʹ�ô˺������Ժ����׵ؼ���Բ��Բ�ģ������������Ҳ������ʵ�Բ�뾶

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

