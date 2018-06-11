//
//  main.cpp
//  leetcode1
//
//  Created by Hao Feng on 2018/06/01.
//  Copyright © 2018年 Hao Feng. All rights reserved.
//
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int result;
        if (s.size()==0){
            result=0;
            return result;}
        else { for(int i=0;i<s.size();i++)
            if (roma(s[i])>=roma(s[i+1])){
                result += roma(s[i]);}
            else {
                result -=roma(s[i]);
            }
        }
        return result;};
    int roma(char ch){
        int romaint;
        romaint =0;
        switch (ch) {
            case 'I':
                romaint =1;
                break;
            case 'V':
                romaint =5;
                break;
            case 'X':
                romaint =10;
                break;
            case 'L':
                romaint =50;
                break;
            case 'C':
                romaint =100;
                break;
            case 'D':
                romaint =500;
                break;
            case 'M':
                romaint =1000;
                break;
        }
        return romaint;
    };
};

int main(){
    Solution sol;
    cout <<"ローマ数字を入力してください"<<"(III=3,IV=4,XI=10)"<<endl;
    cout << "I=1" <<endl;
    cout << "V=5"<<endl;
    cout <<"X=10"<<endl;
    cout <<"L=50"<<endl;
    cout << "C=100" <<endl;
    cout << "D=500" <<endl;
    cout << "M=1000" <<endl;
    string xx;
    cin >> xx;
    string s= xx;
    cout << sol.romanToInt(s) << endl;
}

