#include<iostream>
#include <cmath>
#include<stdio.h>
#include <cstring>
#include <unistd.h>
using namespace std;

int decToBinary(int n)
{
	unsigned long long int B_Number = 0;

	int i = 0;
	while(n > 0)
	{
		int rem= n % 2;
		unsigned long long int c = pow(10, i);
		B_Number += rem * c;
		n /=2;

		i++;
	}
		return B_Number;
}

string convertToString(char* a, int size)
{
	int i;
	string s = "";
	for(i = 0; i < size; i++)
	{
		s = s + a[i];
	}
	return s;
}

void rightrotate(string &s, char &lost)
{
	//string s = "1001";
        int n = s.length();

        char char_array[n+1];

        strcpy(char_array, s.c_str());

        for(int i = 0; i < n; i ++)
        {
        //        cout<<char_array[i];
        }

        //cout<<endl<<endl;

	lost = char_array[n-1];

        for(int i = n -1; i >= 1; i--)
        {
                char_array[i] = char_array[i-1];
        }
                char_array[0] = '0';

        for(int i = 0; i < n; i ++)
        {
          //      cout<<char_array[i];
        }

        cout<<endl<<endl;

        int a_size = sizeof(char_array) / sizeof(char);

	string s_a = convertToString(char_array, a_size);

	for(int i = 0; s_a[i] != '\0'; i++)
	{
		s[i] = s_a[i];
	}
}

string addBinary(string a, string b)
{
	string result = "";
	int s = 0;

	int i = a.size() - 1, j = b.size() -1;

	while(i >= 0 || j >= 0 || s == 1)
	{
		//Comput sum of last digits and carry 
		s += ((i >= 0) ? a[i] - '0':0);
		s += ((j >= 0) ? b[j] - '0':0);
		//If current digit sum is 1 or 3, add 1 to result
		result = char(s % 2 + '0') + result;
		
		//Computer carry
		s /= 2;

		//Move to next digits
		i--; j--;

	}
	return result;
}

int main()
{
	char l_s = 0;
	int multiplicand, multiplier, num_1, num_2;
	cout<<"Enter the multiplicand (decimal)"<<endl;
	cin >>num_1;

	cout<<"Enter the multiplier (decimal)"<<endl;
	cin>>num_2;

	multiplicand = decToBinary(num_1);
	multiplier = decToBinary(num_2);	

//	cout<< multiplicand <<endl;
//	cout<< multiplier <<endl;

	int length = to_string(multiplicand).length();
//	cout<<length<<endl;
	string extension = "";	

	for(int i = 0; i < length; i++)
	{
		extension += "0";
	}

	string s_1 = extension + to_string(multiplicand);
//	cout<<s_1; 
	
	cout<<"Concept: "<<endl;
	cout<<"If a 0 is shifted out from the multiplicand, nothing happens";
	cout<<"If a 1 is shifted from the multiplicand, the multiplier is added to the result";
	cout<<endl;
	sleep(1);
	cout<<"Initialization(multiplicand): "<<s_1;
	cout<<endl;
	sleep(2);
	string s_2;
	string exten = "";
	
	int num_length = s_1.length() - to_string(multiplier).length();
 
	for(int i = 0; i < num_length; i++)
	{
		exten += "0";
	}

	s_2 = to_string(multiplier) + exten;
	
	string equal;

	for(int i = 0; i < length; i++)
	{
		rightrotate(s_1, l_s);
		cout<<"Shift Right   " <<s_1<<endl;
		sleep(2);
		if(l_s == '1')
		{
			cout<<" + "<<endl;
			cout<<"              "<<s_2<<endl;
			cout<<"---------------------"<<endl;
			sleep(2);
			equal = addBinary(s_1, s_2);
			
			for(int i = 0; s_1[i] != '\0'; i++)
        		{
                		s_1[i] = equal[i];
        		}
			cout<<equal<<endl;
			sleep(8);
		}	
		else
		{
			sleep(8);
			continue;
		}	
	}
	cout<<"SHR, One final time:";
	rightrotate(s_1, l_s);
	cout<<"Answer:     " <<s_1<<endl;

	return 0;
}
