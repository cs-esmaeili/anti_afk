#include <windows.h>
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

int random(int min, int max) //range : [min, max]
{
   return min + rand() % (( max + 1 ) - min);
}

int main ()
{

	while(true){
		int size, j, i ;
		int lastNumber = -1;
		bool active = false;
		string input = "";
		string mode = "r";
		system("cls");
		cout<<"Welcome to anti afk \ncoded with love by ***Javad Esmaeili*** \nhttps://github.com/cs-esmaeili \n\n";
  		cout << "Enter the buttons : ";
 		cin >> input;
 		size = input.length();
        char array[size + 1];
   		strcpy(array, input.c_str());
    
    	cout << "Enter the Mode (r for Random , s for sequence) : ";
    	cin >> mode;
    	
  		for (int i = 0; i < size; i++){
			cout << array[i] << "\n";
		}
        	
		cout<<"\nTo active anti afk press NUMLOCK number 1\n";
		cout<<"To Dactive anti afk press NUMLOCK number 2\n";
		cout<<"To reset anti afk press NUMLOCK number 3\n\n";
		while(true){
			Sleep(1000);
			if (GetAsyncKeyState(VK_NUMPAD1)){
				active = true;
				cout << '\r';
				cout << "anti afk is : Active\n";
			}
			if (GetAsyncKeyState(VK_NUMPAD2)){
				active = false;
				cout << '\r';
				cout << "anti afk is : DActive\n";
			}
			if (GetAsyncKeyState(VK_NUMPAD3)){
				break;
			}
			if(active){
				int randomNumber= -1;
				if(mode == "r"){
					while(true){
						 randomNumber = random(0,size - 1);
						 if(randomNumber != lastNumber || size == 1){
						 	break;
						 }
					}
				}else{
					randomNumber = lastNumber;
					if(randomNumber == -1){
						randomNumber = 0;
					}else{
						if(randomNumber + 1 < size){
							randomNumber = randomNumber + 1;	
						}else{
							randomNumber = 0;
						}
					}
				
				}
				lastNumber = randomNumber;
				char randomChar = array[randomNumber];
				int button = VkKeyScan(randomChar); 
				
				keybd_event(button, 0, KEYEVENTF_EXTENDEDKEY, 0);
				Sleep(1000);
				keybd_event(button, 0, KEYEVENTF_KEYUP, 0);	
				Sleep(500);
			}

		}
	}	
	return 0;
}

