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

void importDataFromFile(string &filename, vector<string> &names, vector<int> &scores, vector<char> &grades){
    ifstream source;
    source.open("name_score.txt");
    string textline;
    int s1,s2,s3;
    char n[100];
     while (getline(source, textline)) {
        sscanf(textline.c_str(), "%[^:]:%d %d %d", n, &s1, &s2, &s3);  
        string n2 = n;
        names.push_back(n2);  
        int totalScore = s1 + s2 + s3; 
        scores.push_back(totalScore);  
        grades.push_back(score2grade(totalScore));
    }
    source.close();
}

void getCommand(string &command, string &key){
    cout << "Please input your command:" << endl;
    cin >> command;
    cin >> key;
}

void searchName(vector<string> &name2, vector<int> &scores, vector<char> &grades, string &key){
    for(int i = 0; i < name2.size();i++){
        if(key.compare(name2[i])){
            cout << name2[i] << "'s score = " << scores[i] << endl;
            cout << name2[i] << "'s grade = " << grades[i] << endl;
        }
    }
}

void searchGrade(){

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
