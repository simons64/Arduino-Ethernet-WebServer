 #include "webserver_files.h"  

// wegen )"; aufpassen wegen Ende von R"(
// bei Funktionsaufrufen GetArduinoIO() " <- Leerzeichen


const char *ajax_script_js = R"(     
    strLED1 = "";
    strLED2 = "";
    strLED3 = "";
    strLED4 = "";
    var LED3_state = 0;
    var LED4_state = 0;
    function GetArduinoIO()
    {
      nocache = "&nocache=" + Math.random() * 1000000;
      var request = new XMLHttpRequest();
      request.onreadystatechange = function()
      {
        if (this.readyState == 4) {
          if (this.status == 200) {
            if (this.responseXML != null) {
              // XML file received - contains analog values, switch values and LED states
              var count;
              // get analog inputs
              var num_an = this.responseXML.getElementsByTagName('analog').length;
              for (count = 0; count < num_an; count++) {
                document.getElementsByClassName("analog")[count].innerHTML =
                  this.responseXML.getElementsByTagName('analog')[count].childNodes[0].nodeValue;
              }
              // get switch inputs
              var num_an = this.responseXML.getElementsByTagName('switch').length;
              for (count = 0; count < num_an; count++) {
                document.getElementsByClassName("switches")[count].innerHTML =
                  this.responseXML.getElementsByTagName('switch')[count].childNodes[0].nodeValue;
              }
              // LED 1
              if (this.responseXML.getElementsByTagName('LED')[0].childNodes[0].nodeValue === "checked") {
                document.LED_form.LED1.checked = true;
              }
              else {
                document.LED_form.LED1.checked = false;
              }
              // LED 2
              if (this.responseXML.getElementsByTagName('LED')[1].childNodes[0].nodeValue === "checked") {
                document.LED_form.LED2.checked = true;
              }
              else {
                document.LED_form.LED2.checked = false;
              }
              // LED 3
              if (this.responseXML.getElementsByTagName('LED')[2].childNodes[0].nodeValue === "on") {
                document.getElementById("LED3").innerHTML = "LED 3 is ON";
                LED3_state = 1;
              }
              else {
                document.getElementById("LED3").innerHTML = "LED 3 is OFF";
                LED3_state = 0;
              }
              // LED 4
              if (this.responseXML.getElementsByTagName('LED')[3].childNodes[0].nodeValue === "on") {
                document.getElementById("LED4").innerHTML = "LED 4 is ON ";
                LED4_state = 1;
              }
              else {
                document.getElementById("LED4").innerHTML = "LED 4 is OFF";
                LED4_state = 0;
              }
            }
          }
        }
      }
      // send HTTP GET request with LEDs to switch on/off if any
      request.open("GET", "ajax_inputs" + strLED1 + strLED2 + strLED3 + strLED4 + nocache, true);
      request.send(null);
      //setTimeout('GetArduinoIO()', 1000);
      strLED1 = "";
      strLED2 = "";
      strLED3 = "";
      strLED4 = "";
    }
    // service LEDs when checkbox checked/unchecked
    function GetCheck()
    {
      if (LED_form.LED1.checked) {
        strLED1 = "&LED1=1";
      }
      else {
        strLED1 = "&LED1=0";
      }
      if (LED_form.LED2.checked) {
        strLED2 = "&LED2=1";
      }
      else {
        strLED2 = "&LED2=0";
      }
    }
    function GetButton1()
    {
      if (LED3_state === 1) {
        LED3_state = 0;
        strLED3 = "&LED3=0";
      }
      else {
        LED3_state = 1;
        strLED3 = "&LED3=1";
      }
    }
    function GetButton2()
    {
      if (LED4_state === 1) {
        LED4_state = 0;
        strLED4 = "&LED4=0";
      }
      else {
        LED4_state = 1;
        strLED4 = "&LED4=1";
      }
    }
)";
