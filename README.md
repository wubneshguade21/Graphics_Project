 OpenGL Animation Project: Flag & Bluetooth Logo

 Overview
This project is developed using C++ and OpenGL (GLUT). It demonstrates 2D graphics animation including transformations, real-time motion, and wind simulation effects. The program renders a waving flag and a Bluetooth logo with continuous animation.



Features

 Flag Animation
- Realistic wind-based waving effect using sine and cosine functions
- Smooth continuous motion with time-based animation
- Flag lifting simulation for dynamic movement
 Flag Structure
- Multi-segment flag pole
- Rope connection system
- Cloth animation using QUAD_STRIP rendering
- Natural fabric-like deformation
 Animation System
- Continuous rendering using `glutIdleFunc`
- Time-based updates (`waveTime`)
- Smooth frame updates for real-time motion

 Wind Control
- Press `1` → decrease wind speed
- Press `2` → increase wind speed
- Wind affects wave intensity and animation speed

Bluetooth Logo
- Custom geometric design
- Rotation and scaling support
- Independent transformation system



 Controls

 Flag Controls
- Y / H → Move up/down  
- G / J → Move left/right  
- I / O → Rotate  
- U / B → Scale  

 Logo Controls
- W / S → Move up/down  
- A / D → Move left/right  
- R / T → Rotate  
- M / N → Scale  
Wind Control
- 1 → Decrease wind speed  
- 2 → Increase wind speed  

 Exit
- ESC → Quit program  



 Technologies Used
- C++
- OpenGL (GLUT)
- Windows.h
- Math library (sin, cos)


 How It Works
The animation is driven using:
- `waveTime` → controls wave motion
- `windScale` → controls wind strength
- `glutIdleFunc(update)` → continuous rendering loop

Flag waving effect is generated using:
sin(0.05 * x + waveTime) and cos(0.05 * x + waveTime)

This creates smooth and realistic cloth movement.

 Project Highlights
Real-time animation system  
Wind simulation effect  
Flag cloth physics approximation  
Continuous rendering loop   OpenGL transformation system  


 Author
Wubnesh Guade 

