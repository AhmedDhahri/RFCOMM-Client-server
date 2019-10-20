<?php
	$json_file = file_get_contents("../file_array.json","r");
	$json_array = json_decode($json_file, true);
	$size = count($json_array);
	for($i = 1; $i < $size; $i++){
		echo $json_array[$i]["id"];echo "- ";echo $json_array[$i]["name"];
		echo "\n";
	}
?>
