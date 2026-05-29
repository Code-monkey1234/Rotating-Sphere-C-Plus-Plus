🌐 Rotating Sphere — ASCII C++
A real-time ASCII art rotating sphere rendered directly in your Windows terminal. No libraries, no dependencies — just pure C++ and math.
........ . o O @ @ @ O o .        
..... o @ @ @ @ @ @ @ @ @ o       
....O @ @ @ @ @ @ @ @ @ @ @ O     
...@ @ @ @ @ @ @ @ @ @ @ @ @ @    
..@ @ @ @ @ @ @ @ @ @ @ @ @ @ @   
.@ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @  
..@ @ @ @ @ @ @ @ @ @ @ @ @ @ @   
...@ @ @ @ @ @ @ @ @ @ @ @ @ @    
....O @ @ @ @ @ @ @ @ @ @ @ O     
......o @ @ @ @ @ @ @ @ @ o       
.......... o O @ @ @ O o .

📋 Requirements

Windows 10 or later
A C++ compiler — either of the following:

g++ via MinGW-w64 or MSYS2
cl via Visual Studio (MSVC)




🚀 How to Run
Step 1 — Clone the repository
Open Windows Terminal or Command Prompt and run:
bashgit clone https://github.com/Code-monkey1234/Rotating-Sphere-C-Plus-Plus.git
cd Rotating-Sphere-C-Plus-Plus
Step 2 — Compile
Using g++ (MinGW / MSYS2):
bashg++ -o sphere rotating_sphere.cpp
Using MSVC (Visual Studio Developer Command Prompt):
bashcl rotating_sphere.cpp /Fe:sphere.exe
Step 3 — Run
bash.\sphere.exe

🖥️ Getting the Best Experience
The sphere renders large — zoom out your terminal first so the full animation fits on screen.
In Windows Terminal:

Hold Ctrl and scroll the mouse wheel down to zoom out, or go to Settings → Appearance → Font size and lower it (e.g. set it to 8 or 10).

In Command Prompt:

Right-click the title bar → Properties → Font → pick a smaller font size.

The smaller the font, the more of the sphere you'll see at once. Aim for a window of at least 120 columns × 40 rows.
Press Ctrl + C to stop the animation.

📁 File Structure
Rotating-Sphere-C-Plus-Plus/
├── rotating_sphere.cpp   ← main source file
└── README.md

📄 License
This project is open source. Feel free to fork, modify, and share.
