#include <iostream>
#include <Eigen/Dense>
#include "Board.h"
#include "Snake.h"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace Eigen;
using namespace std;

int main(){
    Board b(50, 50);
    //b.plot();
    cv::Mat m = cv::Mat::zeros(500, 500, CV_32F);
    imshow("AAA", m);
    cv::waitKey(0);
    cout << "after show" << endl;
    //Snake s;
}
