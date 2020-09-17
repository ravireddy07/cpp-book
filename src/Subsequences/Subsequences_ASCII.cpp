#include<bits/stdc++.h>
using namespace std;

void display(string str, int repo, string out[], int &outpos)
{
     if(str[repo]=='\0')
     {
          out[outpos++]="";
          return;
     }
     display(str,repo+1,out,outpos);
     for(int i=0;i<outpos;i++)
          out[outpos+i]=str[repo]+out[i];
     int outqw=outpos;
     outpos*=2;
     for(int i=0;i<outpos;i++)
     {
               ostringstream ss;
               int num = str[repo];
               ss<<num;
               out[i+outpos] = ss.str()+out[i];
     }
     outpos+=outqw;

}

int main()
{
     string input;
     cin>>input;

     string output[10000];
     int outputposi=0;

     display(input,0,output,outputposi);
     for(int i=0;i<outputposi;i++)
          cout<<output[i]<<"  ";

     cout<<"\n"<<outputposi;
}
