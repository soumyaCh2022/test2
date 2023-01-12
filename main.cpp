//update in git hub

#include <iostream>
using namespace std;

string InputString;
string OutputString;

string String_Capitalize(string ipString);
int String_Space_Position(string ipString);
int parameter_count(string ipString);
int String_Colon_Position(string ipString);
string String_subString(string Source,unsigned int start_Pos,unsigned int stop_Pos);

float voltage_set;
float current_set;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int colon_pos,space_pos,stringsize;
	string subString1,subString2,CAPITALString;
	string parameter;
	
	InputString = "SOUrce:curr 15.324\r\n" ;
	
	CAPITALString = String_Capitalize(InputString);
	
	colon_pos = String_Colon_Position(CAPITALString);
	space_pos = String_Space_Position(CAPITALString);
	stringsize = CAPITALString.length();
	
	
	//OutputString = String_Capitalize(InputString);
	
	subString1 = String_subString(CAPITALString,0,colon_pos-1);
	cout << subString1<<endl; 
	
	subString2 = String_subString(CAPITALString,colon_pos+1,space_pos-1);
	cout << subString2<<endl; 
	
	if(subString1=="SOU" || (subString1=="SOURCE"))
	{
		cout << "SubString1 Matched "<<endl; 
		
		if(subString2=="VOLT" || (subString2=="VOLTAGE"))
		{
			cout << "SubString2 Matched "<<endl; 
			
			parameter = String_subString(CAPITALString,space_pos+1,stringsize-2);
			 
			
			stringsize =  parameter.length();
			
			voltage_set = stof(parameter);
			
			cout << "voltage set = "<<voltage_set<<endl;
			
		}
		else if(subString2=="CURR" || (subString2=="CURRENT"))
		{
			cout << "SubString2 Matched "<<endl; 
			
			parameter = String_subString(CAPITALString,space_pos+1,stringsize-2);
			 
			
			stringsize =  parameter.length();
			
			current_set = stof(parameter);
			
			cout << "Current set = "<<current_set<<endl;
			
		}
		
		
	}
	//cout << String_Colon_Position(OutputString)<<endl; 
	
	
	return 0;
}

string String_subString(string Source,unsigned int start_Pos,unsigned int stop_Pos)
{
	string result;
	char scanning;
	int i;
	
	for(i=start_Pos;i<=stop_Pos;i++)
	{
		scanning = Source[i];
		result += scanning;
	}
	return(result);
}


int parameter_count(string ipString)
{
	unsigned int count=1;
	unsigned int StringLength;
	unsigned int i;
	StringLength = ipString.length();
	
	for(i=0;i<StringLength;i++)
	{
		if(ipString[i]==':')
		{
			count = count+1 ;
			break;
		}
		
	}
	
	return(count);
}

string String_Capitalize(string ipString)
{
	string result;
	unsigned int StringLength,space_pos,i;
	char scanning;
	
	StringLength = ipString.length();
	space_pos = String_Space_Position(ipString);
   
    for(i=0;i<StringLength;i++)
	{
		scanning = ipString[i];
		
		if(i<space_pos)
		{
			if(scanning>='a'&&scanning <='z')
			{
				scanning = scanning + ('A'-'a');
			}
		}
		
		result += scanning;
		
    }
	//result =  ipString;
	//cout << int(InputString[StringLength] )<<endl; // 13 = /r and 10=/n
	
	
	//cout << result <<endl; 
	
	//result+= "modified";
	
	return(result);
	
}

int String_Space_Position(string ipString)
{
	unsigned int pos;
	unsigned int StringLength;
	unsigned int i;
	StringLength = ipString.length();
	
	for(i=0;i<StringLength;i++)
	{
		if(ipString[i]==' ')
		{
			pos = i;
			break;
		}
		
	}
	//cout << pos <<endl; 
	return(pos);
}

int String_Colon_Position(string ipString)
{
	unsigned int pos;
	unsigned int StringLength;
	unsigned int i;
	StringLength = ipString.length();
	
	for(i=0;i<StringLength;i++)
	{
		if(ipString[i]==':')
		{
			pos = i;
			break;
		}
		
	}
	//cout << pos <<endl; 
	return(pos);
}