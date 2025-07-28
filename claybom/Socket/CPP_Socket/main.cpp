//I didnt write the socket wrapper class...I found it on te Baylor csci website...http://cs.ecs.baylor.edu/~donahoo/practical/CSockets/practical/
//It's an awesome library...the best I have seen....here is a simple example of its usage
//to get the time from a net time server....just pass the ip for a time server..http://www.boulder.nist.gov/timefreq/service/time-servers.html
//for windows you will need to add the wsock32.lib to your link options objects section....
//fallenhobit....................................................

#include "PracticalSocket.h"  // For Socket and SocketException
#include <iostream>           // For cerr and cout
#include <cstdlib>            // For atoi()

using namespace std;

void GetTime(char *address, char* timebuffer);

int main(int argc, char *argv[]) 
{
/*  if (argc < 2) 
  {     // Test for correct number of arguments
    cerr << "Usage: " << argv[0] 
         << " <Server>" << endl;
    exit(1);
  }*/
	char servAddress[119];
	strcpy(servAddress, "new.uol.com.br");//servAddress,argv[1]); // First arg: server address
	char timebuffer[50];
	GetTime(servAddress,timebuffer);
	cout << timebuffer << endl;

  return 0;
}

void GetTime(char *servAddress, char* timebuffer)
{
	 unsigned short echoServPort = 13;

  try {
    // Establish connection with the time server
    TCPSocket sock(servAddress, echoServPort);
    int bytesReceived = 0;              // Bytes read on each recv()
    int totalBytesReceived = 0;         // Total bytes read
    while (totalBytesReceived < 47 )//time protocol used by these servers passes back 47 bytes
	{
      // Receive up to the buffer size bytes from the sender
      if ((bytesReceived = (sock.recv(timebuffer, 47))) <= 0) 
	  {
		strcpy(timebuffer,"Error.");
		return;
      }
      totalBytesReceived += bytesReceived;     // Keep tally of total bytes
      timebuffer[bytesReceived] = '\0';        // Terminate the string
    }
  } 
  catch(SocketException &e) 
  {
	strcpy(timebuffer,"Error.");
    return;
  }
}
