#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
using namespace std;
vector<string> masterinventoryList;     //Master list of inventory items
vector<string> inventoryList;           //Inventory loaded from a save file
vector<int> inventoryAmountList;        //Amount of each item in the inventory

vector<string> splitString(string str, char splitter){
    vector<string> result;
    string current = ""; 
    for(int i = 0; i < str.size(); i++){
        if(str[i] == splitter){
            if(current != ""){
                result.push_back(current);
                current = "";
            } 
            continue;
        }
        current += str[i];
    }
    if(current.size() != 0)
        result.push_back(current);
    return result;
}
void loadMasterInventory() {
    ifstream file("masterInventory.txt");
    string line;
    //With open file, put each line of file into vector
    if (file.is_open()){
        while (getline(file, line)) {
            if (line != ""){
                masterinventoryList.push_back(line);
            }
        }
        file.close();
    } else {
        cout << "File : masterInventory.txt : did not open" ;
    }
}
void printMasterList() {
    int i = 0;
    for (string line : masterinventoryList){
        line.erase(remove(line.begin(), line.end(), '0'), line.end());
        line.erase(remove(line.begin(), line.end(), ','), line.end());
        cout << "index: " << i << ", Item: " << line << "\n";
        i++;
    }
}
void editMasterInventory() {
    cout << "Input item: \n";
    string item;
    cin >> item;
    item += ",0";
    masterinventoryList.push_back(item);
    ofstream file("masterInventory.txt", ios::app);
    if (file.is_open()) {
        file << item << endl;
        file.close();
    }

}
void printCurrentInventory() {
    cout << "Current Inventory: \n";

    if (inventoryList.size() != inventoryAmountList.size()) {
        throw invalid_argument("Error, Vectors must have the same size");
    }
    for (size_t i = 0; i < inventoryList.size(); ++i) {
        string value1 = inventoryList[i];
        int value2 = inventoryAmountList[i];
        cout << "index: " << i << ", Item: " << value1 << ", Amount: " << value2 << std::endl;
    }
}
void openSaveFile(string fileName) {
    //open file
    ifstream file(fileName.c_str());
    string line;
    //With open file, put each line of file into vector
    if (file.is_open()){
        while (getline(file, line)) {
            //cout << line;
            vector<string> result = splitString(line, ',');
            // cout << result[0];
            // cout << result[1];
            inventoryList.push_back(result[0]);
            inventoryAmountList.push_back(stoi(result[1]));
        }
        file.close();
    } else {
        cout << "File : " << fileName << " : did not open" ;
    }    
}
void createSave(string fileName) {
    // Create and open a text file
    ofstream file(fileName.c_str());
    if (file.is_open()) {
        for (string line : masterinventoryList){
            file << line << "\n";                                               //PROBLEM
        }
    }else {
        cout << "File : " << fileName << " : did not open" << endl;
    }  
    file.close();
}
void saveToFile(string fileName) {
    //open file
    ofstream file(fileName.c_str(), std::ios::trunc);
    if (file.is_open()) {
        if (inventoryList.size() != inventoryAmountList.size()) {
            throw invalid_argument("Error, Vectors must have the same size");
        }
        for (size_t i = 0; i < inventoryList.size(); ++i) {
            string value1 = inventoryList[i];
            int value2 = inventoryAmountList[i];
            file << value1 << ',' << value2 << '\n';
        }
        file.close();
    }else {
        cout << "File : " << fileName << " : did not open" ;
    }  
}
void addOrRemoveItems() {
    //printMasterList();
    cout << "please input the index number of the item you wish to add or remove from: \n";
    int indexNum;
    cin >> indexNum;
    cout << "please input the number of items you wish to add or remove from: \n";
    int amountNum;
    cin >> amountNum;
    cout << "adding or removing items 1/2: \n";
    int aR;
    cin >> aR;
    if (aR == 1){
        inventoryAmountList[indexNum] += amountNum;
    } else {
        inventoryAmountList[indexNum] -= amountNum;
    }
    cout << "index: " << indexNum << ", Item: " << inventoryList[indexNum] << ", Amount: " << inventoryAmountList[indexNum] << std::endl;
}

int main()
{
    std::cout << "Inventory System Running" << std::endl; 
    loadMasterInventory();
    //printMasterList();
    int x;
    bool mainLoop = true;
    bool subLoop = true;
    string fileName;
    //Main loop for the initial actions: create, load, or edit inventory
    while (mainLoop == true) {
        cout << "Input 1 to create a new save\n"; 
        cout << "Input 2 to load a save: \n";
        cout << "Input 3 to add new item to master inventory: \n";
        cin >> x; //Note, this is what gets user input
        //Clear the input buffer to handle leftover newline character
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (x == 1) {
            cout << "Please input save file name: \n";
            cin >> fileName;
            fileName += ".txt";
            createSave(fileName);
            openSaveFile(fileName);
            break;
        } else if (x == 3) {
            editMasterInventory();
        } else {
            cout << "Please input save file name: \n";
            cin >> fileName;
            //fileName = "inventory2";
            fileName += ".txt";
            openSaveFile(fileName);
            break;
        }
    }
    printCurrentInventory();
    //cout << "\n";
    //printMasterList();
    //Sub loop for adding/removing items and saving the final inventory
    while (subLoop == true){
        cout << "Would you like to add or remove items from the current list? y/n\n";
        string input;
        cin >> input;
        //Clear the input buffer to handle leftover newline character
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (input == "y" || input == "1"){
            addOrRemoveItems();
        } else {
            cout << "Good bye!\n";
            break;
        }
    }
    //Ask if the user wants to save the modified inventory
    cout << "Would you like to save this inventory? y/n\n";
        string input;
        cin >> input;
        if (input == "y" || input == "1"){
            saveToFile(fileName);
            cout << "File saved, Good bye!\n";
        } else {
            cout << "Good bye!\n";
        }
}