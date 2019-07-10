# This python script reads values from mysql database
# and update the html file for the web server

import mysql.connector
import numpy as np
from time import sleep
import graphUpdater as graph
import time


# |id|timestamp|humidity|temperature|pressure|airqualityindex|uvindex|particledensity|image|
#  0       1        2         3           4            5           6           7        8
NAMES = ['id','timestamp','humidity','temperature','pressure','gas','uv','particle','image']
NAMES_UNIT = [' ',' ',' %',' *C', ' pa', 'kohm',' mW/cm^2', ' mg/m3', ' ']

# log in to mysql data base
mydb = mysql.connector.connect(
    host='localhost',
    user='pi',
    passwd='pass',
    database='weatherDB'
)
mycursor = mydb.cursor()

# start the graph updater
#graph.initGraphUpdater(mycursor)

# reads in all values from past n records
def fetchAllData(nRec):
    sql='''select * from data order by id desc limit {}'''.format(nRec)
    mycursor.execute(sql)
    result = np.array(mycursor.fetchall())
    for i in range(2, 8):
        avg = np.mean(result[:,i])
        updateFile('/var/www/html/{}Value.html'.format(NAMES[i]), avg, i)
        
# update the html
def updateFile(filename, value, index):
    with open(filename, 'w+') as myhtml:
        newStr = '<p>{}  {}</p>'.format(value, NAMES_UNIT[index])
        print(newStr, file=myhtml)

graph.generateGraph(mycursor)
print('graph updated !')
prevTime = time.time()
while(True):
    # set refresh rate
    now = time.time()
    if(prevTime is not None and now - prevTime >= 600):
        # update graph every 10 minutes
        graph.generateGraph(mycursor)
        prevTime = now
        print('graph updated !')

    sleep(10)
    fetchAllData(5)
    print('web data updated !')
    mydb.commit()
    

