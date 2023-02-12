#include <Arduino.h>

// str = str.replace(/,/g, '<br/>').replace(/\\/g, '');
// var jsonPretty = JSON.stringify(JSON.parse(jsonString),null,2);
// https://codepen.io/adrianparr/pen/VeyeVP

// 	<!-- center><textarea name="" id='json' cols='30' rows='10'></textarea></center /-->
// 			document.getElementById('json').value = str;


const char index_html[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="de">
<head>
	<title>Growatt Solar Inverter to MQTT Gateway (modbus)</title>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0, user-scalable=no">
	<meta name="theme-color" content="#ffffff">	
	<link rel="stylesheet" type="text/css" href="style.css"/>
</head>    
<body>
<header>
	<nav>
		<div class="navBar" id="mainNavBar">
		<span class="title">Growatt Solar Inverter to MQTT Gateway (modbus)</span>
	</nav>
</header>
<section>
	<div id='box'><pre id='jsonspan'>&nbsp;</pre></div>
	<!-- button onclick="copy2clip(document.getElementById('jsonspan').innerHTML)">clip</button /-->
</section>
</body>
<script>
setInterval(function() { getData(); }, 1000);
function copy2clip(text) {
	//var copyText = document.getElementById("jsonspan").innerHTML;
}
function syntaxHighlight(json) {
    json = json.replace(/&/g, '&amp;').replace(/</g, '&lt;').replace(/>/g, '&gt;').replace(/:/g, ' : ');
    return json.replace(/("(\\u[a-zA-Z0-9]{4}|\\[^u]|[^\\"])*"(\s*:)?|\b(true|false|null)\b|-?\d+(?:\.\d*)?(?:[eE][+\-]?\d+)?)/g, function (match) {
        var cls = 'number';
        if (/^"/.test(match)) {
            if (/:$/.test(match)) {
                cls = 'key';
            } else {
                cls = 'string';
            }
        } else if (/true|false/.test(match)) {
            cls = 'boolean';
        } else if (/null/.test(match)) {
            cls = 'null';
        }
        return '<span class="' + cls + '">' + match + '</span>';
    });
}
function getData() {
	var xhttp = new XMLHttpRequest();
	xhttp.onreadystatechange = function() {
	if (this.readyState == 4 && this.status == 200) {
		var str = JSON.stringify(this.responseText, null, 4);
		console.log(str);
		var result = str.slice(1,-1);
		coloredstr = syntaxHighlight(result.replace(/\\/g, '')).replace(/{/g, '').replace(/}/g, '').replace(/\\/g, '').replace(/,/g, '<br />');
		console.log(coloredstr);
		if (result.length > 14 ) {
			document.getElementById('jsonspan').innerHTML = coloredstr;
		}
	}
	};
	xhttp.open('GET', 'states', true);
	xhttp.send();	
}
</script>
</html>
)=====";