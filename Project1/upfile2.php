<?php
$target_dir = "upload/";
$target_file = $target_dir . basename($_FILES["fileToUpload"]["name"]);
$uploadOk = 1;
$imageFileType = strtolower(pathinfo($target_file,PATHINFO_EXTENSION));

// Check if image file is a actual image or fake image
if(isset($_POST["submit"])) {
    $mimes = array('application/vnd.ms-excel','text/plain','text/csv','text/tsv');

//   if(in_array($_FILES['fileToUpload']['type'],$mimes)) {
//     echo "File is of csv type- ";
//     $uploadOk = 1;
//   } else {
//     echo "Invalid file.";
//     $uploadOk = 0;
//   }
}

// Check if file already exists
#if (file_exists($target_file)) {
 # echo "Sorry, file already exists.";
 # $uploadOk = 0;
#}

// Check file size
if ($_FILES["fileToUpload"]["size"] > 50000 || $_FILES["fileToUpload"]["size"] < 10) {
  echo "File size needs to be between 10 bytes or 50,000 bytes. <br>";
  $uploadOk = 0;
}

// Check if $uploadOk is set to 0 by an error
if ($uploadOk == 0) {
  echo "Sorry, your file was not uploaded. <br>";
// if everything is ok, try to upload file
} 

// if uploadOk=1 then try to upload file
else {
    //saving tmp file info
     $temp_info = $_FILES["fileToUpload"]["tmp_name"];
    //  $_FILES["file"]["tmp_name"] implies storage path
    //in tmp directory which is moved to uploads
     //directory using move_uploaded_file() method
    if (move_uploaded_file($_FILES["fileToUpload"]["tmp_name"], $target_file)) {
        
        echo "Filetype: " . mime_content_type($target_file) . "<br>";
        echo "Temp Filepath: $temp_info <br> ";
        echo "Filepath: $target_file <br>";
        echo "Filesize: " . filesize($target_file) . " bytes<br>";
        echo "The file: " . basename($target_file) . " has been successfully uploaded.<br>";
    }
}
?>