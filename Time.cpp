#include <iostream>
using namespace std;
#include <unistd.h>


class Time
{
private:
  int hours;
  int minutes;
  int seconds;
  
    public:
  Time (int, int, int);
  void operator ++ ();
  void operator ++ (int dummy);
  void operator - (Time&);
  bool operator == (Time&);
  friend istream & operator >> (istream & cin, const Time &);
  friend ostream & operator << (ostream & cout, const Time &);
};

Time::Time (int hours=0,int minutes=0,int seconds=0)
{

     if(hours >= 0 && hours <= 23 ){
        this->hours = hours;
    }
    else {
        this->hours = 0;
    }
    if(minutes >= 0 && minutes <= 59 ){
        this->minutes = minutes;
    }
    else {
        this->minutes = 0;
    }
    if(seconds >= 0 && seconds <= 59 ){
        this->seconds = seconds;
    }
    else {
        this->seconds = 0;
    }
}


 istream & operator >> (istream & cin, const Time & timeLater)
{
    cout<<"Set the time:\nHour: ";
    cin>>timeLater.hours;
    while(timeLater.hours < 0 || timeLater.hours > 23){
        cout<<"Enter valid hour: ";
        cin>>timeLater.hours;
    }
    cout<<"Minutes: ";
    cin>>timeLater.minutes;
    while(timeLater.minutes < 0 || timeLater.minutes > 59){
        cout<<"Enter valid minutes: ";
        cin>>timeLater.minutes;
    }
    cout<<"Seconds: ";
    cin>>timeLater.seconds;
    while(timeLater.seconds < 0 || timeLater.seconds > 59){
        cout<<"Enter valid seconds: ";
        cin>>timeLater.seconds;}
        
        return cin;
    }

ostream & operator << (ostream & cout, const Time &timeLater)
{
  
    if(timeLater.hours <= 9){
        cout<<"0";
    }
    cout<<timeLater.hours<<":";
    if(timeLater.minutes <= 9){
        cout<<"0";
    }
    cout<<timeLater.minutes<<":";
    if(timeLater.seconds <= 9){
        cout<<"0";
    }
    cout<<timeLater.seconds;
 
   
    return cout;
}  

void Time:: operator ++ ()
{
    seconds=seconds+1;
    if(seconds > 59){
        seconds = 0;
        ++minutes; 
        if(minutes > 59){
            minutes = 0;
            ++hours;
            if(hours > 23){
                hours = 0;
            }
        }
    } 
    
}
    
    
 void Time ::operator ++ (int dummy)
 {
      seconds=seconds+1;
    if(seconds > 59){
        seconds = 0;
        ++minutes; 
        if(minutes > 59){
            minutes = 0;
            ++hours;
            if(hours > 23){
                hours = 0;
            }
        }
    } 
     
 }



void Time :: operator - (Time& timeLater)
{
    
    hours=hours-timeLater.hours;
   minutes= minutes-timeLater.minutes;
    seconds=seconds-timeLater.seconds;
    
    if(timeLater.hours <= 9){
        cout<<"0";
    }
    cout<<timeLater.hours<<":";
    if(timeLater.minutes <= 9){
        cout<<"0";
    }
    cout<<timeLater.minutes<<":";
    if(timeLater.seconds <= 9){
        cout<<"0";
    }
    cout<<timeLater.seconds;
    cout<< timeLater;
}





 bool Time:: operator == (Time& timeLater )
 {
   if( hours==timeLater.hours&&
       minutes==timeLater.minutes&&
       seconds==timeLater.seconds
     )
     
     return true ;
     else 
     return false;
     
 }
 
 

int main()
{

Time timeNow(13,56,33);
Time timeLater;
cout<<timeNow;
cout<<endl;
++timeLater;
cout<<endl;
cout<<timeLater;
cout<<endl;
timeNow==timeLater;
cout<<endl;

cout<<endl;
timeNow-timeLater;

cin>>timeNow;
cout<<endl;





    return 0;
}
