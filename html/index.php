<html>
	<header>
		<title>Weather Station</title>
		<h1>Pi Weather Station</h1>
		<?php header("refresh: 10");  ?>
	</header>
	<div><img src="sky.jpeg"></div>
<body>	
	<div>
		<h1>Humidity</h1>
		<?php include 'humidityValue.html';?>
		<img src="humidity.png"></div>
	</div>

	<div>
		<h1>Temperature</h1>
		<?php include 'temperatureValue.html';?>
		<img src="temperature.png"></div>
	</div>

	<div>
		<h1>Pressure</h1>
		<?php include 'pressureValue.html';?>
		<img src="pressure.png"></div>
	</div>

	<div>
		<h1>UV Intensity</h1>
		<?php include 'uvValue.html';?>
		<img src="uvindex.png"></div>
	</div>

	<div>
		<h1>Gas resistance</h1>
		<?php include 'gasValue.html';?>
		<img src="airqualityindex.png"></div>
	</div>

	<div>
		<h1>Particle density</h1>
		<?php include 'particleValue.html';?>
		<img src="particledensity.png"></div>
	</div>

	<?php include 'footer.html';?>
</body>
</html>
