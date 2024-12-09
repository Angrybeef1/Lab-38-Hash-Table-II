// COMSC 210 | Lab 37 Hash Tables I | Robert Stonemetz

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <list>
#include <limits>

using namespace std;

//part 3 change part 1 hash to a gen_hash
int gen_hash_index(string str){
    int sum = 0;
    for(char c : str){
        sum += (int)c;
    }
    return sum;
}

void print_first_100 (const map<int, list<string>>& hash_table) {
    int count = 0;
    for (const auto& entry : hash_table){
        cout << "Hash index " << entry.first << ": ";
        for(const string& code : entry.second){
            cout << code<< " ";
        }
        cout << endl;

        count++;
        if (count >= 100) 
        break;
    }
}

void search_key() {

}

void add_key(){

}

void remove_key() {

}

void moidify_key() {

}


int main() {
    
    
    //part 3 create hash table as map
    map<int, list<string>> hash_table;

    //part 2 import data.txt part 3 changes to run the table
    ifstream file("data.txt");
    string line;
    
    while (getline(file,line)) {
        if (!line.empty()) {
            int hash_index = gen_hash_index(line);
            hash_table[hash_index].push_back(line);
        }
    }
    
    //cout << "\nGrand total of ASCII values: " << total << endl;
    cout << "\nFirst 100 hash table entries:" << endl;
    
    
    file.close();

    //menu

    int choice;
    do {
        cout << "\nHash Table Menu:" << endl;
        cout << "1. Print first 100 entries" << endl;
        cout << "2. Search for a key" << endl;
        cout << "3. Add a key" << endl;
        cout << "4. Remove a key" << endl;
        cout << "5. Modify a key" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice (1-6): ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits < streamsize > :: max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }
        switch(choice){
            case 1:
                print_first_100(hash_table);
                break;
        }
    } while (choice != 6);
    return 0;

    
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
