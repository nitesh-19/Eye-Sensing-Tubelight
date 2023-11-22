#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include "mqtt/async_client.h"
#include "mqtt/topic.h"

using namespace cv;
using namespace std;


int main() {
    VideoCapture webcam(0);
    CascadeClassifier faceCascade;
    vector<Rect> faces;
    Mat img;

    while (true) {
        webcam.read(img);
        faceCascade.load(
                R"(C:\\Users\\Nitesh\\Documents\\(B)CommonFiles\\Coding_Workspace\\Face-Detection\\haarcascade_eye.xml)");
        faceCascade.detectMultiScale(img, faces, 1.1, 5);
        for (auto &face: faces) {
            rectangle(img, face.tl(), face.br(), Scalar(0, 255, 2), 2);
        }
        imshow("Webcam", img);
        waitKey(15);
    }


//    string path = R"(C:\\Users\\Nitesh\\Documents\\(B)CommonFiles\\Coding_Workspace\\Face-Detection\\man.jpg)";


//    imshow("Image", img);
//    waitKey(0);
    std::cout << "Hello, World!" << std::endl;

    return 0;
}
