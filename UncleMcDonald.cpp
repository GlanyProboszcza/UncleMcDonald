// UncleMcDonald.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a = 0, b = 0, wire_length = 0, area = 0;
    string input ="";

    cout << "Hello Uncle McDonald!\nI am here to help you figure out how long and wide your fence will be to maximise the area of you farm.\n";
    while (input != "RUN") {
        cout << "Type \"RUN\" to start: ";
        cin >> input;
        cout << endl;
        if (input == "RUN") {
            cout << "Let's go!" << endl;
        }
        else {
            cout << "You entered: " << input << endl;
        }
    }
    cin.clear();
    while (wire_length <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please write how many meters of fence you have available? (not more than 2 147 483 647 meters): ";
        cin >> wire_length;
        cout << endl;
    }
    cout << "Given wire length is: " << wire_length << " meters" << endl;
    a = wire_length / 4;
    b = wire_length - 2 * a;
    area = a*b;
    cout << "a: " << a << ", b: " << b << ", area: " << area << endl;
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
