#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string filename, vector<string> &names1, vector<int> &scores, vector<char> &grades){
    ifstream source;
    source.open(filename);
    string textline;
    int s1,s2,s3;
    char n[100];
     while (getline(source, textline)) {
        sscanf(textline.c_str(), "%[^:]:%d %d %d", n, &s1, &s2, &s3);  
        string n2 = n;
        names1.push_back(n2);  
        int totalScore = s1 + s2 + s3; 
        scores.push_back(totalScore);  
        grades.push_back(score2grade(totalScore));
    }
    source.close();
}

void getCommand(string &command, string &key){
    cout << "Please input your command:\n";
    string line;
    getline(cin, line);  

    size_t pos = line.find(' '); 
    if (pos != string::npos) { 
        command = line.substr(0, pos);   
        key = line.substr(pos + 1);      
    } else {
        command = line;
        key = "";
    }

    command = toUpperStr(command);
    key = toUpperStr(key);
}


void searchName(vector<string> &name2, vector<int> &scores, vector<char> &grades, const string &key){
    bool found = false;
    for (size_t i = 0; i < name2.size(); i++) {
        if (toUpperStr(name2[i]) == key) {
            cout << "---------------------------------\n";
            cout << name2[i] << "'s score = " << scores[i] << "\n";
            cout << name2[i] << "'s grade = " << grades[i] << "\n";
            cout << "---------------------------------\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "---------------------------------\n";
        cout << "Cannot found.\n";
        cout << "---------------------------------\n";
    }
}

void searchGrade(vector<string> &name3, vector<int> &scores, vector<char> &grades, const string &key){
    bool found = false;
    cout << "---------------------------------\n";
    for (size_t i = 0; i < name3.size(); i++) {
        if (grades[i] == key[0]) {
            cout << name3[i] << " (" << scores[i] << ")\n";
            found = true;
        }
    }
    if (!found) {
        cout << "Cannot found.\n";
    }
    cout << "---------------------------------\n";
}



int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    for(unsigned int i = 0; i < names.size(); i++){
     cout << names[i] << "," << scores[i] << "," << grades[i] << "\n";
}
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
       else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}
