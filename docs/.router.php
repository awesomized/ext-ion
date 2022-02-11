<?php

$uri = urldecode($_SERVER["REQUEST_URI"]);

if (strpos($uri, "/ext-ion") === 0) {
    $uri = substr($uri, strlen("/ext-ion"));
}
$file = rtrim(__DIR__ . $uri, "/");
if (is_file($file)) {
    switch (pathinfo($file, PATHINFO_EXTENSION)) {
        case "js":  header("content-type: text/javascript"); break;
        case "css": header("content-type: text/css"); break;
        case "php":
        case "": header("content-type: text-plain"); break;
    }
	readfile($file);
} elseif (is_dir($file) && file_exists("$file/index.html")) {
	readfile("$file/index.html");
} else {
	$file .= ".html";
	if (file_exists($file)) {
		readfile($file);
	} else {
		return false;
	}
}
