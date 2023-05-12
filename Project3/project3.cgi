#!/usr/bin/python3

from http.client import HTTPException
import os
import cgi
import cgitb
import subprocess
from subprocess import STDOUT, PIPE
import stat
import smtplib
import datetime


cgitb.enable()
form = cgi.FieldStorage()


print('Content-type:text/html\r\n\r\n')
#hostname = socket.gethostname()
#IPAddr = socket.gethostbyname(hostname)
#print("<br>Your Computer Name is: " + hostname)
#print("<br>Your Computer IP Address is: " + IPAddr)


print('<head></head>')

print('<body>\n')

print('<div style = "margin-left: 2.5%; font-size: 200%">')

print('<h1 style="line-height: 150%; margin-bottom:-1.25%">Project 3 Results</h1>\n')

try:
    if 'Upload' not in form:
        raise Exception(f'Please Visit the <a href="../CPS3525/project3.html">previous page</a> first.')
   
    stateFile = form['stateFile']
    zipcodeFile = form['zipcodeFile']

    stateAllowedColumns = 8
    zipcodeAllowedColumns = 21

    basePath = '../CPS3525/upload/'

    stateTarget = basePath + stateFile.filename
    zipcodeTarget = basePath + zipcodeFile.filename

    state_line = stateFile.file.readline()
    tokens = state_line.split(b',')
    columns = len(tokens)
    fileExtension = os.path.splitext(stateFile.filename)[1]

    if fileExtension != '.csv':
        raise Exception(f'<br>Incorrect file type. \n<br>State File: <b>{os.path.basename(stateFile.filename)}</b> must be .csv')
        
    if columns != stateAllowedColumns:
        raise Exception(f'<br>Incorrect amount of columns in State File: <b>{os.path.basename(stateFile.filename)}</b>\n<br>Allowed Columns: <b>{stateAllowedColumns}</b>. Columns in file: <b>{columns}</b>')
        
    zipcode_line = zipcodeFile.file.readline()
    tokens = zipcode_line.split(b',')
    columns = len(tokens)
    fileExtension = os.path.splitext(zipcodeFile.filename)[1]

    if fileExtension != '.csv':
        raise Exception(f'<br>Incorrect file type. \n<br>Zipcode File: <b>{os.path.basename(zipcodeFile.filename)}</b> must be .csv')

    if columns != zipcodeAllowedColumns:
        raise Exception(f'<br>Incorrect amount of columns in Zipcode File: <b>{os.path.basename(zipcodeFile.filename)}</b>\n<br>Allowed Columns: <b>{zipcodeAllowedColumns}</b>. Columns in file: <b>{columns}</b>')

    with open(stateTarget, 'wb') as targetFile:
        targetFile.write(state_line)
        targetFile.write(stateFile.file.read())
        os.chmod(stateTarget, stat.S_IRWXU | stat.S_IROTH | stat.S_IXOTH)


    with open(zipcodeTarget, 'wb') as targetFile:
        targetFile.write(zipcode_line)
        targetFile.write(zipcodeFile.file.read())
        os.chmod(zipcodeTarget, stat.S_IRWXU | stat.S_IROTH | stat.S_IXOTH)


    print('<p style="margin-left: 3.5%; line-height: 50%"> Files Successfully Uploaded. From Clint</p>')
    print (cgi.escape(os.environ["REMOTE_ADDR"]))
    current_time=datetime.datetime.now()
    print(current_time)
    print('<br>')
    print('result is available to view at<a href = "../CPS3525/Project3_results.html"> here </a>')


    
  

    cmd = "java -cp ./ project3 \"" + str(stateTarget) + "\" \"" + str(zipcodeTarget) + "\""

    proc = subprocess.Popen(cmd, shell=True, stdout=PIPE, stderr=STDOUT, universal_newlines=True)

    stdout,stderr = proc.communicate(input='')

    if(stderr):
        raise Exception(f'Java Error has occured: {stderr}')
    else:
        print(stdout)
    
    timeDifference = ((datetime.datetime.now() - current_time).total_seconds()) * 1000

    sender = 'manoranl@kean.edu'
    recievers = 'manoranl@kean.edu'
    
    message = """Subject: CPS3525 Project 3 Result
To: manoranl@kean.edu
From: manoranl@kean.edu
Content-Type: text/html; charset = \"UTF-8\"

The java program was run at <b>"""

    message = message + str(current_time) + " stamp (), and the result is available to view <a href = \"yoda.kean.edu/~manoranl/CPS3525/Project3_results.html\"> here </a>"

    try:
        smtpObj = smtplib.SMTP('localhost')
        smtpObj.sendmail(sender, recievers, message)
    except HTTPException:
        print('<br>Error sending email.<br>')

    print("</div>\n</body>")

except Exception as Err:
    print('\n<br>An Error has occured. Please try again.<br>')
    print(Err)
    print("</div>\n</body>")