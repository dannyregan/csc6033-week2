#include <iostream>
#include <random>

using namespace std;

int user_input() {
    int user_choice;

    while (true) {
        cout << "=================" << endl;
        cout << "Select an option:" << endl;
        cout << "1. Rock" << endl;
        cout << "2. Paper" << endl;
        cout << "3. Scissors" << endl;
        cout << "4. End Program" << endl;
        cout << "=================" << endl;

        cin >> user_choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number between 1 and 4." << endl;
            continue;
        }

        if (user_choice >= 1 && user_choice <= 4) {
            return user_choice;
        } else {
            cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
        }
    }
}

int computer_input() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 3);

    int randomNumber = dist(gen);
    return randomNumber;
}

int determine_winner(int &user_choice, int &computer_choice) {
    switch (user_choice) {
        case (1):
            switch (computer_choice) {
                case (1):
                    return 0;
                case (2):
                    return 1;
                case (3):
                    return 2;
            }
        case (2):
            switch (computer_choice) {
                case (1):
                    return 2;
                case (2):
                    return 0;
                case (3):
                    return 1;
            }
        case (3):
            switch (computer_choice) {
                case (1):
                    return 1;
                case (2):
                    return 2;
                case (3):
                    return 0;
            }
    }
    return 0;
}

string game_action(int &user_choice, int &computer_choice) {
    switch (user_choice) {
        case (1):
            switch (computer_choice) {
                case (1):
                    return "You both played ROCK.";
                case (2):
                    return "You played ROCK and the computer played PAPER";
                case (3):
                    return "You played ROCK and the computer played SCISSORS";
            }
        case (2):
            switch (computer_choice) {
                case (1):
                    return "You played PAPER and the computer played ROCK";
                case (2):
                    return "You both played PAPER.";
                case (3):
                    return "You played PAPER and the computer played SCISSORS";
            }
        case (3):
            switch (computer_choice) {
                case (1):
                    return "You played SCISSORS and the computer played ROCK";
                case (2):
                    return "You played SCISSORS and the computer played PAPER";
                case (3):
                    return "You both played SCISSORS.";
            }
    }
    return 0;
}

string announce_winner(int &winner) {
    switch (winner) {
        case (0):
            return "Nobody won.";
        case (1):
            return "The computer won ):";
        case (2):
            return "You won!";
    }
    return 0;
}

int main() {
    while (true) {
        int computer_choice = computer_input();
        int user_choice = user_input();

        if (user_choice == 4) {
            break;
        }

        int winner = determine_winner(user_choice, computer_choice);
        string action_announcement = game_action(user_choice, computer_choice);
        cout << action_announcement << endl;

        string winner_announcement = announce_winner(winner);
        cout << winner_announcement << endl;
    }
    return 0;
}