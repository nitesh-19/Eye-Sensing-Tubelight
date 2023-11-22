#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>

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
                R"(C:\\Users\\Nitesh\\Documents\\(B)CommonFiles\\Coding_Workspace\\Face-Detection\\haarcascade_frontalface_default.xml)");
        faceCascade.detectMultiScale(img, faces, 1.1, 10);
        for (int i = 0; i < faces.size(); i++) {
            rectangle(img, faces[i].tl(), faces[i].br(), Scalar(0, 255, 2), 2);
        }
        imshow("Webcam", img);
        waitKey(10);
    }


//    string path = R"(C:\\Users\\Nitesh\\Documents\\(B)CommonFiles\\Coding_Workspace\\Face-Detection\\man.jpg)";


//    imshow("Image", img);
//    waitKey(0);
    std::cout << "Hello, World!" << std::endl;

    return 0;
}
