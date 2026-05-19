# Interactive Flag & Logo Rendering System with Matrix Transformations  
📌 Computer Graphics Project (OpenGL & GLUT)

---

## 📖 Project Overview

This project is a fully interactive 2D graphics simulation system developed using C++, OpenGL, and GLUT.  
It demonstrates real-time rendering techniques combined with transformation mathematics to create a dynamic ceremonial scene featuring a waving flag, animated logo, and changing environment (day/night cycle).

The system focuses on procedural animation, user interaction, and matrix-based transformations, making it a strong demonstration of core computer graphics concepts in practice. It also includes a real-time HUD (Heads-Up Display) that provides system status, controls, and live animation feedback.

The application is designed to showcase how mathematical models and graphics primitives work together to build an interactive visual simulation that responds to user input in real time.

---

## 1. Geometric Primitive Layout

This project uses different OpenGL primitives to build and animate the scene:

- `GL_POINTS` → creates the star background with twinkling effects  
- `GL_LINES` → used for sun rays, ropes, and structural connections  
- `GL_POLYGON` → forms smooth circular shapes like the sun, moon, and logo base  
- `GL_QUADS` → used for rectangular HUD elements and structural parts of the logo  
- `GL_QUAD_STRIP` → waving flag smooth continuous motion  
- `GL_TRIANGLES` → decorative details  
- `GL_LINE_LOOP` → circular rope and ring structures around the flagpole  

---

## 2. Correct & Verified Real-World Color Palettes

To improve visual realism, the project uses carefully selected real-world inspired color values instead of default or random colors.  
Each object in the scene is assigned a specific RGB value that represents its natural or commonly accepted appearance in real environments.

- Day sky → soft light blue tone  
- Night sky → deep dark blue shade  
- Sun → bright yellow color  
- Moon → pale cream color  
- Logo → deep blue shade  
- Flag red section → vibrant red color  
- Flag white section → pure white color  

---

## 3. Comprehensive Matrix Transformations

This project uses a structured transformation system to control all visual elements in the scene. Each object is handled independently using OpenGL matrix stack operations, which ensures transformations do not interfere with one another.

- Translation (`glTranslatef`) → move objects across the screen  
- Rotation (`glRotatef`) → angular movement of objects  
- Scaling (`glScalef`) → adjust size of objects  

By combining these transformations with `glPushMatrix()` and `glPopMatrix()`, each object maintains its own local coordinate system, ensuring clean and organized rendering throughout the scene.

---

## 🚀 🎯 🚀 🎯🚀 🎯  Bonus Challenge 🚀 🎯🚀 🎯🚀 🎯 🚀 🎯

To go beyond the standard classroom requirements and satisfy the bonus challenge criteria, this project introduces an advanced Interactive Environmental Animation System integrated directly into the OpenGL rendering engine.

---

## 🚩 Realistic Animated Flag Rendering

The flag is not displayed as a static object. Instead, it dynamically waves in real time to simulate natural fabric movement under wind force. The motion continuously changes during execution, creating a smooth and realistic animation effect across the entire flag surface.

---

## 🌬 Interactive Wind Control System

A real-time wind control mechanism allows users to increase or decrease wind intensity using keyboard input. As the wind strength changes, the movement of the flag becomes either smoother or more aggressive.

---

## 🌗 Dynamic Day and Night Environment

The project supports fully interactive switching between daytime and nighttime environments.

### ☀ Day Mode
- Bright blue atmospheric background  
- Animated sun rendering  
- Rotating sunlight rays  
- Fully raised ceremonial flag  

### 🌙 Night Mode
- Dark night sky environment  
- Procedural twinkling stars  
- Animated crescent moon effect  
- Automatic lowering of the flag  

The transition between environments occurs smoothly through user interaction.

---

## 📊 Real-Time HUD Dashboard

A semi-transparent Heads-Up Display (HUD) is rendered at the top of the screen to provide live runtime information, including:

- Current animation status  
- Day/Night environment state  
- Wind intensity level  
- Camera zoom percentage  
- Rotation values  
- Scaling percentages  
- User control instructions  

---

## ⏯ Pause and Resume Animation System

- Single Click on Logo → Switch between Day and Night modes  
- Double Click on Logo → Pause or Resume all animations  

