<?php

$file = __DIR__ . urldecode($_SERVER["REQUEST_URI"]);
error_log("uri:$file\n");

if (is_file($file)) {
	return false;
}

if (is_dir($file) && file_exists($file."/index.html")) {
	readfile($file."/index.html");
} else {
	$file = rtrim($file, "/").".html";
	if (file_exists($file)) {
		readfile($file);
	} else {
		return false;
	}
}
