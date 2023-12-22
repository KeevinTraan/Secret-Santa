#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

// function to shuffle the elements in a vector
void fisherYatesShuffle(vector<string>& n) {
    srand(static_cast<unsigned int>(time(nullptr)));
    for (size_t i = n.size() - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(n[i], n[j]);
    }
}

// bool used to check if all of the elements in vectors are not in the same position
bool checkVectors(vector<string> n, vector<string> n2){
    
    // counter to keep track of number of different elements in both vectors
    int counter = 1;
    // loop through both vectors and add the counter if an element is not in the same position as the other vector
    for(size_t i = 0; i < n.size(); i++){
        if(n[i] != n2[i]){
            counter++;
        }
    }
    
    // if the counter is the same as the vector size, that means all the elements are in different positions
    if(counter == n.size()){
        return false;
    } else{
        return true;
    }
}

int main(){
    for(;;){
        vector<string> nameList;
        
        // heading
        cout << "This is used to match you with someone else! (type \"=\" if you are done)" << endl << "-------------------------------------------" << endl;
        
        int counter = 1;
        while(true){
            string personName;
            cout << "Name " << counter << ": ";
            getline(cin, personName);
            
            // uppercase the first letter of the person's name
            personName[0] = toupper(personName[0]);
            
            // stop the loop if the user inputs =
            if(personName == "="){
                break;
            }
            
            // error message if there is less than 3 people
            if(counter < 4 && personName == "="){
                cout << "You need more people!" << endl;
                continue;
            }
            
            // error message if the name is blank
            if(personName == ""){
                cout << "Please enter a name..." << endl;
                continue;
            }
            
            // add names to the vector
            nameList.push_back(personName);
            
            // increment the counter
            counter++;
        }
        
        // shuffle the name
        fisherYatesShuffle(nameList);
        
        // counter to keep track of the amount of pairs
        int counter2 = 1;
        
        // title for the pairs
        cout << endl << "Pairs" << endl << "-----------------" << endl;
        
        // output all of the pairs in the shuffled vector of names
        for(int p = 0; p < nameList.size() - 1; p++){
            cout << "Pair " << counter2 << ": " << nameList[p] << " -> " << nameList[p + 1] << endl;
            counter2++;
        }
        
        // output the last pair, which is the last person giving the gift to the first person in the vector
        cout << "Pair " << counter2 << ": " << nameList[nameList.size() - 1] << " -> " << nameList.front() << endl;
        
        // bool used to determine if the user wants to reshuffle the names
        bool doIt = false;
        
        while(true){
            string reshuffle;
            cout << endl << "Shuffle with same names? (y/n): ";
            getline(cin, reshuffle);
            
            // uppercase the letter so user can type lowercase and uppercase
            reshuffle[0] = toupper(reshuffle[0]);
            
            // error message for an invalid input
            if(reshuffle != "Y" && reshuffle != "N"){
                cout << "Please choose a valid option..." << endl;
            }
            
            // if the user wants to reshuffle, then the program will go to the next code
            if(reshuffle == "Y"){
                doIt = true;
            } else{
                break;
            }
            
            // create a new vector that copies all the elements of the original string
            vector<string> nameList2 = nameList;
            
            // shuffle the new vector until the vector has diifferent elements in different positions of the vector
            while(checkVectors(nameList2, nameList)){
                fisherYatesShuffle(nameList2);
            }
            
            // counter used to keep track of the amount of shuffled pairs
            int counter3 = 1;
            
            // output all of the shuffled pairs
            cout << endl << "Pairs" << endl << "-----------------" << endl;
            for(int p = 0; p < nameList2.size() - 1; p++){
                cout << "Pair " << counter3 << ": " << nameList2[p] << " -> " << nameList2[p + 1] << endl;
                counter3++;
            }
            
            // output the last person's pair (the first person in the vector)
            cout << "Pair " << counter3 << ": " << nameList2[nameList.size() - 1] << " -> " << nameList2.front() << endl;
        }
        
        // ask if the user wants to restart the program from the beginning or not
        string redo;
        cout << "Do you want to use different names? (y/n): ";
        getline(cin, redo);
        
        // uppercase the letter so that user can type in lowercase and uppercase
        redo[0] = toupper(redo[0]);
        
        // error message for an invalid input
        if(redo != "N" && redo != "Y"){
            cout << "Please choose a valid option..." << endl;
        }
        
        // restart the program from the beginning
        if(redo == "Y"){
            cout << endl;
            continue;
        }
        // end the program
        else{
            break;
        }

    }
    return 0;
}
