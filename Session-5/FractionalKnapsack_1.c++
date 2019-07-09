#include<iostream>
#include<iomanip>
using namespace std;

void Fract_Knapsack(int size, int cap, int w[], int v[]) {
    int curr_weight, temp, filled[10];
    float total_value;

    for(int i=0;i<size;i++) {
      filled[i] = 0;
    }

    curr_weight = cap;
    while(curr_weight>0) {
      temp = -1;
      for(int i=0;i<size;i++) {
        if((filled[i] == 0) && ((temp == -1) || ((float)v[i]/w[i] > (float)v[temp]/w[temp]))) {
          temp = i;
        }
      }
      filled[temp] = 1;
      curr_weight -= w[temp];
      total_value += v[temp];
      if(curr_weight<=0) {
        total_value -= v[temp];
        total_value += (1+(float)curr_weight/w[temp])*v[temp];
      }
    }
    //printf("%0.1f", total_value);
    cout<<fixed<<setprecision(1)<<total_value<<endl;
}

int main(int argc, char *argv[]) {
    int size,cap;
    //scanf("%d%d", &size, &cap);
    cin>>size>>cap;
    int v[size],w[size];
    for(int i=0;i<size;i++) {
        //scanf("%d%d", &v[i], &w[i]);
        cin>>v[i]>>w[i];
    }

    Fract_Knapsack(size, cap, w, v);
    return 0;
}
