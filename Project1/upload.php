<?php
echo '<br/>The fileToUpload1.jpg,  fileToUpload2.jpg have been successfully uploaded.Image contains headers';
echo '<br/>';
echo '<br/>';

$image_file =$_FILES['fileToUpload1'];


$exit = pathinfo($image_file['name'], PATHINFO_EXTENSION);
$tmp =$_FILES['fileToUpload1']['tmp_name'];
$target_dir = "uploads/";
$target_file = $target_dir . basename($_FILES["fileToUpload1"]["name"]);
$fileopen = fopen($tmp, 'r');


$exif = array();
$exif = exif_read_data($tmp, 0, true);
$size = $exif["FILE"]["FileSize"];
$height = $exif["COMPUTED"]["Height"];
$width = $exif["COMPUTED"]["Width"];
$brand = $exif["IFD0"]["Make"];
$model = $exif["IFD0"]["Model"];
$orientation = $exif["IFD0"]["Orientation"];
$exiff = $exif["EXIF"]["ExposureTime"];
$exifversion = ( isset($exif["EXIF"]["ExifVersion"]) ? $exif["EXIF"]["ExifVersion"] : '');
$exifaperture = ( isset($exif["EXIF"]["ApertureValue"]) ? $exif["EXIF"]["ApertureValue"] : '');
$exifmeter = ( isset($exif["EXIF"]["MeteringMode"]) ? $exif["EXIF"]["MeteringMode"] : '');
$focallength = ( isset($exif["EXIF"]["FocalLength"]) ? $exif["EXIF"]["FocalLength"] : '');
$latitude = ( isset($exif["GPS"]["GPSLatitudeRef"]) ? $exif["GPS"]["GPSLatitudeRef"] : '');
$longitude = ( isset($exif["GPS"]["GPSLongitudeRef"]) ? $exif["GPS"]["GPSLongitudeRef"] : '');
$date_time = ( isset($exif["IFD0"]["DateTime"]) ? $exif["IFD0"]["DateTime"] : '');
$city=( isset($exif["IFD0"]["City"]) ? $exif["IFD0"]["City"] : '');
$state=( isset($exif["IFD0"]["State"]) ? $exif["IFD0"]["State"] : '');
$direction = ( isset($exif["GPS"]["GPSImgDirection"]) ? $exif["GPS"]["GPSImgDirection"] : '');
$altitude = ( isset($exif["GPS"]["GPSAltitude"]) ? $exif["GPS"]["GPSAltitude"] : '');
$avg_sea_level = '0'; 
$lat1 = $exif["GPS"]['GPSLatitude'];
$lon1 = $exif["GPS"]['GPSLongitude'];


print_r($exif);

/*$imgLocation = get_image_location($tmp);
$imgLat = $imgLocation['latitude'];
$imgLng = $imgLocation['longitude'];
echo "$imgLat";
echo "$imgLng";
*/




echo "<br>Size: " . $size . "";
echo "<br>Height: " . $height . "";
echo "<br>Width: " . $width . "";
echo "<br>Make: " . $brand . "";
echo "<br>Model: " . $model . "";
echo "<br>EXIF Version: " . $exifversion . "";
echo "<br>Aperture: " . $exifaperture . "";
echo "<br>MeteringMode: " . $exifmeter . "";
echo "<br>Focal length: " . $focallength . "";
echo "<br>ExposureTime: " . $exiff . "";
echo "<br>Orientation: " . $orientation . "";
echo "<br>Latitude: " . $latitude . "";
echo "<br>Longitude: " . $longitude . "";
echo "<br>DateTime: " . $date_time . "";
echo "<br>Direction: " . $direction ."";
echo "<br>Altitude: " .$altitude . "";
echo "<hr>";


echo '<br/>';
echo '<br/>';
echo '<br/>';

$image_file =$_FILES['fileToUpload2'];
$exit = pathinfo($image_file['name'], PATHINFO_EXTENSION);
$tmp =$_FILES['fileToUpload2']['tmp_name'];
$target_dir = "uploads/";
$target_file = $target_dir . basename($_FILES["fileToUpload2"]["name"]);
$fileopen = fopen($tmp, 'r');

