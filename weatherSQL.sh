cd /home/pi/dev/weatherStation/build/
/home/pi/go/bin/./cloud_sql_proxy -dir=/cloudsql -instances=weather-station-2019:asia-east1:weather-station-2019-sqlserver -credential_file=weather-station-2019-b750a7d86184.json &
#sudo python3 dbWriter.py
#sudo python3 webUpdater.py
