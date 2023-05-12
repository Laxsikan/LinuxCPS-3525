<?php

// Establish connection to the database
$db = new mysqli('localhost', 'username', 'password', 'my_db');

// Create a query to get the data from both the images and geo tables
$query = "SELECT i.image_id, i.image_name, g.geo_id, g.geo_name 
          FROM images i 
          INNER JOIN geo g ON i.geo_id = g.geo_id";

// Execute the query
$result = $db->query($query);

// Loop through the results and output
while ($row = $result->fetch_assoc()) {
    echo 'Image ID: ' . $row['image_id'] . ' | ';
    echo 'Image Name: ' . $row['image_name'] . ' | ';
    echo 'Geo ID: ' . $row['geo_id'] . ' | ';
    echo 'Geo Name: ' . $row['geo_name'] . '<br>';
}

// Close the connection
$db->close();

?>