$exif = array();
$exif = exif_read_data($tmp, 0, true);
$size = $exif["FILE"]["FileSize"];
$height = $exif["COMPUTED"]["Height"];
$width = $exif["COMPUTED"]["Width"];
$brand = $exif["IFD0"]["Make"];
$model = $exif["IFD0"]["Model"];
$orientation = $exif["IFD0"]["Orientation"];
$exiff = $exif["EXIF"]["ExposureTime"];
$exifversion = ( isset($exif["EXIF"]["ExifVersion"]) ? $exif["EXIF"]["ExifVersion"] : '');
$exifaperture = ( isset($exif["EXIF"]["ApertureValue"]) ? $exif["EXIF"]["ApertureValue"] : '');
$exifmeter = ( isset($exif["EXIF"]["MeteringMode"]) ? $exif["EXIF"]["MeteringMode"] : '');
$focallength = ( isset($exif["EXIF"]["FocalLength"]) ? $exif["EXIF"]["FocalLength"] : '');
$latitude2 = ( isset($exif["GPS"]["GPSLatitude"]) ? $exif["GPS"]["GPSLatitude"] : '');
$longitude2 = ( isset($exif["GPS"]["GPSLongitude"]) ? $exif["GPS"]["GPSLongitude"] : '');
$date_time = ( isset($exif["IFD0"]["DateTime"]) ? $exif["IFD0"]["DateTime"] : '');
$city=( isset($exif["IFD0"]["City"]) ? $exif["IFD0"]["City"] : '');
$state=( isset($exif["IFD0"]["State"]) ? $exif["IFD0"]["State"] : '');
$direction2 = ( isset($exif["GPS"]["GPSImgDirection"]) ? $exif["GPS"]["GPSImgDirection"] : '');
$altitude2 = ( isset($exif["GPS"]["GPSAltitude"]) ? $exif["GPS"]["GPSAltitude"] : '');
$avg_sea_level = '0';
$lat2 = $exif["GPS"]['GPSLatitude'];
 $lon2 = $exif["GPS"]['GPSLongitude'];
$lat1=floatval($lat1);
$lat2=floatval($lat2);

$lon1=floatval($lon1);
$lon2=floatval($lon2);
$theta = $lon1 - $lon2;
$distance = (sin(deg2rad($lat1)) * sin(deg2rad($lat2))) + (cos(deg2rad($lat1)) * cos(deg2rad($lat2)) * cos(deg2rad($theta)));

$distance = acos($distance);
$distance = rad2deg($distance);
/*
$latitude = convertToDecimalDegrees($lat1);
$longitude = convertToDecimalDegrees($lon1);
$latitude2 = convertToDecimalDegrees($lat2);
$longitude2 = convertToDecimalDegrees($lon2);

*/

print_r($exif);





echo "<br>Size: " . $size . "";
echo "<br>Height: " . $height . "";
echo "<br>Width: " . $width . "";
echo "<br>Make: " . $brand . "";
echo "<br>Model: " . $model . "";
echo "<br>EXIF Version: " . $exifversion . "";
echo "<br>Aperture: " . $exifaperture . "";
echo "<br>MeteringMode: " . $exifmeter . "";
echo "<br>Focal length: " . $focallength . "";
echo "<br>ExposureTime: " . $exiff . "";
echo "<br>Orientation: " . $orientation . "";
echo "<br>Latitude: " . $latitude . "";
echo "<br>Longitude: " . $longitude . "";
echo "<br>DateTime: " . $date_time . "";
echo "<br>Direction: " . $direction ."";
echo "<br>Altitude: " .$altitude . "";
echo "<br>Distance between the two photos: " . $distance . " km\n";




echo '<br/>';
echo '<br/>';

echo '<br/>';
echo '<br/>';
function getDistanceBetweenPointsNew($latitude, $longitude, $latitude2, $longitude2, $unit = 'kilometers') {
  $theta = $longitude - $longitude2; 
$distance = (sin(deg2rad($latitude)) * sin(deg2rad($latitude2))) + (cos(deg2rad($latitude)) * cos(deg2rad($latitude2)) * cos(deg2rad($theta)));
$distance = acos($distance);
$distance = rad2deg($distance);
$distance = $distance * 60 * 1.1515;
switch ($unit) {
    case 'miles':
        break;
    case 'kilometers':
        $distance = $distance * 1.609344;
}
return $distance;
}

$point1 = array('lat' => floatval($latitude), 'long' => floatval($longitude));
$point2 = array('lat' => floatval($latitude2), 'long' => floatval($longitude2));

