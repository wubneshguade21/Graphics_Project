Interactive Flag & Logo Rendering System with Matrix Transformations
📌 Computer Graphics Project (OpenGL & GLUT)

This project is a fully interactive 2D graphics simulation system developed using C++, OpenGL, and GLUT. It demonstrates real-time rendering techniques combined with transformation mathematics to create a dynamic ceremonial scene featuring a waving flag, animated logo, and changing environment (day/night cycle).

The system focuses on procedural animation, user interaction, and matrix-based transformations, making it a strong demonstration of core computer graphics concepts in practice. It also includes a real-time HUD (Heads-Up Display) that provides system status, controls, and live animation feedback.

The application is designed to showcase how mathematical models and graphics primitives work together to build an interactive visual simulation that responds to user input in real time.
1. Geometric Primitive Layout

This project uses different OpenGL primitives to build and animate the scene. 
GL_POINTS creates the star background with twinkling effects, 
GL_LINES is used for sun rays, ropes, and structural connections.
GL_POLYGON forms smooth circular shapes like the sun, moon, and logo base. 
GL_QUADS are used for rectangular HUD elements and structural parts of the logo.
The waving flag is created using GL_QUAD_STRIP for smooth continuous motion.
GL_TRIANGLES add decorative details. Finally
GL_LINE_LOOP is used for circular rope and ring structures around the flagpole.
2. Correct & Verified Real-World Color Palettes

To improve visual realism, the project uses carefully selected real-world inspired color values instead of default or random colors. 
Each object in the scene is assigned a specific RGB value that represents its natural or commonly accepted appearance in real environments.

The day sky is represented using a soft light blue tone to simulate a clear daytime atmosphere.
The night sky uses a deep dark blue shade to represent a midnight environment.
The sun is rendered using a bright yellow color to represent strong daylight intensity.
The moon is designed with a pale cream color to reflect natural moonlight.
The logo uses a deep blue shade to represent a strong identity and visual focus.
The flag red section uses a vibrant red color to represent energy and visibility.
The flag white section uses pure white to maintain clarity and contrast.


3. Comprehensive Matrix Transformations

This project uses a structured transformation system to control all visual elements in the scene. Each object is handled independently using OpenGL matrix stack operations, which ensures transformations do not interfere with one another.

Translation (glTranslatef) is used to move objects across the screen. It allows interactive repositioning of the logo and flag, and also helps simulate natural movement paths for animated elements like celestial bodies.
Rotation (glRotatef) controls the angular movement of objects. It is applied to the logo, flag structure, and sun rays to create smooth spinning and directional changes.
Scaling (glScalef) adjusts the size of objects dynamically. It is used for zoom effects, responsive resizing of the logo and flag, and subtle animation effects that improve visual realism.

By combining these transformations with glPushMatrix() and glPopMatrix(), each object maintains its own local coordinate system, ensuring clean and organized rendering throughout the scene.
To go beyond the standard classroom requirements and satisfy the bonus challenge criteria, this project introduces an advanced Interactive Environmental Animation System integrated directly into the OpenGL rendering engine.

🚩 Realistic Animated Flag Rendering

The flag is not displayed as a static object. Instead, it dynamically waves in real time to simulate natural fabric movement under wind force. The motion continuously changes during execution, creating a smooth and realistic animation effect across the entire flag surface.

🌬 Interactive Wind Control System

A real-time wind control mechanism allows users to increase or decrease wind intensity using keyboard input. As the wind strength changes, the movement of the flag becomes either smoother or more aggressive, creating different environmental conditions during runtime.

🌗 Dynamic Day and Night Environment

The project supports fully interactive switching between daytime and nighttime environments.

☀ Day Mode
Bright blue atmospheric background
Animated sun rendering
Rotating sunlight rays
Fully raised ceremonial flag
🌙 Night Mode
Dark night sky environment
Procedural twinkling stars
Animated crescent moon effect
Automatic lowering of the flag

The transition between environments occurs smoothly through user interaction.

📊 Real-Time HUD Dashboard

A semi-transparent Heads-Up Display (HUD) is rendered at the top of the screen to provide live runtime information, including:

Current animation status
Day/Night environment state
Wind intensity level
Camera zoom percentage
Rotation values
Scaling percentages
User control instructions

This improves usability while demonstrating real-time graphical interface rendering.

⏯ Pause and Resume Animation System

The application includes interactive mouse-based control for simulation management.

Single Click on Logo: Switch between Day and Night modes
Double Click on Logo: Pause or Resume all animations

When paused, all animated components stop smoothly while preserving the current scene state.

# 🎮 Interactive System Control Mapping

### Central Logo Modifiers
| Mapping Key | Assigned System Matrix Action |
| :--- | :--- |
| `W` | Move Object Center Vertically Up |
| `S` | Move Object Center Vertically Down |
| `A` | Move Object Center Horizontally Left |
| `D` | Move Object Center Horizontally Right |
| `R` | Rotate Object Angle Orbitally Clockwise |
| `T` | Rotate Object Angle Orbitally Counterclockwise |
| `M` | Increase Uniform Dimensional Matrix Scale |
| `N` | Decrease Uniform Dimensional Matrix Scale |

