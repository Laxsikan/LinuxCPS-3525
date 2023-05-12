#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cgicc/Cgicc.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>
#include <cgicc/CgiDefs.h> 
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/algorithm/string/split.hpp>
#include <ctime>
#include <stdio.h>  
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <queue>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


using namespace boost::gregorian;
using namespace boost::algorithm;
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

   void check_host_name(int hostname) { 
   if (hostname == -1) {
      perror("gethostname");
      exit(1);
   }
}
void check_host_entry(struct hostent * hostentry) { 
   if (hostentry == NULL){
      perror("gethostbyname");
      exit(1);
   }
}
void IP_formatter(char *IPbuffer) { 
   if (NULL == IPbuffer) {
      perror("inet_ntoa");
      exit(1);
   }
}

string checkTextData(string mydata) {
    char cstr[mydata.size()+1];
    char *token;
    mydata.copy(cstr,mydata.size()+1);
    string msg="";

    token = strtok(cstr,"\n");
    int height = stoi(strtok(token,","));
    int width = stoi(strtok(NULL,","));
    if (height >0 && width >0) {
        char darray[height][width];
        msg=msg + "<br>Height: " + to_string(height) + ", Width: " + to_string(width)+ "\n";

        mydata.copy(cstr,mydata.size()+1);
        token = strtok(cstr,"\n");
        token = strtok(NULL,"\n");
        for (int i=1; i<= height; i++) {
            msg = msg +"<br>" + token +"\n";
            for (int j=0;j<width;j++)
                strncpy(darray[i-1],token,width);
            token = strtok(NULL,"\n");
        }

   int objNum=0;
   int ct=0;
   int objCount=0;
   for (int i=0; i< height; i++) {
   for (int j=0; j< width; j++) {
      ct++;
   if (darray[i][j]=='T') {
      objNum++;
      objCount++;
      int objSize=0;
      int objX=0;
      int objY=0;
      queue<pair<int,int>> q;
      q.push(make_pair(i,j));
      while (!q.empty()) {
            pair<int,int> curr=q.front();
            q.pop();
            if (curr.first>=0 && curr.first<height && curr.second>=0 && curr.second<width && darray[curr.first][curr.second]=='T') {
               darray[curr.first][curr.second]='X';
               objSize++;
               objX+=curr.second;
               objY+=curr.first;
               q.push(make_pair(curr.first-1,curr.second));
               q.push(make_pair(curr.first+1,curr.second));
               q.push(make_pair(curr.first,curr.second-1));
               q.push(make_pair(curr.first,curr.second+1));
            }
      }
   double objCenterX=objX/(double)objSize;
   double objCenterY=objY/(double)objSize;

      char objCenterXStr[32];
      char objCenterYStr[32];
      snprintf(objCenterXStr, 32, "%.2f", objCenterX);
      snprintf(objCenterYStr, 32, "%.2f", objCenterY);

      msg = msg + "<br>Object id " + to_string(objCount) + " starts at (" + to_string(j) + "," + to_string(i) + "), size: " + to_string(objSize) + " chars, center at (" + string(objCenterXStr) + ", " + string(objCenterYStr) + ")\n";

                     }
                  }
            }
            msg = msg + "<br>Total number of objects: " + to_string(objNum) + "\n";
         } else {
            msg="<br>The height: " + to_string(height) + ", width: " + to_string(width) + " cannot be negative\n";
         }
         return msg;
}


