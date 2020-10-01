//
//  main.cpp
//  ShubhamPoggramme
//
//  Created by Mohit on 17/02/19.
//  Copyright © 2019 Mohit. All rights reserved.
//  it is the poggamme which show the sortest job first pogrrame in this pogramme has a arival time , burstime , process.
#include <iostream>
#include<stdlib.h>
using namespace std;

class process{
    public:
    int aT, bT , p ;

    void getAt(){
        cout<<"\n enter the arival time ";
        cin>>aT;
    }
    void getBt(){
        cout<<"\n enter the burst time ";
        cin>>bT;
    }
    void getP(){
        cout<<"\n enter the process ";
        cin>>p;
    }
};

int main(){

    int nP,i,j;
    int minAt , minBt , minPs;
    int count = 0;
    
    
    cout<<"\n \t \t \t  \t \t \t  \t \t \t ***********    limitation of the poggramme    ***********";
    cout<<"\n \n \t \t \t  \t \t \t  \t \t \t 1. nomber of process is greater then five .";
    cout<<"\n \n \t \t \t  \t \t \t  \t \t \t 2. ideal condition is not satisfied . \n ";

    cout<<"\n enter the number of the process :- ";
    cin>>nP;

    process p[nP]; // initialize of the process

    for(int i=0 ; i<= nP-1; i++){
        p[i].getP();

         p[i].getAt();

         p[i].getBt();
         
    }
    
    minAt = p[0].aT;
    minBt = p[0].bT;
    minPs = p[0].p;
    
    for(i=0 ; i<= nP-1; i++){                   // for the sort arrival time
    
        for(j=i+1 ; j<= nP-1; j++){
        
            if (p[i].aT > p[j].aT){
                minAt = p[j].aT;
                minBt = p[j].bT;
                minPs = p[j].p;
                p[j].aT = p[i].aT;
                p[j].bT = p[i].bT;
                p[j].p = p[i].p;
                p[i].aT = minAt;
                p[i].bT = minBt;
                p[i].p = minPs;
            
            }
       
        }
    }
    

    int k;
    int total = 0;
    count = 0;
    int sCount = 0;
    
    for(k= 0; k<nP ; k++){                  // for the sort arrival + burst
        minAt = p[count].aT;
        minBt = p[count].bT;
        minPs = p[count].p;
    
        for(i=count ; i<= nP-1; i++){   // for how many arrival time same in the programme
            if(minAt == p[i+1].aT){
            count++;
            total++;
            }
        }
    
        for(j = sCount ; j< count ; j++){    // here arival time same and sort according to burst time
        
            if(minBt > p[j+1].bT){
            minAt = p[j+1].aT;
            minBt = p[j+1].bT;
            minPs = p[j+1].p;
            p[j+1].aT = p[k].aT;
            p[j+1].bT = p[k].bT;
            p[j+1].p = p[k].p;
            p[k].aT = minAt;
            p[k].bT = minBt;
            p[k].p = minPs;
            }
        }
        
        sCount = ++count;
    
    }
    
 
    total = 0;
    count = p[0].bT;
    sCount = 0;
    int m;
    for(k = 0; k < nP ; k++){
        minBt = p[k+1].bT;
        for(i = k+1 ; i<=nP ;i++)
        {
            if(p[i].aT <= count && p[i].bT < minBt ){
                            minAt = p[i].aT;
                            minBt = p[i].bT;
                            minPs = p[i].p;
                            p[i].aT = p[k+1].aT;
                            p[i].bT = p[k+1].bT;
                            p[i].p = p[k+1].p;
                            p[k+1].aT = minAt;
                            p[k+1].bT = minBt;
                            p[k+1].p = minPs;
            }
        }
        
        count = count + p[k+1].bT;
    
    }
    
 
    for(i=0 ; i< nP ; i++){                     //  for the birstTime is equal at that time arrange proceess order wise
        if(p[i].bT == p[i+1].bT && p[i].p > p[i+1].p){
            m = p[i+1].p;
                p[i+1].p = p[i].p;
                p[i].p = m;
        }
    }

    cout<<"\n process \t Arrival time \t burstTime"; // for the display

    for(i=0 ; i<nP ;i++){
        cout<<"\n "<<p[i].p<<"        \t "<<p[i].aT<<"             \t "<<p[i].bT;
    }
    
    cout<<"\n \n ";
    cout<<"\n here below show the sequence of the process ";
    for(i=0;i<nP;i++){
        cout<<"\t "<<p[i].p<<"\t ";
    }

    return 0;
}


