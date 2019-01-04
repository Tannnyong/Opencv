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
    //IPL_BORDER_CONSTANT - 填充边界为固定值，值由函数最后一个参数指定。
    //IPL_BORDER_REPLICATE -边界用上下行或者左右列来复制填充

    Mat img1s[] = { Mat_<float>(img1), Mat::zeros(img1.size(), CV_32F) };
    merge(img1s, 2, img2);
    dft(img2, img2);
    split(img2, img1s);
    magnitude(img1s[0], img1s[1], img1s[0]);
    //printf("img.rows = %d", img.rows);
    imshow("img2", img1s[0]);


    //进行对数尺寸缩放(logarithmic scale)
    img1s[0] += Scalar::all(1);
    log(img1s[0], img1s[0]);//求自然对数
    //剪切和重分布象限
    //若有奇数行或技术列，进行频谱裁剪
    img1s[0] = img1s[0](Rect(0, 0, img1s[0].cols & -2, img1s[0].rows & -2));
    //重新排列傅里叶图像中的象限，使得原点为与图像中心
    int cx = img1s[0].cols / 2;
    int cy = img1s[0].rows / 2;
    Mat q0(img1s[0], Rect(0, 0, cx, cy));//ROI区域的左上
    Mat q1(img1s[0], Rect(cx, 0, cx, cy));//右上
    Mat q2(img1s[0], Rect(0, cy, cx, cy));//左下
    Mat q3(img1s[0], Rect(cx, cy, cx, cy));//右下
    //交换象限（左上与右下进行交换）
    Mat tmp;
    q0.copyTo(tmp);
    q3.copyTo(q0);
    tmp.copyTo(q3);
    //交换象限（右上与左下交换）
    q1.copyTo(tmp);
    q2.copyTo(q1);
    tmp.copyTo(q2);
    //归一化，用0到1之间的浮点值将矩阵变换为可视的图像格式
    normalize(img1s[0], img1s[0], 0, 1, NORM_MINMAX);
    //显示效果图
    imshow("频谱幅值", img1s[0]);

    waitKey();
    return 0;
}