int main () {

   
   cout << "Content-type:text/html\r\n\r\n";
   cout << "<html>\n";
   cout << "<head>\n";
   cout << "<title>CGI Environment Variables</title>\n";
   cout << "<h1>CPS 3525 project 2 output file</h1>" << endl;
   cout << "</head>\n";
   cout << "<body>\n";
   cout << "<table border = \"0\" cellspacing = \"2\">"; 
   
  
  /**
   ifstream inputFile("p2test.txt");

    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            cout << line << endl;
        }
        inputFile.close();
    }
    else {
        cout << "Unable to open file" << endl;
    }
    */

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
   printf("Current Host Name: %s<br>\n", host);
   printf("Host IP: %s<br>\n", IP);


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
  form_iterator gender = formData.getElement("gender");
  form_iterator age = formData.getElement("age");
  form_iterator gpa = formData.getElement("gpa");
  form_iterator birthday = formData.getElement("birthday");
  form_iterator biking = formData.getElement("Biking");
  form_iterator reading = formData.getElement("Reading");
  form_iterator fishing = formData.getElement("Fishing");
  form_iterator swimming = formData.getElement("Swimming");
  form_iterator term = formData.getElement("term");
  form_iterator mydata = formData.getElement("mydata");

   
   string nameError = "";
   string ageError = "";
   string gpaError = "";
   string interestError = "";
   string termError = "";

  
   if (name->isEmpty()) {
      nameError = "Name is required.";
   }
   
   if (age->isEmpty()) {
      ageError = "Age is required.";
   } 
   else {
      try {
         int ageValue = stoi(**age);
         if (ageValue < 0 || ageValue > 100) {
            ageError = "Age must be between 0 and 100.";
         }
         else {
         
         string birthdayStr = **birthday;
         int birthYear = stoi(birthdayStr.substr(0, 4));
         int birthMonth = stoi(birthdayStr.substr(5, 2));
         int birthDay = stoi(birthdayStr.substr(8, 2));
         time_t now = time(0);
         tm *ltm = localtime(&now);
         int currentYear = 1900 + ltm->tm_year;
         int currentMonth = 1 + ltm->tm_mon;
         int currentDay = ltm->tm_mday;
         int ageCalc = currentYear - birthYear;
         if (currentMonth < birthMonth || (currentMonth == birthMonth && currentDay < birthDay)) {
            ageCalc--;
         }
         if (ageCalc != ageValue) {
            ageError = "Age does not match birthday.";
         }
      }
   }  catch (invalid_argument&) {
      ageError = "Age must be a number.";
   }
}

if (gpa->isEmpty()) {
   gpaError = "GPA is required.";
}
else {
   try {
      float gpaValue = stof(**gpa);
      if (gpaValue < 0.0 || gpaValue > 4.0) {
         gpaError = "GPA must be between 0.0 and 4.0.";
      }
   } catch (invalid_argument&) {
      gpaError = "GPA must be a number.";
   }
}

if (biking->isEmpty() && reading->isEmpty() && fishing->isEmpty() && swimming->isEmpty()) {
   interestError = "At least one interest must be selected.";
}

if (term->isEmpty()) {
   termError = "A term must be selected.";
}  





char *remoteAddr = getenv("REMOTE_ADDR");
char *userAgent = getenv("HTTP_USER_AGENT");
cout << "<html><head><title>CPS 3525 Project 2 Output File</title></head><body>" << endl;

std::cout << "browser/OS: " << userAgent << "<br>" << std::endl;
  

   cout << "</table>\n";
   cout << "</body>\n";
   cout << "</html>\n";
  cout << HTTPHTMLHeader() << endl;
  cout << "<html><head><title>CPS 3525 project 2 output file</title></head><body>" << endl;
  if (!nameError.empty()) {
   cout << "<span style=\"color:red\">" << nameError << "</span><br>\n";
} 
else {
   cout << "Name: " << **name << "<br>" << endl;
}
cout << "Sex: " << **gender << "<br>" << endl;
cout << "Age: " << **age << "<br>" << endl;
if (!gpaError.empty()) {
   cout << "<span style=\"color:red\">" << gpaError << "</span><br>\n";
} 
else {
   cout << "GPA: " << **gpa << "<br>" << endl;
}
if (!ageError.empty()) {
   cout << "Birthday: "  << **birthday << "<br>" << "<span style=\"color:red\">" << ageError << "</span><br>\n";
} 
else {
   cout << "Birthday: " << **birthday << "<br>" << endl;
}
if (!interestError.empty()) {
   cout << "<span style=\"color:red\">" << interestError << "</span><br>\n";
} 
else {
   cout << "Interests: ";
   if (**biking == "ON") cout << "Biking ";
   if (**reading == "ON") cout << "Reading ";
   if (**fishing == "ON") cout << "Fishing ";
   if (**swimming == "ON") cout << "Swimming ";
   cout << "<br>" << endl;
}
if (!termError.empty()){
   cout << "<span style=\"color:red\">" << termError << "</span><br>\n";
} 
else {
   cout << "Term: " << **term << "<br>" << endl;
}
  cout << "<p>Input object text from web: "<<"<br>\n";
string output = checkTextData(**mydata);
cout << output << endl;
cout << "<pre>" << **mydata << "</pre>";

 
   cout << "<p>The data from the uploaded file: "<<"<br>\n";
     //Cgicc cgi;
   // get list of files to be uploaded
   const_file_iterator file = formData.getFile("userFile");
if(file != formData.getFiles().end()) {
   

string fileContent = file->getData();
   string result = checkTextData(fileContent);
   cout << result << endl;
   cout << "<pre>" << fileContent << endl;

   
   cout << "<p> "<<"<br>\n";

   int objNum1 = stoi(checkTextData(**mydata).substr(checkTextData(**mydata).find("Total number of objects: ") + 25));
   int objNum2 = stoi(checkTextData(fileContent).substr(checkTextData(fileContent).find("Total number of objects: ") + 25));
   if (objNum1>objNum2){
      cout << "File input has " << objNum1 << " objects, and web input has " << objNum2 << " objects. File input has more objects." << endl;
   }
   else {
   cout << "Web input has " << objNum2 << " objects, and file input has " << objNum1 << " objects. Web input has more objects." << endl;      
}
}
  
  
  cout << "</body></html>" << endl;


   

    return 0;
}