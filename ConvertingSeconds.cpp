//*********************
//Antonio Salgado
//Project #2
//Compute seconds into day,hour,minute, seconds
//Due: Sep 18, 2017
//*********************
#include <string>
#include <iostream>
using namespace std;
void secToDay(int sec);
int  main(){
	int totalSeconds, hour, minute, secondsleft;
	string day[7]= {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
 	cout << "Enter seconds to calculate day of week and time: ";
 	cin >> totalSeconds; 
	secToDay(totalSeconds); 
	
	return 0;
}
void secToDay(int sec){
	string dayOfWeek[7]= {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	int day = sec / (24 * 3600); 
  
    sec = sec % (24 * 3600); 
    int hour = sec / 3600; 
  
    sec %= 3600; 
    int minutes = sec / 60 ; 
  hour = hour %12; 
    sec %= 60; 
    int seconds = sec;
	if(day==0)				//displays day as sunday
		cout<< dayOfWeek[0] << " "<<  hour << ":" << minutes << ":" << seconds; 
    	 else if (day == 1 )	//displays day as monday	
     		cout<< dayOfWeek[1] << " "<<  hour << ":" << minutes << ":" << seconds; 
    	 else if (day == 2)	//displays day as tuesday 
     		cout<< dayOfWeek[2] << " "<<  hour << ":" << minutes << ":" << seconds; 
	else if (day == 3)	//displays day as wednesday
     		cout<< dayOfWeek[3] << " "<<  hour << ":" << minutes << ":" << seconds; 
	else if (day == 4)	//displays day as thursday 
     		cout<< dayOfWeek[4] << " "<<  hour << ":" << minutes << ":" << seconds; 
	else if (day == 5)	//displays day as friday
     		cout<< dayOfWeek[5] << " "<<  hour << ":" << minutes << ":" << seconds; 
	else if (day == 6)	//displays day as saturday 
     		cout<< dayOfWeek[6] << " "<<  hour << ":" << minutes << ":" << seconds; 
	else 
		cout << "invalid entry" <<endl;




//    cout << day << " " << "days " << hour  
//         << " " << "hours " << minutes << " " 
//         << "minutes " << seconds << " " 
//         << "seconds "  << endl; 
	
	
	
	
	
}