### 🚩 Flag Structure Modifiers
Mapping Key <<<<<<<< Assigned System Matrix Action 

 `Y` >>>>>> Move Flag Asset Base Vertically Up 
 `H` >>>>>>>Move Flag Asset Base Vertically Down 
`G` >>>>>>Move Flag Asset Base Horizontally Left 
 `J` >>>>>>Move Flag Asset Base Horizontally Right 
 `I` >>>>>>Rotate Rigging Structure Pitch Clockwise 
`O` >>>>>>>Rotate Rigging Structure Pitch Counterclockwise 
`U` >>>>>> Increase Flag Bounding Box Extents Scale 
`B` >>>>>> Decrease Flag Bounding Box Extents Scale 

###  Global Environment & Tool Options
 Mapping Key<<<<<<<<<Assigned System Matrix Action 

 `1` >>>>>>>> Attenuate Simulated Wind Velocity Engine Output 
`2` >>>>>>>> Boost Simulated Wind Velocity Engine Output 
 `8` >>>>>>>> Apply Orthographic Matrix Scaling Scale-Out Factor 
`9` >>>>>>>>>> Apply Orthographic Matrix Scaling Scale-In Factor 
`ESC` >>>>>>>>Safely Terminate Application Context Loop 

Mouse Controls
Action>>>>>>>>>>	Result
Single Click	>>>>>>>>>>Toggle Day/Night
Double Click	>>>>>>>>Pause/Resume Animation
#  Core Architectural Function Mapping

|Source Function >>>>>>>>Structural Execution Role 

 `display()` |>>>>>>>>Main rendering loop; handles buffer clearing, window projections, and rendering the scene graph. 
 `timer()` >>>>>> 60Hz (~16ms) clock callback; updates mathematical animation variables and phase offsets. 
`drawCelestialBody()`>>>>>Generates circle geometry using parametric formulas; handles sun ray rotations and pulses. 
 `renderHUD()` >>>>>>> Renders the alpha-blended overlay dashboard, system statistics, and text instructions. 
 `handleMouse()` >>>>> Intercepts click coordinates, maps them to world spaces, and runs distance-bounds checks. 
`handleKeypress()` >>>>> Maps ASCII keyboard inputs directly to matrix transformation variables and engine switches. 
`drawStars()` >>>>>>>>>Spawns a seeded pseudo-random coordinate point grid to process background twinkling logic. 
 `drawRingArc()` >>>>>> Draws semi-elliptical lines around the flagpole to simulate a layered, pseudo-3D rigging ring. 
 `renderText()` >>>>>>> Processes string data arrays using `glutBitmapCharacter` to render flat 2D raster fonts. |
 Implementation & Challenges

## ⚙️ Installation & Setup

### Requirements
- Windows OS
- Code::Blocks / Visual Studio
- OpenGL (GLUT / FreeGLUT)

### Run Steps
1. Clone the repository
2. Open project in codeblock
3. Make sure GLUT/OpenGL libraries are linked
4. Build and Run

Technical Challenges & Resolutions 
 Rigid Flag Animation
Problem: Uniform transformations made the flag look stiff and unrealistic.
Solution: Split the flag into a vertex grid and applied time-based sine/cosine wave functions. Wind strength and distance from the pole control wave intensity for realistic cloth motion.
Click Detection Issues under Zoom
Problem: Zooming distorted mouse coordinates, causing inaccurate click detection on the logo.
Solution: Converted screen coordinates back into fixed world space (1200 × 750) and applied inverse scaling to maintain correct hit detection.
 Single vs Double Click Conflict (GLUT)
Problem: GLUT does not natively support distinguishing single and double clicks, causing unintended mode switching.
Solution: Implemented a timing threshold using glutGet(GLUT_ELAPSED_TIME). Clicks within 300 ms are treated as double-clicks (pause/resume), otherwise treated as single-click (mode toggle).

 the out put image

 <img width="1062" height="641" alt="flags" src="https://github.com/user-attachments/assets/c912de03-3f34-4eda-9108-cedfd47448d5" />
<img width="1157" height="638" alt="flag12" src="https://github.com/user-attachments/assets/c37ed3dc-1a43-4867-98cb-551362f702b1" />








group member NAME           ID
 1.Yeabsra andargachew       gur/o1154/16
 2.Wubnesh guade              gur/02172/16
 3.Dawit Atnkut               gur/
 4.Surafel                      gur
 5.Ayub
 6.Meseret           
 7 Sekeriya

│
│
└── assets/                  # Shared geometric design templates
<img width="1157" height="638" alt="image" src="https://github.com/user-attachments/assets/de9f45d7-9e8d-4483-95d1-7d5cb939b025" />
