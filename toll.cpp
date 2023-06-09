#include <iostream>
#include "attiki1.h"

using namespace std;

Toll::Toll(int node,int k,bool is_regular)
{   this->is_regular=is_regular;
    if(is_regular){
        K=k;
    }
    else{
        K=2*k;
    }
    eksodos=0;
    Vehicle* ptr;
    int i;
    for(i =0;i<NewCarsTolls;i++)
    {   
        ptr = new Vehicle(Highway::Nsegs,-1,node);
        vq.push(ptr);
    }
}

void Toll::push_into_vq(int n)
{
    Vehicle* ptr;
    int i;
    for(i = 0; i < NewCarsTolls; i++)
    {
        ptr = new Vehicle(-1,n,Highway::Nsegs);
        vq.push(ptr);
    }
} 

Toll::~Toll()
{   
    Vehicle* ptr;
    while(!vq.empty())
    {
        ptr = vq.front();
        delete ptr;
        vq.pop();
    }
}  
        
     
Vehicle* Toll::pop1()
{
    Vehicle* ptr;
    if(vq.size() > 0 && eksodos < K)
    {
        ptr = vq.front();
        vq.pop();
        eksodos++;
        return ptr;
    }
    else return NULL;  
}
        
void Toll::modify()
{if(eksodos< K)
{   K--;
    if(!is_regular) K--;}
else{
    K++;
    if(!is_regular) K++;}
eksodos = 0;
} 