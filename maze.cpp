#include<bits/stdc++.h>
using namespace std;  
//vector<string>v ;                
void show_board(char board [7][20]){
    for(int i=0;i<7;i++){
    for(int j=0;j<20;j++){
        cout<<board[i][j];
    }
    cout<<endl;
    }
} 
bool dfs(char board[7][20],int i,int j,vector<string>&v,string a)
{
    bool done=false;
    if(board[i][j]=='O')
    {
            v.push_back(a);
            done=true; 
                     
    }
    if(i>=0&&i<7&&j>=0&&j<20&&board[i][j]!='%'&&board[i][j]!='*'){
            board[i][j]='*';
            if(!done) done=dfs(board,i,j+1,v,a+" Right ");
            if(!done) done=dfs(board,i-1,j,v,a+" UP ");
            if(!done) done=dfs(board,i+1,j,v,a+" Down ");
            if(!done) done=dfs(board,i,j-1,v,a+" Left ");
                
    }
    return done;
        
 }
int main(){
    char board[7][20]={'%','%','%','%','%','%','%','%','%','%','%','%','%','%','%','%','%','%','%','%',
                    '%','-','-','-','-','-','-','-','-','-','-','-','-','-','-','%','-','-','-','%',
                    '%','-','%','%','-','%','%','-','%','%','-','%','%','-','%','%','-','%','-','%',
                    '%','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','%','-','%',
                    '%','%','%','%','%','%','%','%','%','%','%','%','%','%','%','%','%','%','-','%',
                    '%','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','%',
                    '%','%','%','%','%','%','%','%','%','%','%','%','%','%','%','%','%','%','%','%'
                    };
    show_board(board);
    int i,j;
    cin>>i>>j;
    int x,y;
    cin>>x>>y;
    board[i][j]='P';
    board[x][y]='O';
    vector<string>v;
    string s="start";
    show_board(board);
    if(dfs(board,i,j,v,s)){
    cout<<"goal can found"<<endl;
    board[i][j]='P';
    board[x][y]='O';
    show_board(board);
    v.push_back("goal");
    for(auto it:v){
        cout<<it<<" ";
    }
    cout<<endl;
    }
    else
    cout<<"can't find gaol"<<endl;
    return 0;
    }