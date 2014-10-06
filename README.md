Internet_of_things_Home_secutiry_system
=======================================

With the 3.2 Billion purchase of Nest from Google and the “smart home platform” announced by Apple,
Internet of thing is moving quickly into out lifes.  The internet of things is essentially a intergration of 
household appliance with internet that allows people to monitor/control home appliance through their 
phone and Laptop.

This project demostrate How we can implement a simple home security system with Internet of Things. 
  We are using Proximity sensor to detect a event of closing distance such door opens, people approaches. This 
event can get picked up by Respberry Pi and sent off to online server which alerts owner with a text message.

BOM:
*Electric Imp break out wifi-controller board + IMP SD wifi-card
*Pull up resisters and Jumper wires
*STM Proximity Sensor
*Raspberry Pi Micro-Computer
*Breadboard and Wires

<img src="https://raw.githubusercontent.com/eddyzhangGit/Internet_of_things_Home_secutiry_system/master/image/BOM.jpg" 
alt="IMAGE ALT TEXT HERE" width="700" height="450" border="10" />
Figure[0] required material

MileStone 1:  
Designed the entire schematic on EAGLE CAD

<img src="https://raw.githubusercontent.com/eddyzhangGit/Internet_of_things_Home_secutiry_system/master/image/Capture_imp.PNG" 
alt="IMAGE ALT TEXT HERE" width="700" height="450" border="10" />
Figure[1] Schematic


MileStone 2: 
Programmed the Proximity sensor as Low threhold interrrupt that is to trigger when a predefined the distance is 
detected.  source code @(
*set the interrrupt as Active low and Low threhod triggered.
*set Low threhod as 3 cm.
*Test the interrrupt will trigger at around 3 cm

<img src="https://raw.githubusercontent.com/eddyzhangGit/Internet_of_things_Home_secutiry_system/master/image/checking_distance.PNG" 
alt="IMAGE ALT TEXT HERE" width="700" height="450" border="10" />
Figure[2.a] Check_distance

<img src="https://raw.githubusercontent.com/eddyzhangGit/Internet_of_things_Home_secutiry_system/master/image/detecting_distance.jpg" 
alt="IMAGE ALT TEXT HERE" width="700" height="450" border="10" />
Figure[2.b] Check_distance


MileStone 3: 
Now we have the respberry pi picking up the signal from 
Proximity sensor, We need a way to send it to the user.  
Here comes the internet of the things.
We use a wifi-adapting micro-controller(electric imp) to 
Send a request to  web server code. The webserver code is 
programmed to send a text message to the owners.

<img src="https://raw.githubusercontent.com/eddyzhangGit/Internet_of_things_Home_secutiry_system/master/image/server_code.PNG" 
alt="IMAGE ALT TEXT HERE" width="700" height="450" border="10" />
Figure[2.b] configuring the server code to send a text message

_Author: Eddy Zhang

_Email : <eddy.zhang@mail.utoronto.ca>_

_Phone: 416-655-6473_
