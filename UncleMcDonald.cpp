
#include <iostream>
#include <string>

using namespace std;

int getWireLen() {
    int wire_length = 0;
    while (wire_length <= 0) {
        //this ignores values which are larger then possible numeric limit for input (basic sanitization of user input)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please write how many meters of fence you have available? (not more than 2 147 483 647 meters): ";
        cin >> wire_length;
        cout << endl;
        cin.clear();
    }
    //when there is a correct and sane wire length provided, function reports the given value (which can be trimmed in case it's bigger than 2147483647
    cout << "Given wire length is: " << wire_length << " meters" << endl;
    return wire_length;
}

void getResult(int wire_length) {
    int a = 0, b = 0, area = 0;
    /*
    the formula used to calculte the optimal dimensions is best explained here: https://blog.etrapez.pl/pochodne/zadania-optymalizacyjne/ (in polish)
    or here in form of video: https://www.youtube.com/watch?v=lx8RcYcYVuU&t=1621s (in english)
    since the floating part of the division will be discarded it should not cause a situtation where Uncle will not have enough wire to build a suggested size of fence
    */
    a = wire_length / 4;
    b = wire_length - 2 * a;
    area = a * b;
    //simple ASCII drawing, designed using https://asciiflow.com/
    cout << "|   ++\n|   ||  a=?\n|   |+------+\n| W ||  F   |\n| A ||  a   |\n| L ||  r   |b=?\n| L ||  m   |\n|   ||      |\n|   |+------+\n|   ||  a=?\n|   ++\n";
    //after showing a simple ASCII-art drawing, the resulting values are pritned
    cout << "The most optimal dimensions, maximizing the area of your farm are as follows\n >>a: " << a << " meters,\n >>b: " << b << " meters.\nThis gives an area of: " << area << " square meters." << endl;
}

//initial function that asks user to type RUN or EXIT in a loop and either terminates the program or runs next functions to get fence length and calculate best dimensions
void farmingStarter() {
    string input = "";
    cout << "Hello Uncle McDonald!\nI am here to help you figure out how long and wide your fence will be to maximise the area of you farm.\n";
    do {
        cin.clear();
        cout << "\nType \"RUN\" to start, or \"EXIT\" to exit the program: ";
        cin >> input;
        cout << endl;
        if (input == "RUN") {
            cout << "Let's go!" << endl;
            //when user entered RUN, there will first be a prompt for wire length by getWireLen() function, this will be passed to getResult() function which calculates and prints the result
            getResult(getWireLen());
            //since the input value triggering calculations is not 'EXTI', user will be presented with option to run the algorithm once again or exit the application.
        }
        else {
            cout << "You entered: " << input << endl;
        }
    } while (input != "EXIT");
}

int main()
{
    farmingStarter();
}

