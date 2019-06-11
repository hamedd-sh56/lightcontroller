const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<body>
<div class="res">
  <center>
  <div id="demo">
  <h1>The ESP8266 Light control</h1>
    <h4>V 0.5</h4>
     <button class="sb" type="button" onclick="sendData(1)">ON</button>
    <button class="sb" type="button" onclick="sendData(0)">OFF</button><BR>
  </div>
<br>
<br>
<div class="state">
  ADC Value is : <span id="ADCValue">0</span><br>
  LED State is : <span id="LEDState">NA</span>
</div>
</center>
</div>
<script>
function sendData(led) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("LEDState").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "setLED?LEDstate="+led, true);
  xhttp.send();
}

setInterval(function() {
  // Call a function repetatively with 2 Second interval
  getData();
}, 2000); //2000mSeconds update rate

function getData() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("ADCValue").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "readADC", true);
  xhttp.send();
}
</script>

</body>
</html>
<style>
  body{
 background-color : #33ffff;

}
  
  
  .sb{
     font-size: 5.5rem;
     border-radius: 25px;
     margin: 20px 20px ;
     }

  .res{
      font-size: 3.5rem;

  }
  .state{
    width: auto;
    font-size: 4.5rem;
    border: 2px solid;

  }  
</style>
)=====";