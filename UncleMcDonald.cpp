
#include <iostream>
#include <string>

using namespace std;

/*
* A basic definition of class (without external header file due to unnecessary complexity for such a basic class)
*/
class Farm {
private:
    int a = 0, b = 0, area = 0;
public:
    /*
    * public method of Farm class, which takes the fence/wire length. 
    * Since the algorithm is computationally simple it computes the required values and stores them in private parameters inside class
    */
    void fenceLen(int wire_len) {
        /*
        * the formula used to calculte the optimal dimensions is best explained here: https://blog.etrapez.pl/pochodne/zadania-optymalizacyjne/ (in polish)
        * or here in form of video: https://www.youtube.com/watch?v=lx8RcYcYVuU&t=1621s (in english)
        * since the floating part of the division will be discarded it should not cause a situtation where Uncle will not have enough wire to build a suggested size of fence
        */
        a = wire_len / 4;
        b = wire_len - 2 * a;
        area = a * b;
    }
    /*
    * A method printing the result in a fancy form along with ASCII graphic of the field.
    */
    void printResult() {
        //simple ASCII drawing, designed using https://asciiflow.com/
        cout << "|   ++\n|   ||  a=?\n|   |+------+\n| W ||  F   |\n| A ||  a   |\n| L ||  r   |b=?\n| L ||  m   |\n|   ||      |\n|   |+------+\n|   ||  a=?\n|   ++\n";
        //after showing a simple ASCII-art drawing, the resulting values are pritned
        cout << "The most optimal dimensions, maximizing the area of your farm are as follows\n >>a: " << a << " meters,\n >>b: " << b << " meters.\nThis gives an area of: " << area << " square meters." << endl;
    }
};
/*
* Function which returns integer value of fence/wire length provided by the user.
* Basic sanitization of input is handled here
*/
int getWireLen() {
    int wire_length = 0;
    while (wire_length <= 0) {
        //this ignores values which are larger then possible numeric limit for input (basic sanitization of user input)
        //resource used: https://stackoverflow.com/questions/10178830/input-validation-for-numeric-input
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



//initial function that asks user to type RUN or EXIT in a loop and either terminates the program or runs next functions to get fence length and calculate best dimensions
void farmingStarter() {
    string input = "";
    cout << "Hello Uncle McDonald!\nI am here to help you figure out how long and wide your fence will be to maximise the area of you farm.\n";
    do {
        cin.clear();
        cout << "\nType \"RUN\" to start, or \"EXIT\" to exit the program: ";
        cin >> input;
        cout << endl;
        //when user entered RUN the calculation part starts
        if (input == "RUN" || input == "run") {
            cout << "Let's go!" << endl;
            //Farm class object is initialized
            Farm uncleFarm1;
            //fenceLen() method is called with parameter being output of user-provided fence/wire length (see getWireLen() function definition)
            uncleFarm1.fenceLen(getWireLen());
            //printResult() method shows the result on the console
            uncleFarm1.printResult();
            //since the input value triggering calculations is not 'EXTI', user will be presented with option to run the algorithm once again or exit the application
        }
        else {
            cout << "You entered: " << input << endl;
        }
        //program will continue to execute until EXIT is entered or is terminated externally
    } while (input != "EXIT" && input != "exit");
}

int main()
{
    farmingStarter();
}

