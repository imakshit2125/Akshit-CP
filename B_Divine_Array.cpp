#include <iostream>
using namespace std;
 
void reverseStringWordWise(char input[])
{
	int temp;
	int len=0;
	int i=0;
	while (input[i] != '\0'){
      	len++;
        i++;
	}
 
	int start = 0, end = len - 1;
 
      	while(start<end){
      	 temp= input[start];
      	 input[start]=input[end];
      	 input[end]=temp;
      	 start++;
    	 end--;
	}

	i=0;
	start=0;
	while(input[i]!='\0'){
  		if(input[i]==' '){
      	end=i-1;
	  	while(start<end){
      	 temp= input[end];
      	 input[end]=input[start];
      	 input[start]=temp;
      	 start++;
    	 end--;
   	   }
      	start=end-1;
 
	}
    i++;
 
	}
  // word
	end=len;
 
	while(start<=end){
  		temp= input[end];
      	 input[start]=input[end];
      	 input[start]=temp;
      	 start++;
    	  end--;
	}
}
int main() {
	char input[1000];
	cin.getline(input, 1000);
	reverseStringWordWise(input);
	cout << input << endl;
}
