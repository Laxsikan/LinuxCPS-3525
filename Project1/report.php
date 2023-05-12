<?php

$userip = $_SERVER['REMOTE_ADDR'];
$cache_file = 'data.json';
if(file_exists($cache_file)){
  $data = json_decode(file_get_contents($cache_file));
}else{
  $api_url = 'https://content.api.nytimes.com/svc/weather/v2/current-and-seven-day-forecast.json';
  $data = file_get_contents($api_url);
  
  $data = json_decode($data);
}
//$ip = $_SERVER['REMOTE_ADDR'];
 //   $ip2 = file_get_contents("https://api.ipgeolocation.io/ipgeo?apiKey=f4fbaf7e4a614b1a85e4292427fd7eb1&ip=" . $ip . "");
  //  $geo_arr = json_decode($ip2, true);

    

    

$current = $data->results->current[0];
$forecast = $data->results->seven_day_forecast;

?>
<?php

?>
<style>
  body{
    background-color:#aaa!important;
  }
  .wrapper .single{
    color:#fff;
    width:100%;
    padding:10px;
    text-align:center;
    margin-bottom:10px;
  }
  .aqi-value{
    font-family : "Noto Serif","Palatino Linotype","Book Antiqua","URW Palladio L";
    font-size:40px;
    font-weight:bold;
  }
  h1{
    text-align: center;
    font-size:3em;
  }
  .forecast-block{
  	background-color: #3b463d!important;
  	width:20% !important;
  }
  .title{
  	background-color:#673f3f;
  	width: 100%;
  	color:#fff;
  	margin-bottom:0px;
  	padding-top:10px;
  	padding-bottom: 10px;
  }
  .bordered{
  	border:1px solid #fff;
  }
  .weather-icon{
  	width:40%;
  	font-weight: bold;
  	background-color: #673f3f;
  	padding:10px;
  	border: 1px solid #fff;
  }
</style>

<?php

  function convert2cen($value,$unit){
    if($unit=='C'){
      return $value;
    }else if($unit=='F'){
      $cen = ($value - 32) / 1.8;
      	return round($cen,2);
      }
  }
?>
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/twitter-bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha256-YLGeXaapI0/5IgZopewRJcFXomhRMlYYjugPLSyNjTY=" crossorigin="anonymous" />

<div class="container wrapper">
  <br>
  
  <div class="row">
    <h3 class="title text-center bordered">Weather Report for <?php echo $current->city.','.$current->state.'('.$current->country.')';?></h3>
    <div class="col-md-12" style="padding-left:0px;padding-right:0px;">
      <div class="single bordered" style="padding-bottom:25px;background:url('back.jpg') no-repeat ;border-top:0px;background-size: cover;">
        <div class="row">
          <div class="col-sm-9" style="font-size:20px;text-align:left;padding-left:70px;">
            <p class="aqi-value"><?php echo convert2cen($current->temp,$current->temp_unit);?> °C</p>
            <p class="weather-icon">
              <img style="margin-left:-10px;" src="<?php echo $current->image;?>">
              <?php echo $current->description;?>
            </p>
            <div class="weather-icon">
              <p><strong>Wind Speed : </strong><?php echo $current->windspeed;?> <?php echo $current->windspeed_unit;?></p>
              <p><strong>Pressue : </strong><?php echo $current->pressure;?> <?php echo $current->pressure_unit;?></p>
              <p><strong>Visibility : </strong><?php echo $current->visibility;?> <?php echo $current->visibility_unit;?></p>
              <p><strong>Wind direction : </strong><?php echo $current->wind_dir;?></p>
              <p><strong>Humidity : </strong><?php echo $current->rhumid;?></p>
              
              <p><strong>Sunrise : </strong><?php echo date("D M d Y"). ', sunrise time : ' .date_sunrise(time(), SUNFUNCS_RET_STRING, 38.4, -9, 90, 1);

?></p>
             
              <p><strong>Sunset : </strong><?php echo date("D M d Y"). ', sunset time : ' .date_sunset(time(), SUNFUNCS_RET_STRING, 38.4, -9, 90, 1);?></p>
              <p><strong>Zip Code: </strong><?php echo $current->zipcode;?></p>
              <p><strong>Time Zone: </strong><?php date_default_timezone_set('America/New_York'); $script_tz = date_default_timezone_get();

if (strcmp($script_tz, ini_get('date.timezone'))){
    echo 'America/New_York';
} else {
    echo 'America/New_York';
}
?></p>
              <p><strong>IP Adress</strong><?php echo ": ".$_SERVER['REMOTE_ADDR'];?></p>
            </div>
          </div>
        </div>
          </div>
    </div>
  </div>
  <br><br>
  <div class="row">
    <h3 class="title text-center bordered">5 Days Weather Forecast for <?php echo $current->city.','.$current->state.'('.$current->country.')';?></h3>
    <?php $loop=0; foreach($forecast as $f){ $loop++;?>
      <div class="single forecast-block bordered">
        <h3><?php echo $f->day;?></h3>
        <p style="font-size:1em;" class="aqi-value"><?php echo convert2cen($f->low,$f->low_unit);?> °C - <?php echo convert2cen($f->high,$f->high_unit);?> °C</p>
        <hr style="border-bottom:1px solid #fff;">
        <img src="<?php echo $f->image;?>">
        <p><?php echo $f->phrase;?></p>
      </div>
    <?php } ?>
  </div>
</div>



