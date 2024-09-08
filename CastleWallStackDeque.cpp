// CastleWallStackDeque.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<deque>
#include<stack>
#include<string>
#include <iostream>

using namespace std;

void pushToStack(string& userInput, stack<string>& castleWallList) {
    if (userInput == "t") {
        castleWallList.push("tower");
    }
    else if (userInput == "w") {
        castleWallList.push("wall");
    }
    else if (userInput == "rw") {
        castleWallList.push("ruined wall");
    }
    else if (userInput == "tt") {
        castleWallList.push("tall tower");
    }
    else if (userInput == "g") {
        castleWallList.push("gate");
    }
    else if (userInput == "m") {
        castleWallList.push("moat bridge");
    }
    else if (userInput == "st") {
        castleWallList.push("short tower");
    }
}


void pushToDeque(string& userInput, deque<string>& castleWallDeque) {
    if (userInput == "t") {
        castleWallDeque.push_front("tower");
    }
    else if (userInput == "w") {
        castleWallDeque.push_front("wall");
    }
    else if (userInput == "rw") {
        castleWallDeque.push_front("ruined wall");
    }
    else if(userInput == "tt"){

        castleWallDeque.push_front("tall tower");
    }
    else if (userInput == "g") {
        castleWallDeque.push_front("gate");
    }
    else if (userInput == "m") {
        castleWallDeque.push_front("moat bridge");
    }
    else if (userInput == "st") {
        castleWallDeque.push_front("short tower");
    }
}

/*Pass by reference to make this work.*/
void checkUserInput(stack<string>& castleWallStack, string& userInput) {

    cout << "CASTLE WALL STACK: " << endl;
    int countValid = 0;

   //check if the userinput is valid.
	userInput = "";
    bool keepChecking = true;

	while (keepChecking) {
		cout << "Please add a turret (t), wall (w), ruined wall (rw), tall tower (tt), short tower (st), gate (g), moat bridge (m): ";
		cin >> userInput;
        /*trim any blank spaces off of the user's input*/
        userInput.erase(remove_if(userInput.begin(), userInput.end(), isspace), userInput.end());
        /*Now the user input will be checked, regardless of the spaces.*/
		if (userInput != "t" && userInput != "w" && userInput != "rw" && userInput != "tt" && userInput != "st"
			&& userInput != "g" && userInput != "m" && userInput != "d") {
			cout << "You did not enter something valid.  " << endl;
            keepChecking = true;
			continue;
        }
        else {
            /*This statement is only reached if the other statement isn't true.*/
                if (!(userInput == "d")) {
                    cout << "Your input was valid!" << endl;
                    cout << endl;
                    pushToStack(userInput, castleWallStack);
                    keepChecking = true;
                    countValid++;
                 }
                else if (userInput == "d" && countValid >= 2) {
                    cout << "All done!" << endl;
                    keepChecking = false;
                }
                else if (userInput == "d" && countValid < 2) {
                    cout << "You must have at least two items." << endl;
                    keepChecking = true;
                }
        }
		
	}
}

void checkDequeUserInput(deque<string>& castleWallDeque, string& userInput) {
    cout << endl;
    cout << "CASTLE WALL DEQUE: " << endl;
    int countValid = 0;

    //check if the userinput is valid.
    userInput = "";
    bool keepChecking = true;

    while (keepChecking) {
        cout << "Please add a turret (t), wall (w), ruined wall (rw), tall tower (tt), short tower (st), gate (g), moat bridge (m): ";
        cin >> userInput;
        /*trim any blank spaces off of the user's input*/
        userInput.erase(remove_if(userInput.begin(), userInput.end(), isspace), userInput.end());
        /*Now the user input will be checked, regardless of the spaces.*/
        if (userInput != "t" && userInput != "w" && userInput != "rw" && userInput != "tt" && userInput != "st"
            && userInput != "g" && userInput != "m" && userInput != "d") {
            cout << "You did not enter something valid.  " << endl;
            keepChecking = true;
            continue;
        }
        else {
            /*This statement is only reached if the other statement isn't true.*/
            if (!(userInput == "d")) {
                cout << "Your input was valid!" << endl;
                cout << endl;
                pushToDeque(userInput, castleWallDeque);
                keepChecking = true;
                countValid++;
            }
            else if (userInput == "d" && countValid >= 2) {
                cout << "All done!" << endl;
                keepChecking = false;
            }
            else if (userInput == "d" && countValid < 2) {
                cout << "You must have at least two items." << endl;
                keepChecking = true;
            }
        }

    }
}

void popCastleWallStack(stack<string>& castleWallStack) {
    cout << endl;
    cout << endl;
    cout << "Going to view each element of the castle stack, and then delete it.  Stacks start from the top." << endl;;
    cout << "At the start, there are " << int(castleWallStack.size()) << " items in the stack!" << endl;
    string savePrint = "";
    while(!(castleWallStack.empty())){
        cout << "The next item in the stack is: " << castleWallStack.top() << " - " << endl;
        castleWallStack.pop();
        if (!(int(castleWallStack.size()) == 1)) {
            cout << "There are now " << int(castleWallStack.size()) << " items!" << endl;
        }
        else {
            cout << "There is now " << int(castleWallStack.size()) << " item!" << endl;
        }
        
        if (int(castleWallStack.size()) == 0) {
            cout << "The wall has been demolished!" << endl;
        }
    }
}

void printCastleWallDeque(deque<string>& castleWallDeque) {
    cout << endl;
    cout << endl;
    cout << "Going to view each element of the castle deque, and then delete it.  Deque deletes all at once, and not element by element." << endl;
    for (int i = 0; i < int(castleWallDeque.size()); i++) {
        cout << "The next part of the wall is " << castleWallDeque[i] << " - " << endl;
    }
    castleWallDeque.clear();
    cout << "The entire deque has now  been deleted with clear().  The size is " << int(castleWallDeque.size()) << ". " << endl;  
    cout << "The castle wall has been demolished!" << endl;

}



int main()
{
   /*Main is not doing a lot of work here.*/
   cout << "Welcome to the castle wall stack and deque program!\n";
   cout << endl;
   cout << endl;

   //Define variables
   stack<string> castleWallStack;
   string userInput;
   checkUserInput(castleWallStack, userInput);

   deque<string> castleWallDeque;
   checkDequeUserInput(castleWallDeque, userInput);

   popCastleWallStack(castleWallStack);
   printCastleWallDeque(castleWallDeque);
}


