#include "webserver_files.h" 

// wegen )"; aufpassen wegen Ende von R"(
// bei Funktionsaufrufen GetArduinoIO() " <- Leerzeichen


const char *index_htm = R"(<!DOCTYPE html>
<html>
    <head>
        <link rel="icon" href="data:;base64,iVBORw0KGgo=">
        <title>Arduino Ajax I/O</title>
        <script>
  </script>
  <style>
    .IO_box {
      float: left;
      margin: 0 20px 20px 0;
      border: 1px solid blue;
      padding: 0 5px 0 5px;
      width: 120px;
    }
    h1 {
      font-size: 120%;
      color: blue;
      margin: 0 0 10px 0;
    }
    h2 {
      font-size: 85%;
      color: #5734E6;
      margin: 5px 0 5px 0;
    }
    p, form, button {
      font-size: 80%;
      color: #252525;
    }
    .small_text {
      font-size: 70%;
      color: #737373;
    }
  </style>
    </head>
    <body onload="GetArduinoIO() ">
        <h1>Arduino Ajax I/O</h1>
        <div class="IO_box">
      <h2>Analog Inputs</h2>
      <p class="small_text">A0 used by Ethernet shield</p>
      <p class="small_text">A1 used by Ethernet shield</p>
      <p>A2: <span class="analog">...</span></p>
      <p>A3: <span class="analog">...</span></p>
      <p>A4: <span class="analog">...</span></p>
      <p>A5: <span class="analog">...</span></p>
    </div>
    <div class="IO_box">
      <h2>Switch Inputs</h2>
      <p class="small_text">D0: used by serial RX</p>
      <p class="small_text">D1: used by serial TX</p>
      <p>Switch 1 (D2): <span class="switches">...</span></p>
      <p>Switch 2 (D3): <span class="switches">...</span></p>
      <p class="small_text">D4: used by Ethernet shield</p>
      <p>Switch 3 (D5): <span class="switches">...</span></p>
    </div>
    <div class="IO_box">
      <h2>LEDs Using Checkboxes</h2>
      <form id="check_LEDs" name="LED_form">
        <input type="checkbox" name="LED1" value="0" onclick="GetCheck" />LED 1 (D6)<br /><br />
        <input type="checkbox" name="LED2" value="0" onclick="GetCheck" />LED 2 (D7)<br /><br />
      </form>
    </div>
    <div class="IO_box">
      <h2>LEDs Using Buttons</h2>
      <button type="button" id="LED3" onclick="GetButton1">LED 3 is OFF</button><br /><br />
      <button type="button" id="LED4" onclick="GetButton2">LED 4 is OFF</button><br /><br />
      <p class="small_text">D10 to D13 used by Ethernet shield</p>
    </div>
  <div class="IO_box">
    <h2>submit test</h2>
    <input type="button" onclick="myFunction() " name="dicker button" value="test" />
    </div>
  </body>
</html>
<script src="ajax_script.js"></script>
<script src="myscripts.js"></script>
)";
