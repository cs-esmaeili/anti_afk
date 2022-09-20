#include <windows.h>
#include <iostream>
#include <conio.h>


using namespace std;

int random(int min, int max) //range : [min, max]
{
   return min + rand() % (( max + 1 ) - min);
}

int main ()
{
	cout<<"Welcome to anti afk \ncoded with love by ***Javad Esmaeili*** \nhttps://github.com/cs-esmaeili \n\n";

	int size, j, i;
	bool active = false;
	while(true){
		cout << "Enter number of the buttons : ";
		cin >> size;
		char array[size];
	
		for(j=0; j<size; j++){
			cout << "Enter button : ";
			cin >> array[j];	
		}
		cout<<"\nTo active anti afk press NUMLOCK number 1\n";
		cout<<"To Dactive anti afk press NUMLOCK number 2\n";
		cout<<"To reset anti afk press NUMLOCK number 3\n\n";
		while(true){
			Sleep(1000);
			if (GetAsyncKeyState(VK_NUMPAD1)){
				active = true;
				cout << "anti afk is : Active\n";
			}
			if (GetAsyncKeyState(VK_NUMPAD2)){
				active = false;
				cout << "anti afk is : DActive\n";
			}
			if (GetAsyncKeyState(VK_NUMPAD3)){
				break;
			}
			if(active){
				int randomChar = array[random(0,size - 1)];
				int button = VkKeyScan(randomChar); 
				
				keybd_event(button, 0, KEYEVENTF_EXTENDEDKEY, 0);
				Sleep(2000);
				keybd_event(button, 0, KEYEVENTF_KEYUP, 0);	
				Sleep(500);
			}

		}
	}	
	return 0;
}

