#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

//#include "learner.h"

using namespace std;

//CLASSES
class Voice 
{
	public:
	    void say(string phrase);    // Used to textually and audibly communicate a phrase
};

class Learner 
{
	string AIname_;
	public:
		Voice voice;
	    Learner();
	    ~Learner(){}
	    void respond(string phrase);    // Used to get, or teach a response
	    void say(string phrase);    // Used to textually and audibly communicate a phrase	    
	    void getName();
		void userSearch(string name);	    
	//    void say(string phrase);    // Used to textually and audibly communicate a phrase
};

//FUNCTIONS

Learner::Learner()
{
	AIname_="MEMORY";
}
void Learner::respond(string phrase)
{
    fstream memory;
    memory.open("Data/Brain.txt", ios::in);    // Open the memory file for input

    // Search through the file until the end is reached
    while( !memory.eof() ){    // While not at end of file
        string identifier;
        getline(memory,identifier);    // Get next phrase
        
        if(identifier == phrase){    // Is it the phrase we are looking for
            string response;
            getline(memory,response);   // If so, get the response
            voice.say(response);   // Textually and audibly output the response!
            return;    // Leave the function
        }
    }
	cout<<" It seems that i don't know the answer for this question yet. Please teach me the right answer:"<<endl;
    memory.close();    // Looks like we couldn't find the phrase in memory. Close the file!
    memory.open("Data/Brain.txt", ios::out | ios::app);    // Now open for output, and append at end of file
    memory << phrase << endl;    // Record initial phrase in memory
//	if(choice=)
  //  voice.say(phrase);   // Repeat the phrase the user entered
    string userResponse;
    cout << "ANSWER: ";
    getline(cin, userResponse);    // Get the ideal response
    memory << userResponse << endl;    // Write the ideal response to memory
    memory.close();    // Close the file!
}

void Learner::getName()
{
	cout<<AIname_;
}
void Voice::say(string phrase)
{
  //  string command = "espeak \"" + phrase + "\"";    // Concat the phrase to the command
  //  const char* charCommand = command.c_str();    // Convert to a const char* 
    cout << phrase << endl;    // Textually output phrase
   // system(charCommand);    // Send the command to cmd to execute espeak with the phrase an argument
}

void Learner::userSearch(string name)
{
	string user;
	char welcome=0;
	srand(time(NULL));
   	fstream USERS;
    USERS.open("Data/Users.txt", ios::in);    // Open the memory file for input
    // Search through the file until the end is reached
    while( !USERS.eof() )
	{    // While not at end of file
        string identifier;
        getline(USERS,identifier);    // Get next phrase
        if(identifier == name)// Is user exists?
		{
			welcome=rand()%2;
			cout<<endl;
			if(welcome==0)cout<<">Welcome back "<<name<<"!"<<endl;
			else if(welcome==1)cout<<">Heyy "<<name<<"!! "<<"Welcome Back!"<<endl;
         	else cout<<">I missed you "<<name<<". "<< "Welcome back!"<<endl;
		 //voice.say(response);   // Textually and audibly output the response!*/
            return;    // Leave the function
 		}
    }
	USERS.close();    // Looks like we couldn't find the phrase in memory. Close the file!
    USERS.open("Data/Users.txt", ios::out | ios::app);    // Now open for output, and append at end of file
	cout<< ">Hello "<< name<<"! We are talking to each other for first time, so i must introduce myself."<<endl;
	cout<<">My Name is ";
	Learner::getName();
	cout <<"."<<endl;
	cout<< ">I am an AI Chatbot. That means that we can chat to each other."<<endl;
	cout<<">In the future i will be able to speak, and help you with your stuff."<<endl;
	cout<<">Let's talk to each other!! You can start by saying hi to me!"<<endl;
    USERS << name << endl;    // Write the ideal response to memory
    USERS.close();    // Close the file!
}

//MAIN
int main (void)
{
    Learner AI;    // Create a learner object
	string user;
    string phrase;	
    cout<<"Write your name to wake up the chatbot: "; 
	cin>>user;
	AI.userSearch(user);
	getline(cin, phrase);
    for(;;)
	{
        cout <<"\n"<<">"<<user<<": ";    // User prompt
        getline(cin, phrase);    // Using getline for multi word input, then store in phrase. 
        cout << ">";AI.getName();cout<<": ";
        AI.respond(phrase);    // Pass the user input to the learner and see if he can respond
    }
}
