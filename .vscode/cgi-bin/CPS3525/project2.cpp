#include <fstream>
#include <iostream>
#include <vector>  
#include <string>  
#include <stdio.h>  
#include <stdlib.h> 

#include <cgicc/CgiDefs.h> 
#include <cgicc/Cgicc.h> 
#include <cgicc/HTTPHTMLHeader.h> 
#include <cgicc/HTMLClasses.h>  

using namespace std;
using namespace cgicc;

int main () {
     Cgicc cgi;
   Cgicc formData;
     bool biking_flag, reading_flag, fishing_flag, swimming_flag;
     const_cookie_iterator cci;

   cout << "Content-type:text/html\r\n\r\n";
   cout << "Set-Cookie:Path = /perl;\n";
   cout << "Set-Cookie:UserID = XYZ;\r\n";
   cout << "Set-Cookie:Password = XYZ123;\r\n";
   cout << "<html>\n";
   cout << "<head>\n";
   cout << "<title>Hello World - First CGI Program</title>\n";
   cout << "</head>\n";
   cout << "<body>\n";
   cout << "<h2>Hello World! This is my first CGI program</h2>\n";
   cout << "</body>\n";
   cout << "<table border = \"0\" cellspacing = \"2\">";
   cout << "</html>\n";
   
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

   

   
   return 0;
}