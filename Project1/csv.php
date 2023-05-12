<?php
function get_html($csv_file)
{
   $html='';
   file = fopen($csv_file, 'r');
   $header_arr=fgetcsv($file);
   $html.='thead>';
   foreach($header_arr as $k=>$v)
   {
     $html.='<th>'.$v.'</th>';
   }
   $html.='<thead>';
   $html.='<tbody>';
   while($line = fgetcsv($file ))
   {
    $html.='<tr>';
    foreach($line_arr as $k=>$v)
   {
     $html.='<td>'.$v.'</td>';
   }
    $html.='</tr>';
   }
   $html.='</tbody>';
   $html.='</table>';
   return $html;
}
echo get_html('C:\Users\manor\Documents\CPS 3525\uploads\student_roster1.csv';)
?>