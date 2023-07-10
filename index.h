const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.3.0/css/all.min.css">
<style>
.card{
     background: #02b875;
     padding: 30px;
     box-sizing: border-box;
     color: #FFF;
     margin:20px;
     box-shadow: 0px 2px 18px -4px rgba(0,0,0,0.75);
     font-size:60px;
     font-weight:bold;
}
</style>
<body>

<div class="card">
  <label style="color:yellow">IoT Based Water Quality Measurement</label><br><br>
  <i class="fas fa-faucet-drip fa-3x"></i>&nbsp;<label style="color:black">Turbidity Value: <span id="turbidity" style="color:white"></span></label><br>
  <i class="fas fa-tint fa-3x"></i>&nbsp;<label style="color:black">TDS Value: <span id="tds" style="color:white"></span></label><br>
  <i class="fa-solid fa-temperature-high fa-3x"></i>&nbsp;<label style="color:black">Temperature: </label><span id="temp" style="color:white"></span><label style="color:white">&deg;C</label><br>
  <i class="fa-solid fa-glass-water fa-3x"></i>&nbsp;<label style="color:black">Is Drinkable: <span id="isDrinkable" style="color:white"></span></label><br>
</div>
<script>

setInterval(function() {
  // Call a function repetatively with 2 Second interval
  getTurbidity();
  getTDS();
  isDrinkable();
  getTempr();
}, 1000); //2000mSeconds update rate

function getTurbidity() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("turbidity").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "readTurbidity", true);
  xhttp.send();
}

function getTDS() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("tds").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "readTds", true);
  xhttp.send();
}

function isDrinkable() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("isDrinkable").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "readIsDrinkable", true);
  xhttp.send();
}

function getTempr() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("temp").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "readTemp", true);
  xhttp.send();
}

</script>
</body>
</html>
)=====";
