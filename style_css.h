#include <Arduino.h>

const char style_css[] PROGMEM = R"=====(
* {
    font-family: 'Source Code Pro', UltimaPro, Verdana, Arial, sans-serif;
    color: DarkSlateGrey;
    vertical-align: baseline;
    box-sizing: border-box;
}
.clearfix {
    overflow: auto;
}
.clearfix::before,
.clearfix::after {
    content: "";
    display: table;
} 
.clearfix::after {
    clear: both;
}
body {
    margin: 0px;
    padding: 0px;
    max-width: 100%;
    color: #4a4a4a;
    font-weight: 400;
    line-height: 1.5;
    font-size: 1.0em;
}
html {
    margin: 0px;
    padding: 0px;
    max-width: 100%;
    color: #4a4a4a;
    font-weight: 400;
    line-height: 1.5;
    font-size: 1.0em;
}
.navBar {
    margin: 0;
    padding: 0;
    background-color: white;
    z-index: 1;
    box-shadow: 0 .5em .5em -.125em rgba(10, 10, 10, .1), 0 0 0 1px rgba(10, 10, 10, .02);
    overflow: hidden;
    position: fixed;
    width: 100%;
    top: 0px;
    line-height: 35px;
    vertical-align: bottom;
    font-size: 1.2em;
}
.navBar a {
    float: left;
    display: block;
    color: slategray;
    text-align: center;
    padding: 0px 10px;
    text-decoration: none;
    -webkit-tap-highlight-color: rgba(200, 0, 0, 0.4);
    border-radius: 5px;
    margin: 18px 10px;
}
.navBar a:hover:not(.active) {
    background-color: #245BA9;
    color: white;
}
.navBar a.active {
    background-color: slategray;
    color: white;
}
.navBar .title {
    float: right;
    color: slategray;
    z-index: 10000;
    padding-right: 20px;
    background-color: transparent;
    margin: 18px 10px;
}
.navBar .icon {
    display: none;
}
header:after {
    content: "";
    display: table;
    clear: both;
    margin-top: 20px;
}
section:first-of-type {
    margin: 100px 0 10px 0;
}
section:after {
    content: "";
    display: table;
    clear: both;
    margin-top: 30px;
}
section {
    margin: 0px auto;
    text-align: center;
}
#box { 
    margin: 0px auto;
    text-align: left;
	width: 35%;
	min-height: 25rem; 
	background-color: slategray; 
	color: white; 
	font-family: monospace; 
	padding: 10px; 
}
#jsonspan {
	color: white; 
	font-family: monospace; 
	text-align: left; 
	white-space: nowrap; 
	padding-left: 20px;
}
.string { color: yellow; }
.number { color: orange; }
.boolean { color: red; }
.null { color: magenta; }
.key { color: white; }
.quotes { color: black; }
.colon { color: cyan; }
)=====";