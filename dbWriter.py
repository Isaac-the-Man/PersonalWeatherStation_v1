# This program reads sensor data from serial Broadcast
# and write it into the mysql database weather

import serial
import mysql.connector


def list2Float(strList):
    try:
        concat = ''.join(strList)
        converted = float(concat)
    except ValueError as e:
        print(e)
        print(concat)
    return converted

# log in to the right mysql database
mydb = mysql.connector.connect(
    host='localhost',
    user='pi',
    passwd='pass',
    database='weatherDB'
)
mycursor = mydb.cursor()

def write2DB(values):
    assert len(values) == 7
    sqlText = '''INSERT INTO data(humidity, temperature, pressure, airqualityindex, uvindex, particledensity, image) VALUES({},{},{},{},{},{},{})'''.format(values[0], values[1], values[2], values[3], values[4], values[5], values[6])
    mycursor.execute(sqlText)
    mydb.commit()


# open serial
dev = '/dev/ttyACM0'

with serial.Serial(dev, 9600, timeout=1) as ser:
    buffer=[]
    record=[]

    while True:
        raw = ser.read()
        if raw:
            decoded = raw.decode('ascii')
            if (decoded is ':'):
                # a full number is read
                newFloat = list2Float(buffer)
                record.append(newFloat)
                buffer.clear()
            elif (decoded is ']'):
                # full record is read
                if (len(record) == 7):
                    #no arg is  missing, write to database
                    record[-1] = '\'some img\''
                    print(record)
                    write2DB(record)
                record.clear()
            else:
                # single letter is read
                buffer.append(decoded)