$distance = getDistanceBetweenPoints($point1['lat'], $point1['long'], $point2['lat'], $point2['long']);
foreach ($distance as $unit => $value) {
    echo $unit.': '.number_format($value,4).'<br />';
}
function checkFileForGeotag($filePath) {
  $exif = exif_read_data($filePath);
  if (isset($exif['GPSLatitude']) && isset($exif['GPSLongitude'])) {
    return true;
  } else {
    return false;
  }
}


function convertFractionToDecimal($fraction) {
  $parts = explode('/', $fraction);
  $numerator = $parts[0];
  $denominator = isset($parts[1]) ? $parts[1] : 1;
  $decimal = $numerator / $denominator;
  return $decimal;
}
/*
function convertToDecimalDegrees($coordinates) {
  $degrees = $coordinates[0];
  $minutes = $coordinates[1];
  $seconds = $coordinates[2];
  $decimalDegrees = (int)$degrees + ((int)$minutes / 60) + ((int)$seconds / 3600);
  return $decimalDegrees;
}
*/
if ($direction && $direction2) {
  $diff = abs((int)$direction - (int)$direction2);
  if ($diff < 45 || $diff > 315) {
    echo "<br>The two photos are facing at similar direction and possibly have overlapped view.\n";
  } else if ($diff < 135 || $diff > 225) {
    echo "<br>Although the two photos face different directions, they might have overlapped view.\n";
  } else {
    echo "<br>The two photos are facing at opposite direction and NO overlapped view.\n";
  }
} else {
  echo "<br>Unable to determine the direction of one or both photos.\n";
}

function get_image_location($image = ''){
  $exif = exif_read_data($image, 0, true);
  if($exif && isset($exif['GPS'])){
      $GPSLatitudeRef = $exif['GPS']['GPSLatitudeRef'];
      $GPSLatitude    = $exif['GPS']['GPSLatitude'];
      $GPSLongitudeRef= $exif['GPS']['GPSLongitudeRef'];
      $GPSLongitude   = $exif['GPS']['GPSLongitude'];
      
      $lat_degrees = count($GPSLatitude) > 0 ? gps2Num($GPSLatitude[0]) : 0;
      $lat_minutes = count($GPSLatitude) > 1 ? gps2Num($GPSLatitude[1]) : 0;
      $lat_seconds = count($GPSLatitude) > 2 ? gps2Num($GPSLatitude[2]) : 0;
      
      $lon_degrees = count($GPSLongitude) > 0 ? gps2Num($GPSLongitude[0]) : 0;
      $lon_minutes = count($GPSLongitude) > 1 ? gps2Num($GPSLongitude[1]) : 0;
      $lon_seconds = count($GPSLongitude) > 2 ? gps2Num($GPSLongitude[2]) : 0;
      
      $lat_direction = ($GPSLatitudeRef == 'W' or $GPSLatitudeRef == 'S') ? -1 : 1;
      $lon_direction = ($GPSLongitudeRef == 'W' or $GPSLongitudeRef == 'S') ? -1 : 1;
      
      $latitude = $lat_direction * ($lat_degrees + ($lat_minutes / 60) + ($lat_seconds / (60*60)));
      $longitude = $lon_direction * ($lon_degrees + ($lon_minutes / 60) + ($lon_seconds / (60*60)));

      return array('latitude'=>$latitude, 'longitude'=>$longitude);
  }else{
      return false;
  }
}
function gps2Num($coordPart){
  $parts = explode('/', $coordPart);
  if(count($parts) <= 0)
  return 0;
  if(count($parts) == 1)
  return $parts[0];
  return floatval($parts[0]) / floatval($parts[1]);
}

function getDistanceBetweenPoints($lat1, $lon1, $lat2, $lon2) {
  $theta = $lon1 - $lon2;
  $miles = (sin(deg2rad($lat1)) * sin(deg2rad($lat2))) + (cos(deg2rad($lat1)) * cos(deg2rad($lat2)) * cos(deg2rad($theta)));
  $miles = acos($miles);
  $miles = rad2deg($miles);
  $miles = $miles * 60 * 1.1515;
  $feet = $miles * 5280;
  $yards = $feet / 3;
  $kilometers = $miles * 1.609344;
  $meters = $kilometers * 1000;
  return compact('miles','feet','yards','kilometers','meters'); 
}
?>