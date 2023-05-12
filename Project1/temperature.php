<?php

$temperature = 0;
// IP address 
$userIP = '162.222.198.75'; 
$userIP = $_SERVER['REMOTE_ADDR'];
 
// API end URL 
$apiURL = 'https://freegeoip.app/json/'.$userIP; 
 
// Create a new cURL resource with URL 
$ch = curl_init($apiURL); 
 
// Return response instead of outputting 
curl_setopt($ch, CURLOPT_RETURNTRANSFER, true); 
 
// Execute API request 
$apiResponse = curl_exec($ch); 
 
// Close cURL resource 
curl_close($ch); 
 
// Retrieve IP data from API response 
$ipData = json_decode($apiResponse, true); 

if(!empty($ipData)){ 
    $country_code = $ipData['country_code']; 
    $country_name = $ipData['country_name']; 
    $region_code = $ipData['region_code']; 
    $region_name = $ipData['region_name']; 
    $city = $ipData['city']; 
    $zip_code = $ipData['zip_code']; 
    $latitude = $ipData['latitude']; 
    $longitude = $ipData['longitude']; 
    $time_zone = $ipData['time_zone']; 
     
    echo 'Country Name: '.$country_name.'<br/>'; 
    echo 'Country Code: '.$country_code.'<br/>'; 
    echo 'Region Code: '.$region_code.'<br/>'; 
    echo 'Region Name: '.$region_name.'<br/>'; 
    echo 'City: '.$city.'<br/>'; 
    echo 'Zipcode: '.$zip_code.'<br/>'; 
    echo 'Latitude: '.$latitude.'<br/>'; 
    echo 'Longitude: '.$longitude.'<br/>'; 
    echo 'Time Zone: '.$time_zone; 
}else{ 
    echo 'IP data is not found!'; 
} 
 
?>