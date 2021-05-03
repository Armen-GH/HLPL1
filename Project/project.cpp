#include <iostream>
#include <vector>
using namespace std;

bool check(char array[], int n);

int main()
{
    char coins[10] = {'H','H','H','H','H','H','H','H','H','H'};
    char player[2] = {'A', 'B'};
    char inf;
    int i, flipNum, a, n=0;
    cout << "There are 10 coins, Two players (A & B) will alternate turns, deciding how many coins they wish to be flipped." << endl;
    cout << "keeping in mind that the right-most coin picked must be facing head 'H'." << endl;
    cout << "The player whom on her/his turn, all coins are facing tail 'T' wins!" << endl;
    for(i=0;i<10;i++)
    {
        cout << coins[i] << " ";
    }
    cout << "\n";
    while(!check(coins, 10))
        {
        vector<int> in;
        cout << "\n" << "Player " << player[n] << " Choose How Many Coins Would You like to flip (1,2,3): ";
        cin >> flipNum;
        cout << "\n";
        if((flipNum < 1) || (flipNum > 3))
        {
            cout << "Sorry, try again ,only DIGITS between 1 and 3 are accepted!" << endl;
            cin >> flipNum;
            cout << "\n";
        }
        cout << "Enter the coins` numbers (space-separated) you would like to flip: " << endl;
        for(i=0;i<flipNum;i++)
        {
            cin >> a;
            a-=1;
            in.push_back(a);
        }
        sort(in.begin(),in.end());
        while(coins[in.back()]=='T')
        {
            in.clear();
            cout << "\n" << "Remember! Last coin must be facing Head 'H'! PLease Try Again! " << endl;
            cout << "Enter the coins` numbers you would like to flip: ";
            for(i=0;i<flipNum;i++)
            {
                cin >> a;
                a-=1;
                in.push_back(a);
            }
            sort(in.begin(),in.end());
        }
        for(i=0;i<flipNum;i++)
        {
            //coins[in[i]]='T';
            if(coins[in[i]]=='T')
            {
                coins[in[i]]='H';
            } else {
                coins[in[i]]='T';
            }
        }
        cout << "\n" << "Here are the coins at the end of this round: " << endl;
        for(i=0;i<10;i++)
        {
            cout << coins[i] << " ";
        }
        cout << "\n";
        cout << "\n" << "to continue (C), to quit (Q), to restart(R) and to display to rules again (I): ";
        cin >> inf;
        if (inf == 'q')
        {
            cout << "it seems your busy, come back later!";
            exit(0);
        } else if(inf == 'r')
        {
            cout << "\n" << "Here we go again!" << endl;
            fill_n(coins, 10, 'H');
            for(i=0;i<10;i++)
            {
                cout << coins[i] << " ";
            }
            cout << "\n";
            n = 0;
        } else if(inf == 'i')
        {
            cout << "\n" << "All right. We have 10 coins all facing head head (H) initially." << endl;
            cout << "Two players 'A' and 'B' will alternate turns, each deciding how many coins and which coins to flip!" << endl;
            cout << "However, the rightmost coin picked at each turn MUST be facing head 'H'." << endl;
            cout << "The first player who successfully flips all coins to tail 'T' wins." << endl;
            n++;
            if(n>1)
            {
                n=0;
            };
        } else {
            n++;
            if(n>1)
            {
                n=0;
            };
        }
        
        }
    n++;
    if(n>1)
    {
        n=0;
    };
    cout << "Congrats Player " << player[n] << ", You nailed it!";
}
bool check(char array[], int n)
{   
    for(int i = 0; i < n - 1; i++)      
    {         
        if((array[i]!='T') || (array[i] != array[i + 1]))
            return false;
    }
    return true;
}
