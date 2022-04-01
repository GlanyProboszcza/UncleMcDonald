// UncleMcDonald.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

int getWireLen() {
    int wire_length = 0;
    while (wire_length <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please write how many meters of fence you have available? (not more than 2 147 483 647 meters): ";
        cin >> wire_length;
        cout << endl;
    }
    cout << "Given wire length is: " << wire_length << " meters" << endl;
    return wire_length;
}

void getResult(int wire_length) {
    int a = 0, b = 0, area = 0;
    a = wire_length / 4;
    b = wire_length - 2 * a;
    area = a * b;
    cout << "The most optimal dimensions, maximizing the area of your farm are as follows\n a: " << a << " meters, and  b: " << b << " meters.\nThis gives an area of: " << area << " square meters." << endl;
}

void farmingStarter() {
    string input = "";

    cout << "Hello Uncle McDonald!\nI am here to help you figure out how long and wide your fence will be to maximise the area of you farm.\n";
    do {
        cout << "Type \"RUN\" to start, or \"EXIT\" to exit the program: ";
        cin >> input;
        cout << endl;
        if (input == "RUN") {
            cout << "Let's go!" << endl;
            getResult(getWireLen());
        }
        else {
            cout << "You entered: " << input << endl;
        }
    } while (input != "EXIT");
    cin.clear();
}

int main()
{
    farmingStarter();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
