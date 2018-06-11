//
//  main.cpp
//  宿題２ 2.0
//
//  Created by Hao Feng on 2018/05/17.
//  Copyright © 2018年 Hao Feng. All rights reserved.
//

#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
const int N=400000;
bool vis[N];
class node
{   public:
    string str;
    vector<int>res;
    void getindex(string str);
    int index;
};
vector<int>res;
void node::getindex(string str){
    for(int i=0;i<9;i++){
        if(str[i]=='0'){
            index =i;
        }
        }
}
int  kanto[] = {1,1,2,6,24,120,720,5040,40320,362880};
int KanTo(string str)
{
    int i, j, t, sum;
    int s[10];
    for(i=0;i<9;i++)
    {
        s[i]=str[i]-'0';
//        s[i]=atoi(str[i].c_str());
    }
    sum = 0;
    for (i=0; i<9; i++)
    {
        t = 0;
        for (j=i+1; j<9; j++)
            if (s[j] < s[i])
                t++;
        sum += t*kanto[9-i-1];
    }
    return sum+1;
}
node start;
bool bfs(){
        char c;
        queue<node> q;
        node g,h;
        g.str =start.str;
        g.getindex(g.str);
        q.push(g);
    while (!q.empty()) {
        g=q.front();q.pop();
    if (KanTo(g.str) ==46234){
        res=g.res;
        return true;
        }
        h=g;
        h.getindex(h.str);
        if((h.index+1)%3!=0)
        {   h.res.push_back(h.str[h.index+1]-'0');
            c=h.str[h.index];h.str[h.index]=h.str[h.index+1];h.str[h.index+1]=c;
            h.index++;
            int t =KanTo(h.str);
            if(!vis[t])
            {
                vis[t]=true;
                q.push(h);
            }
        }
        h=g;
        h.getindex(h.str);
        if(h.index%3!=0)
        {   h.res.push_back(h.str[h.index-1]-'0');
            c=h.str[h.index];h.str[h.index]=h.str[h.index-1];h.str[h.index-1]=c;
            h.index--;
            int t =KanTo(h.str);
            if(!vis[t])
            {
                vis[t]=true;
                q.push(h);
            }
        }
        h=g;
        h.getindex(h.str);
        if(h.index<6)
        {
            h.res.push_back(h.str[h.index+3]-'0');
            c=h.str[h.index];h.str[h.index]=h.str[h.index+3];h.str[h.index+3]=c;
            h.index+=3;
            int t =KanTo(h.str);
            if(!vis[t])
            {
                vis[t]=true;
                q.push(h);
            }
        }
        h=g;
        g.getindex(g.str);
        if(h.index>2)
        {   h.res.push_back(h.str[h.index-3]-'0');
            c=h.str[h.index];h.str[h.index]=h.str[h.index-3];h.str[h.index-3]=c;
            h.index-=3;
            int t =KanTo(h.str);
            if(!vis[t])
            {
                vis[t]=true;
                q.push(h);
            }
        }
    }
    return false;
    
};


int main(int argc, const char * argv[]) {
    cout << "数字を入力してください(string)"<<endl;
    string s;
    cin >> s;
    start.str =s;
    start.res.clear();
    if(bfs()){
        cout << "手数は" << res.size()<<endl;   //手数を出力します
        int i;
        for(i=0;i<res.size();i++)//移動の順序を出力
//            res[i]= res[i]- '0';
            cout << res[i] << " ";}
    else cout << "解決不能" <<endl;
    return 0;
}
