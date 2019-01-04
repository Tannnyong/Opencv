#include<cv.h>
#include <highgui.h>


using namespace cv;



int main()
{

    Mat img = imread("2.png", 0);
    imshow("img1", img);

    int n = getOptimalDFTSize(img.rows);
    int m = getOptimalDFTSize(img.cols);

    Mat img1;
    Mat img2;
    copyMakeBorder(img, img1, 0, n - img.rows, 0, m - img.cols, BORDER_CONSTANT, 0);
    //IPL_BORDER_CONSTANT - ���߽�Ϊ�̶�ֵ��ֵ�ɺ������һ������ָ����
    //IPL_BORDER_REPLICATE -�߽��������л������������������

    Mat img1s[] = { Mat_<float>(img1), Mat::zeros(img1.size(), CV_32F) };
    merge(img1s, 2, img2);
    dft(img2, img2);
    split(img2, img1s);
    magnitude(img1s[0], img1s[1], img1s[0]);
    //printf("img.rows = %d", img.rows);
    imshow("img2", img1s[0]);


    //���ж����ߴ�����(logarithmic scale)
    img1s[0] += Scalar::all(1);
    log(img1s[0], img1s[0]);//����Ȼ����
    //���к��طֲ�����
    //���������л����У�����Ƶ�ײü�
    img1s[0] = img1s[0](Rect(0, 0, img1s[0].cols & -2, img1s[0].rows & -2));
    //�������и���Ҷͼ���е����ޣ�ʹ��ԭ��Ϊ��ͼ������
    int cx = img1s[0].cols / 2;
    int cy = img1s[0].rows / 2;
    Mat q0(img1s[0], Rect(0, 0, cx, cy));//ROI���������
    Mat q1(img1s[0], Rect(cx, 0, cx, cy));//����
    Mat q2(img1s[0], Rect(0, cy, cx, cy));//����
    Mat q3(img1s[0], Rect(cx, cy, cx, cy));//����
    //�������ޣ����������½��н�����
    Mat tmp;
    q0.copyTo(tmp);
    q3.copyTo(q0);
    tmp.copyTo(q3);
    //�������ޣ����������½�����
    q1.copyTo(tmp);
    q2.copyTo(q1);
    tmp.copyTo(q2);
    //��һ������0��1֮��ĸ���ֵ������任Ϊ���ӵ�ͼ���ʽ
    normalize(img1s[0], img1s[0], 0, 1, NORM_MINMAX);
    //��ʾЧ��ͼ
    imshow("Ƶ�׷�ֵ", img1s[0]);

    waitKey();
    return 0;
}
