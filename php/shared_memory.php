<?php
$mem = new SyncSharedMemory("rfcomm_client", 4096);
if ($mem->first()){
    // Do first time initialization work here.
}
$result = $mem->write("report.txt");
$result = $mem->read(3, -4);
?>
