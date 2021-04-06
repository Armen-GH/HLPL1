#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <limits>

using namespace std;

int main()
{
    int sum_total = 10;

    cout << "Player A and Player B flip a total of 10 coins.  Player A flips first, Player B flips back, alternativaly.  You can flip 1-3 coins per turn, the 10th coin is the winner" << endl;
    
    vector<string> player(2);
    player[0] = "Player A";
    player[1] = "Player B";
    int select = 0, n = 0; 
    char user_input;


    while (sum_total)
    {
        cout << "There are " << sum_total << " pieces left. Now, " << player[n] << " please Choose how many would you like to flip (1-3)：";
        cin >> select;

        // A code that ensures the user only enters numeric values
        if (!(cin >> select)) {
            cout << "You entered an invalid character, please enter a DIGIT between 1 and 3: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            continue;
        }  

        // A code that ensures the nummeric values entered are in between 1 and 3
        if (select > 3 || select < 1)
        {
            cout << "Can only choose 1-3, please select again!" << endl;
            continue;
        }
        
        if (select > sum_total)
        {
            cout << "Still left" << sum_total << "Pieces，" << "Cannot select more coins than the remaining coins, please select again" << endl;
            continue;
        }
        sum_total -= select;
        if (sum_total == 0)break;
        n++;
        if (n > 1)n = 0;

        // here, at the end of each turn, we ask if the player would like to quit, restart or get more info
        cout << "To continue (C), to quit (q), to restart (r) and to display the rules again (i): ";
        cin >> user_input;
        if (user_input == 'q') // user exits the program
        {
            cout << "Terminating..." << endl;
            exit(0);   
        } else if (user_input == 'r') { // user restarts the game (basically resets all coing to head`)  
            cout << "resetting all coins back to head!" << endl;
            sum_total = 10; 
            continue;
        } else if (user_input == 'i'){
            cout << "There are 2 players, A & B";
            cout << "And 10 coins all facing heads at the beginning of a round";
            cout << "the player who flips the 10th coin to tails wins the round" << endl;
            continue;
        } else {
            continue;
    }
    }
    cout << player[n] << " is winner! " << endl;
    system("pause");
}
