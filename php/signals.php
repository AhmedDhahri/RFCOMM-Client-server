<?php
$proc = "rfcomm_client";
exec("pgrep rfcomm_client",$out);
posix_kill ($out[0], SIGCONT);
?>
