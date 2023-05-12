//#include <iostream>
#include <vector>  
//#include <string> 
//#include <cstring>
 //#include <cstdlib> 
#include <stdio.h>  
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
//#include <stdlib.h> 
//#include <ctime>

//#include <cgicc/CgiDefs.h> 
//#include <cgicc/Cgicc.h> 
//#include <cgicc/HTTPHTMLHeader.h> 
//#include <cgicc/HTMLClasses.h>  

using namespace std;
using namespace cgicc;




const int NKEY=10;

const string ENV[ NKEY ] = {
   "HTTP_ACCEPT_LANGUAGE",
   "HTTP_CONNECTION",
   "HTTP_HOST",
   "HTTP_USER_AGENT",
   "QUERY_STRING",
   "REMOTE_ADDR",
   "REMOTE_PORT",
   "REQUEST_METHOD",
   "REQUEST_URI",
   "HTTP_REFERER"
   
   
   };

void check_host_name(int hostname) { //This function returns host name for local computer
   if (hostname == -1) {
      perror("gethostname");
      exit(1);
   }
}
void check_host_entry(struct hostent * hostentry) { //find host info from host name
   if (hostentry == NULL){
      perror("gethostbyname");
      exit(1);
   }
}
void IP_formatter(char *IPbuffer) { //convert IP string to dotted decimal format
   if (NULL == IPbuffer) {
      perror("inet_ntoa");
      exit(1);
   }
}

