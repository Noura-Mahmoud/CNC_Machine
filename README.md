# CNC_Machine
# IOT Task_5

## Team members
| Name  | Section| BN |
| ------------- | ------------- |------------- |
|Dalia Lotfy| 01| 30|
|Marwa AbdelAal| 02| 23|
|Nada Ezzat |02 |38  |
|Noura Mahmoud |02 |39|
|Tasneem Gamal |01 |24|


## Components
* Arduino uno
* CNC sheild v3
* Servo motor
* 2 CD rooms for stepper motors

## Modes
- This CNC machine have 2 modes
### * Mode using application to draw pictures 
> install *Benbox* application first

> after opening it:
> from the last icon in the toolbar, select *Ardiuno uno* and choose *the firmware* from the application folder

> from the icon on the right, we adjust the parameters and connect to the port of arduino uno
> *Low light*: 90, *Intensity*: 30, *Speed*: 800, *Time*: 200, *Step*: 1, *Carve Mode*: outline
> from the next window we adjust the pins, for example:
> *STEP*: 3,2 ... *DIR*: 5,6 ... *MIN*: -1,-1 ... *MAX*: -1,-1 ... *PPM*: 800,800
> 
>Then you can choose the image and rescale it between 0 and 20 
>
<!-- >  ```
> 
> ```

```
python web_cam.py
``` -->

### * Mode using Arduino IDE to draw saved shapes

* Don't forget to update the *IP* address in the *esp_cnc.ino* code in *esp_cnc*, and in the *App.js* file in the *front_end* folder 

>Install node modules in the *front_end* folder
> ```
> npm start
> ```
> 
> then start the front
> ```
> npm start
> ```

>In the main folder, run the server
> ```
> python server.py
> ```

Note: you can't upload the code of arduino while you the app is connected to the aruino port
