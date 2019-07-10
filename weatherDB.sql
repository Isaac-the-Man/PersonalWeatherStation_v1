
DROP DATABASE IF EXISTS weatherDB;

CREATE DATABASE weatherDB;

use weatherDB;

-- humidity, temperature, pressure, air quality index,
-- UV index, particle densithy,picture
DROP TABLE IF EXISTS data;
-- CREATE TABLE data(
-- 	id int(3) NOT NULL DEFAULT 0,
-- 	time DECIMAL(6,3) NOT NULL DEFAULT 0.00
-- );
CREATE TABLE IF NOT EXISTS data (
	id INT NOT NULL AUTO_INCREMENT,
	timestamp TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
	humidity DECIMAL(6,3) NOT NULL DEFAULT 0.00,
	temperature DECIMAL(6,3) NOT NULL DEFAULT 0.00,
	pressure DECIMAL(7,3) NOT NULL DEFAULT 0.00,
	airqualityindex DECIMAL(6,3) NOT NULL DEFAULT 0.00,
       	uvindex DECIMAL(6,3) NOT NULL DEFAULT 0.00,
	particledensity DECIMAL(6,3) NOT NULL DEFAULT 0.00,
	image VARCHAR(20) NOT NULL DEFAULT 'IMG NOT FOUND',
	PRIMARY KEY (id)
);

DROP USER IF EXISTS 'pi'@'localhost';
CREATE USER 'pi'@'localhost' IDENTIFIED BY 'pass';
GRANT ALL PRIVILEGES ON weatherDB.* TO 'pi'@'localhost';
