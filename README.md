# moh-obs-fix
CLI helper to change the 'renderer present method' useful for fixing MOHAA's OBS issues \
(when trying to use the 'GameCapture' source option).


> [!WARNING]
> Only usable with NVIDIA graphics cards at the moment.


---

## Fast & Simple Usage
- Download the [latest release](https://github.com/slowptr/moh-obs-fix/releases/tag/v1.0)
- Execute the 'moh-obs-fix.exe' (as Administrator)
- Input 1 for fixing the OBS-Issues
  - (If you want to revert it to default, input 2)
- (Re-)start MOHAA and try capturing the game using the OBS-GameCapture feature

---

## Optional: Build Steps
- Take a look at the [xmake project page](https://github.com/xmake-io/xmake)
  - Download & Install it using their provided instructions
  - Make sure the 'xmake.exe' is included in your PATH variable
- Clone / download the contents of this repository
- Open a cmd / powershell shell inside the cloned repo
  - execute ```xmake``` to compile (output will be inside the newly created build directory)
  - execute ```xmake r``` to run the executable or run the compiled .exe
