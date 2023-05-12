<?php
$target_dir = "upload/";
$target_file = $target_dir . basename($_FILES["fileToUpload"]["name"]);
$uploadOk = 1;
$imageFileType = strtolower(pathinfo($target_file,PATHINFO_EXTENSION));

if(isset($_POST["submit"])) {
    $mimes = array('application/vnd.ms-excel','text/plain','text/csv','text/tsv');


}


if ($_FILES["fileToUpload"]["size"] > 50000 || $_FILES["fileToUpload"]["size"] < 10) {
  echo "File size needs to be between 10 bytes or 50,000 bytes. <br>";
  $uploadOk = 0;
}


if ($uploadOk == 0) {
  echo "Sorry, your file was not uploaded. <br>";

} 


else {
    
     $temp_info = $_FILES["fileToUpload"]["tmp_name"];
   
    if (move_uploaded_file($_FILES["fileToUpload"]["tmp_name"], $target_file)) {
        
        echo "Filetype: " . mime_content_type($target_file) . "<br>";
        echo "Temp Filepath: $temp_info <br> ";
        echo "Filepath: $target_file <br>";
        echo "Filesize: " . filesize($target_file) . " bytes<br>";
        echo "The file: " . basename($target_file) . " has been successfully uploaded.<br>";
    



        $csv = array();
        $lines = file($target_file, FILE_IGNORE_NEW_LINES);
        foreach ($lines as $key => $value) {
            $csv[$key] = str_getcsv($value);
        }
        $max_col = max(array_map('count', $csv));
        if($max_col == 4){
            unset($csv[0]); 
            $csv = array_values($csv);
            
            
            $m_tot1 = total_avg($csv, 1);
            $m_tot2 = total_avg($csv, 2);
            $m_tot3 = total_avg($csv, 3);
            $total_row_arr = total_row_avg_arr($csv);
            echo "
                <p>Original Table</p>         
                <table border = 1>
                <thead>
                <tr>
                <th>#</th>
                <th>Name</th>
                <th>Math</th>
                <th>Science</th>
                <th>English</th>
                <th>AVG</th>
                <tr>
                </thead>
                <tfoot>
                <th colspan=2>AVG</th>
                <th>" . $m_tot1 . "</th>
                <th>" . $m_tot2 . "</th>
                <th>" . $m_tot3 . "</th>
                 <th>" . number_format(($m_tot1 + $m_tot2 + $m_tot3) / 3, 1) .  "</th>
                <tbody>";
                $num = 1;
                foreach($csv as $p) {
                    echo"
                    <tr>
                    <td>$num</td>
                    <td>$p[0]</td>
                    <td>$p[1]</td>
                    <td>$p[2]</td>
                    <td>$p[3]</td>
                    <td>". $total_row_arr[$num-1] ." </td>        
                    </tr>
                    "; 
                    $num = $num+1; 
                }
            echo "
            </tbody>
            </table>";

            $arr_mrg2 = merge_array_on_index($csv, $total_row_arr);
            $arr_sorted = array_multisort(array_map(function($element){
                return $element[4];
            },$arr_mrg2), SORT_DESC, $arr_mrg2);

            $sorted_col_tol1 = total_avg($arr_mrg2, 1);
            $sorted_col_tol2 = total_avg($arr_mrg2, 2);
            $sorted_col_tol3 = total_avg($arr_mrg2, 3);

            $subject = 0;

            if($_POST["subject"] != "All") {
                $subject = 0;
                switch($_POST["subject"]) {
                    case "Math":
                    $subject = 1;
                    array_multisort(array_map(function($element){
                    return $element[1];
                    },$arr_mrg2), SORT_DESC, $arr_mrg2);
                    break;
                    case "Science":
                    $subject = 2;
                    array_multisort(array_map(function($element){
                    return $element[2];
                    },$arr_mrg2), SORT_DESC, $arr_mrg2);
                    break;
                    case "English":
                    $subject = 3;
                    array_multisort(array_map(function($element){
                    return $element[3];
                    },$arr_mrg2), SORT_DESC, $arr_mrg2);
                    break;
                }

                echo "
                    <p>Sorting Table by subject: ".$_POST["subject"]." </p>         
                    <table border = 1>
                    <thead>
                    <tr>
                    <th>#</th>
                    <th>Name</th>
                    <th>" . $_POST["subject"]. "</th>
                    <th>AVG</th>
                    <tr>
                    </thead>
                    <tfoot>
                    <th colspan=2>AVG</th>
                    <th>" . total_avg($arr_mrg2, $subject) . "</th>
                    <th>" . total_avg($arr_mrg2, $subject) . "</th>
                    <tbody>";
                    $num = 1; 
                        foreach($arr_mrg2 as $p) {
                            echo"
                            <tr>
                                <td>$num</td>
                                <td>$p[0]</td>
                                <td>$p[$subject]</td>
                                <td>" . number_format($p[$subject],1) . "</td>
                                
                            </tr>
                            "; 
                            $num = $num+1; 
                        }
                echo "
                </tbody>
                </table>
                        
                ";
            }
            else if($_POST["subject"] = "All"){

                echo "
                <p>Sorting Table by subject: ".$_POST["subject"]." </p>         
                <table border = 1>
                <thead>
                <tr>
                <th>#</th>
                <th>Name</th>
                <th>Math</th>
                <th>Science</th>
                <th>English</th>
                <th>AVG</th>
                <tr>
                </thead>
                <tfoot>
                <th colspan=2>AVG</th>
                <th>" . $sorted_col_tol1 . "</th>
                <th>" . $sorted_col_tol2 . "</th>
                <th>" . $sorted_col_tol3 . "</th>
                 <th>" . number_format(($sorted_col_tol1 + $sorted_col_tol2 + $sorted_col_tol3) / 3, 1) .  "</th>
                <tbody>";
                $num = 1;
                foreach($arr_mrg2 as $p) {
                    echo"
                    <tr>
                    <td>$num</td>
                    <td>$p[0]</td>
                    <td>$p[1]</td>
                    <td>$p[2]</td>
                    <td>$p[3]</td>
                    <td>$p[4]</td>

                    </tr>
                    "; 
                    $num = $num+1; 
                }
            echo "
            </tbody>
            </table>";
            }
                

        } else {
            echo "Cannot upload. Please correct number of columns";
        }
        

            
        
    }    
}
function total_avg($arr, int $x) {
    $sum = array_sum(array_column($arr, $x));
    $div = count($arr); 
    return number_format($sum/$div, 1);
}

function total_row_avg_arr ($arr) {
    $x=0;
    for($x; $x < count($arr); $x++) {
        unset($arr[$x][0]); //removes all 
        $sum = array_sum($arr[$x]);
        $div = count($arr[$x]); 
        $row_arr[$x] = number_format($sum/$div, 1);
    }
    return $row_arr;
}

function total_row_avg ($arr, int $x) {
    unset($arr[$x][0]); 
    $sum = array_sum($arr[$x]);
    $div = count($arr[$x]); 
    return number_format($sum/$div, 1);
}


function merge_array_on_index ($x, $y) {
    $arr1 = $x;
    $arr2 = $y;
    for($x = 0; $x < count($arr1); $x++) {
        $arr1[$x][] = $arr2[$x];
    }
    return $arr1; 
}

?>