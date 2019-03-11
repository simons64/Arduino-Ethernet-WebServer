#include "webserver_files.h"  

// wegen )"; aufpassen wegen Ende von R"(
// bei Funktionsaufrufen GetArduinoIO() " <- Leerzeichen


const char *myscript_js = R"( 
function myFunction() {
  alert("url ohne F5 aendern ");
  window.history.pushState('page2', 'Title', '/test_url');
}
)";
