# Arduino Thermostat

Source Code written by Henry Hall.

# How To Upload:

1. Download the ZIP Folder and extract it.
2. Open PlaformIO Home in VSCode.
3. Click "Import Project"
4. Select the board you wish to use.
5. Navigate to the correct directory of where your unzipped folder is.
6. Click "Import"
7. If import is successful, go to the "src" folder and find "main.cpp" (it shouldn't be hard, its the only file there)
8. Go to the bottom of the window, and click the upload button.

Done!

PlatformIO should automatically find the COM Port, and the Arduino Thermostat code will be uploaded.

# Changing the pins

If you wish to change which pins the heating/cooling devices are on, just find the lines:

const int heatPin = 0;  
const int coolPin = 1;

And change the pins respectively.  
To change the pin of which the DHT11 sensor is on, or the DHT Type, just edit these lines of code respectively:

#define DHTPIN 12

#define DHTTYPE DHT11
