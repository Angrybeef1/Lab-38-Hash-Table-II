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

void search_key(const map<int, list<string>>& hash_table) {
    int key;
    cout << "Enter hash index to search: ";
    cin >> key;

    auto it = hash_table.find(key);
    if(it != hash_table.end()){
        cout << "Found Values for hash index " << key << ": ";
        for (const string& code : it -> second) {
            cout << code << " ";
        }
        cout << endl;
    } else {
        cout << "hash index does not exist" << endl;
    }

}

void add_key(map<int, list <string>>& hash_table) {
    string code;
    cout << "Enter 12-character code to add: ";
    cin >> code;

    if(code.length() != 12) {
        cout << "Error: code is not 12 characters long." << endl;
    }

    int hash_index = gen_hash_index(code);
    hash_table[hash_index].push_back(code);
    cout << "Added code with hash index: " << hash_index << endl;
}

void remove_key(map<int, list <string>>& hash_table) {
    int key;
    cout << "Enter hash index to remove: ";
    cin >> key;

    auto it = hash_table.find(key);
    if (it != hash_table.end()) {
        hash_table.erase(it);
        cout << "Remove hash index " << key << endl;
    } else {
        cout << "Hash index not found." << endl;
    }

}

void moidify_key(map<int, list<string>>& hash_table) {
    int key;
    cout << "Enter hash index to modify: ";

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
            case 2:
                search_key(hash_table);
                break;
            case 3:
                add_key(hash_table);
                break;
            case 4:
                remove_key(hash_table);
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
