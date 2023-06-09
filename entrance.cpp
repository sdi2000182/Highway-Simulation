#include "attiki1.h"

using namespace std;

Entrance::Entrance(int Seg)
{	this->Seg=Seg;
	Tolls=TollsNumber;
	eTolls=eTollsNumber;
    Toll* diod;
	int sum=Tolls+eTolls;//synolo diodiwn
	int i;
    for(i=0;i<sum; i++)
    {
        iter = t.begin();
        if(i%2){
			diod = new Toll(Seg,Highway::K,false);} //automato mhxanhma
        else 
        {diod = new Toll(Seg, Highway::K,true);}//kanoniko
        iter = t.insert(iter,diod);
    }
    cout << "An Entrance has been constructed\n\n";
}

Entrance::~Entrance()
{   int i;
    int sum=Tolls+eTolls;
    cout << "An Entrance to be destructed\n\n";
    for(i = 0; i < sum; i++)
        { delete t[i]; }
    t.clear();
}

int Entrance::vehicles_in_toll_queue()
{
    int total= 0,i;
    int total_tolls=Tolls+eTolls;
    for(i = 0; i < total_tolls; i++) 
    { total += t[i]->vq.size();}//prosthetei sta yparxonta  to megethos tou queue}
    return total; 
}

vector<Vehicle*> Entrance::operate(int var)
{
    Vehicle* ptr;
    vector<Vehicle*> vehvec;
    vector<Vehicle*>::iterator iter6; 
    int a=0,b=0,c=0;//to b einai o arithmos ton diwdiwn pou den ginetai na eksyp allo amaksi
    int total = Tolls + eTolls;
    while( b < total && c<var)
    {   b = 0;
        for(a=0; a<total; a++)
        {ptr = t[a]->pop1();//vgainei to ekastote amaksi apo to toll queue
        if(ptr == NULL)
        {
            b++;//auksanetai to b
            continue;}
        iter6 = vehvec.begin();
        iter6 = vehvec.insert(iter6,ptr);
        c++;
        if (c==var) 
        {break;}
        }
    }   
    for(a=0;a<total;a++)
    {
        t[a]->modify();//allazei to k opws leei sthn ekfwnhsh
        t[a]->push_into_vq(Seg); 
    }
    return vehvec;
}