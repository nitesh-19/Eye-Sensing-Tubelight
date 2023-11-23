#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include "mqtt/client.h"
#include "mqtt/async_client.h"
#include "mqtt/message.h"


using namespace cv;
using namespace std;


void mqtt_handler() {
    const string server_url = "mqtt://192.168.1.4/1883";
    const string client_id = "openbkt";


    mqtt::async_client my_client(server_url, "");
    mqtt::topic topic { my_client, "openbkt/2/set", 1};

    try {
        std::cout << "Connecting to the chat server at '" << server_url
            << "'..." << std::flush;
        auto tok = my_client.connect();
        tok->wait();

        // Subscribe to the topic using "no local" so that
        // we don't get own messages sent back to us

        std::cout << "Ok\nJoining the group..." << std::flush;

        topic.subscribe()->wait();
        std::cout << "Ok" << std::endl;
    }
    catch (const mqtt::exception& exc) {
        std::cerr << "\nERROR: Unable to connect. "
            << exc.what() << std::endl;
       
    }
    topic.publish("50");
}

int main() {
    VideoCapture webcam(0);
    CascadeClassifier faceCascade;
    vector<Rect> faces;
    Mat img;
    mqtt_handler();
    faceCascade.load(
        R"(C:\\Users\\Nitesh\\Documents\\(B)CommonFiles\\Coding_Workspace\\Face-Detection\\haarcascade_eye.xml)");
    while (true) {
        webcam.read(img);
        
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
