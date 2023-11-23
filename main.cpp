#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include "mqtt/client.h"
#include "mqtt/async_client.h"
#include "mqtt/message.h"
#include<windows.h>


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
    const string server_url = "mqtt://192.168.1.4/1883";
    const string client_id = "openbkt";


    mqtt::async_client my_client(server_url, "");
    mqtt::topic topic { my_client, "openbkt/2/set", 1};

    try {
        std::cout << "Connecting to the chat server at '" << server_url
            << "'..." << std::flush;
        auto tok = my_client.connect();
        tok->wait();

        

        topic.subscribe()->wait();
        std::cout << "Ok" << std::endl;
    }
    catch (const mqtt::exception& exc) {
        std::cerr << "\nERROR: Unable to connect. "
            << exc.what() << std::endl;

    }

    string values[2] = { "0", "60" };

    faceCascade.load(R"(C:\Users\Nitesh\Documents\(B)CommonFiles\Coding_Workspace\Face-Detection\haarcascade_eye.xml)");
    int i = 0;

    while (true) {
        webcam.read(img);
        cvtColor(img, img, COLOR_BGR2GRAY);

        faceCascade.detectMultiScale(img, faces, 1.1,6);
        if (!faces.empty()) {
            for (&i; i <= 60; i++) {
                topic.publish(to_string(i));
                Sleep(8);
            }
            while (!faces.empty()) {
               // topic.publish(to_string(60));
                webcam.read(img);
                cvtColor(img, img, COLOR_BGR2GRAY);
                cout << "face" << endl;

                faceCascade.detectMultiScale(img, faces, 1.1, 6);

            }
        }
        else
        {
            for (&i; i >= 0; i--) {
                topic.publish(to_string(i));
                Sleep(5);
            }
                while (faces.empty()) {
                   // topic.publish(to_string(0));
                    webcam.read(img);
                    cvtColor(img, img, COLOR_BGR2GRAY);

                    cout << "no face" << endl;
                    faceCascade.detectMultiScale(img, faces, 1.1, 6);

                


            }

        }
        //for (auto &face: faces) {
       //     rectangle(img, face.tl(), face.br(), Scalar(0, 255, 2), 2);
        //}
        //imshow("Webcam", img);
        //topic.publish(values[i%2]);

        //waitKey(15);
    }


}
