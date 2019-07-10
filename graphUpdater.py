from matplotlib import pyplot as plt
from matplotlib import dates as mdates
import numpy as np
import mysql.connector
from datetime import datetime, timedelta


paramList = ['humidity','temperature', 'pressure', 'airqualityindex', 'uvindex', 'particledensity']

#mycursor = None

# initialize graph updater
#def initGraphUpdater(cursor):
#    mycursor = cursor

# get the current day
def getDay(mycursor):
    mycursor.execute('select timestamp from data order by id desc limit 1')
    current = mycursor.fetchall()[0][0]
    today = datetime(current.year, current.month, current.day, 0,0,0)
    todayList = [today]
    for i in range(1,24):
        todayList.append(today + timedelta(hours=i))
    return todayList

# generate every graph
def generateGraph(mycursor):
    for param in paramList:
        fig, subplt = plt.subplots()

        today = getDay(mycursor)
        
        sql = 'select timestamp,{} from data where timestamp > {} and timestamp < {}'.format(param,'\'{}\''.format(today[0]), '\'{}\''.format(today[-1] + timedelta(minutes=59, seconds=59)))
        mycursor.execute(sql)
        res = np.array(mycursor.fetchall())

        x = res[:, 0]
        y = res[:, 1]
       
        # use the first found timestamp as graph time title
        fig.suptitle('{} {}'.format(param, x[0].strftime('%Y-%b-%d')))
        plt.plot(x, y)
        plt.xticks(today)
        dateFmt = mdates.DateFormatter('%H')
        subplt.xaxis.set_major_formatter(dateFmt)
        fig.savefig('/var/www/html/{}.png'.format(param))