int main () 
{
     Cgicc cgi;
     //Cgicc formData;
    // bool biking_flag, reading_flag, fishing_flag, swimming_flag;
    // const_cookie_iterator cci;
      cout << "Content-type:text/html\r\n\r\n";
      cout << "CPS 3525 project 3 output file"<<"<br>\n"; 
      
   cout << "<html>\n";
   cout << "<head>\n";
   cout << "<title>CGI Environment Variables</title>\n";
   cout << "</head>\n";
   cout << "<body>\n";
   cout << "<table border = \"0\" cellspacing = \"2\">";
    
   time_t now = time(0);
   
   
   char* dt = ctime(&now);

   cout << "The local date and time is: " << dt  <<"<br>\n";

   char host[256];
   char *IP;
   struct hostent *host_entry;
   int hostname;
   hostname = gethostname(host, sizeof(host)); 
   check_host_name(hostname);
   host_entry = gethostbyname(host); 
   check_host_entry(host_entry);
   IP = inet_ntoa(*((struct in_addr*) host_entry->h_addr_list[0])); 
   printf("Current Host Name: %s\n", host);
   printf("Host IP: %s\n", IP);

   

   for ( int i = 0; i < NKEY; i++ ) {
      cout << "<tr><td>" << ENV[ i ] << "</td><td>";

      
      char *value = getenv( ENV[ i ].c_str() );
      if ( value != 0 ) {
         cout << value;
      } else {
         cout << "Environment variable does not exist.";
      }
      cout << "</td></tr>\n";
   }

  Cgicc formData;
  form_iterator name = formData.getElement("name");
  form_iterator sex = formData.getElement("sex");
  form_iterator age = formData.getElement("age");
  form_iterator gpa = formData.getElement("gpa");
  form_iterator birthday = formData.getElement("birthday");
  form_iterator biking = formData.getElement("Biking");
  form_iterator reading = formData.getElement("Reading");
  form_iterator fishing = formData.getElement("Fishing");
  form_iterator swimming = formData.getElement("Swimming");
  form_iterator term = formData.getElement("term");
  form_iterator mydata = formData.getElement("mydata");
    cout << "</table>\n";
   cout << "</body>\n";
   cout << "</html>\n"; 
    
  cout << HTTPHTMLHeader() << endl;
  cout << "<html><head><title>Form Data</title></head><body>" << endl;
  cout << "<h1>Form Data</h1>" << endl;
  cout << "<p>Name: " << **name << "</p>" << endl;
  cout << "<p>Sex: " << **sex << "</p>" << endl;
  cout << "<p>Age: " << **age << "</p>" << endl;
  cout << "<p>GPA: " << **gpa << "</p>" << endl;
  cout << "<p>Birthday: " << **birthday << "</p>" << endl;
  cout << "<p>Interests: ";
  if (**biking == "ON") cout << "Biking ";
  if (**reading == "ON") cout << "Reading ";
  if (**fishing == "ON") cout << "Fishing ";
  if (**swimming == "ON") cout << "Swimming ";
  cout << "</p>" << endl;
  cout << "<p>Term: " << **term << "</p>" << endl;
  cout << "</body></html>" << endl;
 

      
   /**
      



        
        std::string name = std::getenv("QUERY_STRING");
        std::string sex = std::getenv("QUERY_STRING");
        std::string age = std::getenv("QUERY_STRING");
        std::string gpa = std::getenv("QUERY_STRING");
        std::string birthday = std::getenv("QUERY_STRING");
        std::string interests = std::getenv("QUERY_STRING");
        std::string dropdown = std::getenv("QUERY_STRING");
        std::string textarea = std::getenv("QUERY_STRING");

       
        cout << "Name: " << name << std::endl;
       cout << "Sex: " << sex << std::endl;
        cout << "Age: " << age << std::endl;
       cout << "GPA: " << gpa << std::endl;
        cout << "Birthday: " << birthday << std::endl;
        cout << "Interests: " << interests << std::endl;
        cout << "Dropdown: " << dropdown << std::endl;
        cout << "Textarea: " << textarea << std::endl;
       
        
        std::cout << "Content-type: text/html\r\n\r\n";
        std::cout << "<html><head><title>Web Inputs</title></head><body>";
        std::cout << "<h1>Web Inputs</h1>";
        std::cout << "<p>Name: " << name << "</p>";
        std::cout << "<p>Sex: " << sex << "</p>";
        std::cout << "<p>Age: " << age << "</p>";
        std::cout << "<p>GPA: " << gpa << "</p>";
        std::cout << "<p>Birthday: " << birthday << "</p>";
        std::cout << "<p>Interests: " << interests << "</p>";
        std::cout << "<p>Dropdown: " << dropdown << "</p>";
        std::cout << "<p>Textarea: " << textarea << "</p>";
        std::cout << "</body></html>";
        std::cout << "Set-Cookie:Path = /perl;\n";
        std::cout << "Set-Cookie:UserID = XYZ;\r\n";
        std::cout << "Set-Cookie:Password = XYZ123;\r\n";
        std::cout << "<table border = \"0\" cellspacing = \"2\">";
   
   
     form_iterator fi = formData.getElement("user_name");  
   if( !fi->isEmpty() && fi != (*formData).end()) {  
      cout << "User name: " << **fi << endl;  
   } else {
      cout << "No text entered for user name" << endl;  
   }
   cout << "<br/>\n";
    fi = formData.getElement("sex");  
   if( !fi->isEmpty() && fi != (*formData).end()) {  
      cout << "No text entered for radio box selected: " << **fi << endl;  
   }
    cout << "<br/>\n";
   fi = formData.getElement("age");  
   if( !fi->isEmpty() &&fi != (*formData).end()) {  
      cout << "Age: " << **fi << endl;  
   } else {
      cout << "No text entered for age" << endl;  
   }
    cout << "<br/>\n";
   fi = formData.getElement("gpa");  
   if( !fi->isEmpty() &&fi != (*formData).end()) {  
      cout << "GPA: " << **fi << endl;  
   } else {
      cout << "No text entered for gpa" << endl;  
   }
     fi = formData.getElement("interest"); 
   biking_flag = formData.queryCheckbox("biking");
   if( biking_flag ) {  
      cout << "Biking Flag: ON " << endl;  
   } else {
      cout << "Biking Flag: OFF " << endl;  
   }
   reading_flag = formData.queryCheckbox("reading");
   if( reading_flag ) {  
      cout << "Reading Flag: ON " << endl;  
   } else {
      cout << "Reading Flag: OFF " << endl;  
   }
   fishing_flag = formData.queryCheckbox("fishing");
   if( fishing_flag ) {  
      cout << "Fishing Flag: ON " << endl;  
   } else {
      cout << "Fishing Flag: OFF " << endl;  
   }
   swimming_flag = formData.queryCheckbox("swimming");
   if( swimming_flag ) {  
      cout << "Swimming Flag: ON " << endl;  
   } else {
      cout << "Swimming Flag: OFF " << endl;  
   }
     cout << "<br/>\n";
     fi = formData.getElement("dropdown");  
   if( !fi->isEmpty() && fi != (*formData).end()) {  
      cout << "Value Selected: " << **fi << endl;  
   }
     cout << "<br/>\n";
    fi = formData.getElement("textcontent");  
   if( !fi->isEmpty() && fi != (*formData).end()) {  
      cout << "Text Content: " << **fi << endl;  
   } else {
      cout << "No text entered" << endl;  
   }
       
   
   
   
    // get list of files to be uploaded
   const_file_iterator file = cgi.getFile("userfile");
   if(file != cgi.getFiles().end()) {
      // send data type at cout.
      cout << HTTPContentHeader(file->getDataType());
      // write content at cout.
      file->writeToStream(cout);
   }
   // get environment variables
   const CgiEnvironment& env = cgi.getEnvironment();

   for( cci = env.getCookieList().begin();
   cci != env.getCookieList().end(); 
   ++cci ) {
      cout << "<tr><td>" << cci->getName() << "</td><td>";
      cout << cci->getValue();                                 
      cout << "</td></tr>\n";
   }
   cout << "<File uploaded successfully>\n";
   
   cout << "Setting cookies" << endl; 


   cout << "<br/>\n";
   cout << "</body>\n";
   cout << "</html>\n";

   
     const int HEIGHT = 6;
    const int WIDTH = 7;
    char board[HEIGHT][WIDTH] = {
        {'B', 'B', 'B', 'B', 'B', 'B', 'B'},
        {'B', 'T', 'T', 'B', 'B', 'T', 'B'},
        {'B', 'B', 'B', 'B', 'B', 'B', 'B'},
        {'B', 'B', 'B', 'T', 'B', 'B', 'B'},
        {'B', 'T', 'T', 'T', 'B', 'B', 'B'},
        {'B', 'B', 'B', 'B', 'B', 'B', '#'}
    };

    // Print board
    cout << "Height: " << HEIGHT << ", width: " << WIDTH << endl;
    for (int i = 0; i < HEIGHT; i++) {
        cout << i+1 << ":";
        for (int j = 0; j < WIDTH; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }

    // Print board coordinates and characters
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            cout << "(" << j << "," << i << "): " << board[i][j] << endl;
        }
    }

    // Count characters
    int numB = 0, numT = 0, totalChars = 0;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (board[i][j] == 'B') {
                numB++;
            } else if (board[i][j] == 'T') {
                numT++;
            }
            totalChars++;
        }
    }

    // Print character count and guess
    cout << "Total number of char: " << totalChars << ", number of B is " << numB << ", number of T is " << numT << endl;
    int guess = 2;
    cout << "Your guess is " << guess << " and there are " << totalChars << " characters" << endl;
    if (guess == totalChars) {
        cout << "You are correct!" << endl;
    } else {
        cout << "You are wrong!" << endl;
    }

    // Write to file
    ofstream outputFile("output.txt");
    if (outputFile.is_open()) {
        outputFile << "Height: " << HEIGHT << ", width: " << WIDTH << endl;
        for (int i = 0; i < HEIGHT; i++) {
            outputFile << i+1 << ":";
            for (int j = 0; j < WIDTH; j++) {
                outputFile << board[i][j];
            }
            outputFile << endl;
        }
        outputFile << "Total number of char: " << totalChars << ", number of B is " << numB << ", number of T is " << numT << endl;
        outputFile.close();
        cout << "File uploaded and saved successfully" << endl;
    } else {
        cout << "Error: Unable to open file" << endl;
    }
   */
   return 0;
}