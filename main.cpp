#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>

using namespace cv;
using namespace std;


int main() {
    string path = R"(C:\\Users\\Nitesh\\Documents\\(B)CommonFiles\\Coding_Workspace\\Face-Detection\\man.jpg)";
    Mat img = imread(path);
    CascadeClassifier faceCascade;
    faceCascade.load(
            R"(C:\\Users\\Nitesh\\Documents\\(B)CommonFiles\\Coding_Workspace\\Face-Detection\\haarcascade_frontalface_default.xml)");
    imshow("Image", img);
    waitKey(0);
    std::cout << "Hello, World!" << std::endl;

    return 0;
}
