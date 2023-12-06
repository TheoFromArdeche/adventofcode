#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <regex>

using namespace std;

int main() {
    ifstream input_file("./day6_inputs.txt");
    

    int answer=1;
    string line;
    vector<pair<long long,long long>> races(0);
    while(getline(input_file, line)) {
        int i=0;
        while (line[i]>'9'||line[i]<'0') i++;
        int index=0;
        string temp="";
        while (i<line.size()) {
            if (line[i]<='9'&&line[i]>='0') temp.push_back(line[i]);
            i++;
        }
        if (index>(int)(races.size())-1) races.push_back(make_pair(stoll(temp), 0));
        else races[index].second=stoll(temp);
    }
    
    for (auto race:races) {
        int count=0;
        //cout << race.first << " " << race.second << "\n";
        for (int i=1; i<race.first; i++) {
            if ((race.first-i)*i>race.second) count++;
        }
        answer*=count;
    }
    

    cout << "answer : " << answer << "\n";

    input_file.close();

    return 0;

}