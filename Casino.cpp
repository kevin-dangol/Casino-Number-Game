#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void customPause(const string& message) {

    cout << message;
    cin.ignore();
    cin.get();
    
}

void easyplay(){

    int playerNum, computerNum, money = 0, randMoney, score[2] = {0, 0};

    ifstream invinFile("inv.txt");

    if (invinFile >> money) {

        invinFile.close();

    } else {

        money = 0;

    }

    ifstream scoreinFile("score.txt");

    if (scoreinFile >> score[0] >> score[1]) {

        scoreinFile.close();

    } else {

        score[0] = 0;
        score[1] = 0;

    }

    computerNum = (rand() % 100) + 1;

    cout << "Enter a number from 1-100: ";
    cin >> playerNum;

    randMoney = (rand() % 100) + 1;

    if (playerNum == computerNum) {

        cout << "You have won!\n\nYour number: " << playerNum << "\nChosen number: " << computerNum << "\n\n";

        score[0]++;
        money += randMoney;

        cout << "You have won " << randMoney << " money.\n";

    } else {

        cout << "You have lost!\n\nYour number: " << playerNum << "\nChosen number: " << computerNum << "\n\n";

        score[1]++;
        money -= randMoney;

        cout << "You have lost " << randMoney << " money.\n";
    }

    ofstream scoreFile("score.txt");

    scoreFile << score[0] << " " << score[1] << endl;

    scoreFile.close();

    ofstream invFile("inv.txt");

    invFile << money << endl;

    invFile.close();

    customPause("Going back. . . ");

}

void midplay(){

    int playerNum, computerNum, money = 0, randMoney, score[2] = {0, 0};

    ifstream invinFile("inv.txt");

    if (invinFile >> money) {

        invinFile.close();

    } else {

        money = 0;
        
    }


    ifstream scoreinFile("score.txt");

    if (scoreinFile >> score[0] >> score[1]) {

        scoreinFile.close();

    } else {

        score[0] = 0;
        score[1] = 0;

    }


    computerNum = (rand() % 500) + 1;

    cout << "Enter a number from 1-500: ";
    cin >> playerNum;

    randMoney = (rand() % 500) + 1;

    if (playerNum == computerNum) {

        cout << "You have won!\n\nYour number: " << playerNum << "\nChosen number: " << computerNum << "\n\n";

        score[0]++;
        money += randMoney;

        cout << "You have won " << randMoney << " money.\n";

    } else {

        cout << "You have lost!\n\nYour number: " << playerNum << "\nChosen number: " << computerNum << "\n\n";

        score[1]++;
        money -= randMoney;

        cout << "You have lost " << randMoney << " money.\n";
    }


    ofstream scoreFile("score.txt");

    scoreFile << score[0] << " " << score[1] << endl;

    scoreFile.close();


    ofstream invFile("inv.txt");

    invFile << money << endl;

    invFile.close();

    customPause("Going back. . . ");

}

void hardplay(){

    int playerNum, computerNum, money = 0, randMoney, score[2] = {0, 0};

    ifstream invinFile("inv.txt");

    if (invinFile >> money) {

        invinFile.close();

    } else {

        money = 0;
        
    }


    ifstream scoreinFile("score.txt");

    if (scoreinFile >> score[0] >> score[1]) {

        scoreinFile.close();

    } else {

        score[0] = 0;
        score[1] = 0;

    }

    
    computerNum = (rand() % 1000) + 1;

    cout << "Enter a number from 1-1000: ";
    cin >> playerNum;

    randMoney = (rand() % 1000) + 1;

    if (playerNum == computerNum) {

        cout << "You have won!\n\nYour number: " << playerNum << "\nChosen number: " << computerNum << "\n\n";

        score[0]++;
        money += randMoney;

        cout << "You have won " << randMoney << " money.\n";

    } else {

        cout << "You have lost!\n\nYour number: " << playerNum << "\nChosen number: " << computerNum << "\n\n";

        score[1]++;
        money -= randMoney;

        cout << "You have lost " << randMoney << " money.\n";
    }


    ofstream scoreFile("score.txt");

    scoreFile << score[0] << " " << score[1] << endl;

    scoreFile.close();


    ofstream invFile("inv.txt");

    invFile << money << endl;

    invFile.close();

    customPause("Going back. . . ");

}

void inv(){

    int money;

    ifstream file("inv.txt");

    if (file >> money){

        file.close();
        cout << "Inventory:\nMoney: " << money << endl;

    }else{

        cout << "Inventory is empty.\n";

    }

    customPause("Going back. . . ");

}

void score() {

    int score[2] = {0, 0};

    ifstream file("score.txt");

    if (file >> score[0] >> score[1]) {

        file.close();
        cout << "Win: " << score[0] << "\nLoss: " << score[1] << endl;

    } else {

        cout << "Empty scores." << endl;

    }

    customPause("Going back. . . ");
}

int main(){

    int choice, pChoice;

    ofstream invFile("inv.txt");
    ofstream scoreFile("score.txt");
    invFile.close();
    scoreFile.close();

    while(true){

        cout << "------------------------------" << endl;

        cout << "Welcome to the casino\n" << endl;
        cout << "1: Play\n2: Inventory\n3: Score\n4: Exit\n" << endl;
        cout << "Choice: ";
        cin >> choice;

        cout << "------------------------------" << endl;

        switch (choice)
        {
        case 1:
            
            cout << "Select the difficulty\n" << endl; 
            cout << "1: Easy\n2: Medium\n3: Hard\n4: Back\n" << endl;
            cout << "Choice: ";
            cin >> pChoice;

            cout << "------------------------------" << endl;

            switch (pChoice)
            {
            case 1:
                easyplay();
                break;
            
            case 2:
                midplay();
                break;

            case 3:
                hardplay();
                break;
            
            case 4:
            
                customPause("Going back. . . ");
                break;
                
            default:

                cout << "Invalid" << endl;
                system("pause");
                break;
            }
            break;

        case 2:
            
            customPause("Opening inventory. . .");
            cout << "------------------------------" << endl;
            inv();
            break;

        case 3:
            
            customPause("Calculating Score. . .");
            cout << "------------------------------" << endl;
            score();
            break;

        case 4:

            cout << "Exiting . . ." << endl;
            system("pause");
            return 0;

        default:
            cout << "Invalid!";
            system("pause");
            break;
        }

    }

}