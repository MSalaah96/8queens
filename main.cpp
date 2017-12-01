#include <bits/stdc++.h>

using namespace std;
vector<vector<int> >sol ;
bool run  = true ;
void solve (vector<vector<int> > v , int i , int j , int co)
{
    // Termination function ;
    if(co == 8){
        sol = v ;
        run = false ;
        cout<<"--------------- Final Answer ----------------------\n";
        for(int ii = 0 ; ii < v.size() ; ii++)
        {
            for(int jj = 0 ; jj <v[ii].size();jj++)
            {
                cout<<v[ii][jj]<<"\t";
            }
            cout<<endl ;
        }
        cout<<"-------------------------------------\n";
        return ;
    }
    else if(run== false){
        return ;
    }
    else if(j>7){
//        cout<<"i="<<i<<"\t"<<"j="<<j<<"\n";
        solve(v,i+1,0,co);
        return ;
    }
    else if(i>7){
  //      cout<<"i="<<i<<"\t"<<"j="<<j<<"\n";
        return ;
    }
    //solve function ;
    if (v[i][j]==1){
        solve(v,i+1,0,co);
        return;
    }
    solve(v,i,j+1,co);
    if(v[i][j]==5){

        co++;
        //fill
        //-----------------------------------------------//
    int a ,b;
        for(int h = 0 ; h<8;h++){
            v[i][h]=0;
            v[h][j]=0;
        }
        if (i<=j){
            a = 0;
            b = j-i;
        }
        else {
            a = i-j;
            b = 0;
        }
        while (a < 8 && b <8){
          //  cout<<a <<"   "<<b<<endl;
            v[a][b]=0;
            a++;
            b++;

        }

        a = i ; b =j;
        while (a >= 0 && b < 8){
          //  cout<<a <<"   "<<b<<endl;
            v[a][b]=0;
            a--;
            b++;

        }
        a = i ; b =j;
        while (a < 8 && b >= 0 ){
            v[a][b]=0;
            a++;
            b--;
        }
        v[i][j]=1;
        //-----------------------------------------------//
        solve(v,i+1,0,co);
    }
}
int main()
{
    //fill
        //-----------------------------------------------//
       vector<vector<int> >  v ;
       for(int i = 0 ; i <  8 ; i++)
       {
           vector<int>vv ;
            for(int j = 0 ; j < 8 ; j++)
            {
                vv.push_back(5);
            }
            v.push_back(vv);
       }
        int i = 2 ;
        int j = 3 ;
        cin>>i>>j;
        int a ,b;
        for(int h = 0 ; h<8;h++){
            v[i][h]=0;
            v[h][j]=0;
        }

    //Done

        if (i<=j){
            a = 0;
            b = j-i;
        }
        else {
            a = i-j;
            b = 0;
        }
        while (a < 8 && b <8){
          //  cout<<a <<"   "<<b<<endl;
            v[a][b]=0;
            a++;
            b++;

        }
        a = i ; b =j;
        while (a >= 0 && b < 8){
          //  cout<<a <<"   "<<b<<endl;
            v[a][b]=0;
            a--;
            b++;

        }
        a = i ; b =j;
        while (a < 8 && b >= 0 ){
            v[a][b]=0;
            a++;
            b--;
        }
        v[i][j]=1;

        solve(v,0,0,1);
        //-----------------------------------------------//
}
