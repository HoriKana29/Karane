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

void importDataFromFile(string filename,vector<string> &names,vector<int> &scores,vector<char> &grades){
    
    ifstream file(filename);
    string line;
    
    while (getline(file,line)) {
        char n[100];
        int a,b,c;
        sscanf(line.c_str(), "%[^:]: %d %d %d", n, &a, &b, &c);
        
        names.push_back(n);
        int total = a+b+c;
        scores.push_back(total);
        grades.push_back(score2grade(total));
    }

}

void getCommand(string &command,string &key){
    char c[100],k[100];
    cout << "Please input your command:\n";
    string quest;
    getline(cin,quest);
    sscanf (quest.c_str(),"%s %[^:]",c,k);
    command = c;
    key = k;
}



void searchName(vector<string> names,vector<int> scores,vector<char> grades,string key){
    bool t = false;
    cout << "---------------------------------\n";
    for(unsigned int i = 0;i<names.size();i+=1){
        if(toUpperStr(names[i])==key){
            cout << names[i] << "'s score = " << scores[i] << "\n";
            cout << names[i] << "'s grade = " << grades[i] << "\n";
            t = true;
        }
    }
    if(t==false) cout << "Cannot found.\n";
    cout << "---------------------------------\n";
}

void searchGrade(vector<string> &names,vector<int> scores,vector<char> &grades,string key){
    cout << "---------------------------------\n";
    bool t = false;
    for(unsigned int i = 0;i<names.size();i+=1){
        if(grades[i]==key[0]) {
            cout << names[i] << " (" << scores[i] << ")\n";
            t = true;
        }
    }
    if(t==false) cout << "Cannot found.\n";
    cout << "---------------------------------\n";
}


int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
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