When paused, all animated components stop smoothly while preserving the current scene state.

---

## 🎮 Interactive System Control Mapping

### Central Logo Modifiers

| Mapping Key | Assigned System Matrix Action |
|------------|------------------------------|
| W | Move Object Center Vertically Up |
| S | Move Object Center Vertically Down |
| A | Move Object Center Horizontally Left |
| D | Move Object Center Horizontally Right |
| R | Rotate Object Angle Orbitally Clockwise |
| T | Rotate Object Angle Orbitally Counterclockwise |
| M | Increase Uniform Dimensional Matrix Scale |
| N | Decrease Uniform Dimensional Matrix Scale |

---

### 🚩 Flag Structure Modifiers

| Key | Action |
|-----|--------|
| Y | Move Flag Asset Base Vertically Up |
| H | Move Flag Asset Base Vertically Down |
| G | Move Flag Asset Base Horizontally Left |
| J | Move Flag Asset Base Horizontally Right |
| I | Rotate Rigging Structure Pitch Clockwise |
| O | Rotate Rigging Structure Pitch Counterclockwise |
| U | Increase Flag Bounding Box Extents Scale |
| B | Decrease Flag Bounding Box Extents Scale |

---

### 🌍 Global Environment & Tool Options

| Key | Action |
|-----|--------|
| 1 | Attenuate Simulated Wind Velocity Engine Output |
| 2 | Boost Simulated Wind Velocity Engine Output |
| 8 | Apply Orthographic Matrix Scaling Scale-Out Factor |
| 9 | Apply Orthographic Matrix Scaling Scale-In Factor |
| ESC | Safely Terminate Application Context Loop |

---

## 🖱 Mouse Controls

| Action | Result |
|--------|--------|
| Single Click | Toggle Day/Night |
| Double Click | Pause/Resume Animation |

---

## 🧠 Core Architectural Function Mapping

| Function | Role |
|----------|------|
| `display()` | Main rendering loop; handles buffer clearing, window projections, and rendering the scene graph |
| `timer()` | 60Hz clock callback; updates animation variables |
| `drawCelestialBody()` | Generates sun/moon geometry |
| `renderHUD()` | Renders system dashboard |
| `handleMouse()` | Mouse interaction handling |
| `handleKeypress()` | Keyboard input mapping |
| `drawStars()` | Star field generation |
| `drawRingArc()` | Flagpole ring rendering |
| `renderText()` | HUD text rendering |

---

## ⚙️ Installation & Setup

### Requirements
- Windows OS  
- Code::Blocks / Visual Studio  
- OpenGL (GLUT / FreeGLUT)

---

### Run Steps

1. Clone the repository  
2. Open project in Code::Blocks  
3. Make sure GLUT/OpenGL libraries are linked  
4. Build and Run  

---

## ⚠️ Technical Challenges & Resolutions

### Rigid Flag Animation
**Problem:** Uniform transformations made the flag look stiff and unrealistic.  
**Solution:** Split the flag into a vertex grid and applied time-based sine/cosine wave functions.

---

### Click Detection Issues under Zoom
**Problem:** Zooming distorted mouse coordinates.  
**Solution:** Converted screen coordinates back into fixed world space (1200 × 750).

---

### Single vs Double Click Conflict (GLUT)
**Problem:** GLUT does not support click differentiation.  
**Solution:** Implemented a 300ms timing threshold using `glutGet(GLUT_ELAPSED_TIME)`.

---

## 📸 Output Images

![Flag Output](https://github.com/user-attachments/assets/c912de03-3f34-4eda-9108-cedfd47448d5)  
![Flag View](https://github.com/user-attachments/assets/c37ed3dc-1a43-4867-98cb-551362f702b1)

---

## 👥 Group Members

| No | Name | ID |
|----|------|----|
| 1 | Yeabsra Andargachew | GUR/O1154/16 |
| 2 | Wubnesh Guade | GUR/02172/16 |
| 3 | Dawit Atinkut | GUR/01843/16 |
| 4 | Surafel Worku | GUR/01327/16 |
| 5 | Ayub Abduljellil| GUR/ 01008/176|
| 6 | Meseret G/Mariam | GUR/02811/16 |
|7  | Sekeria Sulub | GUR/
---
