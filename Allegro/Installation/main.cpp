/*For any project you create that uses Allegro 5, you must tell Visual C++ to link your project with the Allegro 5 library.

Right click your project under Solution Explorer on the right. Select Properties.

Under Configuration Properties->C/C++->General,  enter "c:\allegro\include" in Additional Include Directories.
Under Configuration Properties->Linker->General, enter "c:\allegro\lib"     in Additional Library Directories.
Under Configuration Properties->Linker->Input, append allegro-5.0.10-monolith-md-debug.lib to Additional Dependencies.													  
Under Configuration Properties->Debugging, enter PATH=c:\allegro\bin;%PATH% in Environment.
Click Apply.
Visual C++ can now link your project with the Allegro 5 library.
*/
#include <stdio.h>
#include <allegro5/allegro.h>

int main(int argc, char **argv)
{
   ALLEGRO_DISPLAY *display = NULL;

   if(!al_init()) {
      fprintf(stderr, "failed to initialize allegro!\n");
      return -1;
   }

   display = al_create_display(640, 480);
   if(!display) {
      fprintf(stderr, "failed to create display!\n");
      return -1;
   }

   al_clear_to_color(al_map_rgb(0,0,0));
   
   al_flip_display();

   al_rest(10.0);

   al_destroy_display(display);

   return 0;
}

/*
But wait, this method is for dynamic linking. What if you want it so MSVCR100.dll and the Allegro libraries come packaged with the executable? You'll have to change some things. You can do this just for the Release configuration, no need to do it for the Debug one.

Add the following libraries to the linker in Configuration Properties->Linker->Input:
(Your standard Allegro library(ies), but with the -static-mt suffix. So, for instance, allegro_image-5.0.10-static-mt.lib. This can be the monolith dll, or all addons separated.)
dumb-0.9.3-static-mt.lib
freetype-2.4.8-static-mt.lib
libFLAC-1.2.1-static-mt.lib
libogg-1.2.1-static-mt.lib
libvorbis-1.3.2-static-mt.lib
libvorbisfile-1.3.2-static-mt.lib
openal-1.14-static-mt.lib
zlib-1.2.5-static-mt.lib
winmm.lib
opengl32.lib
gdiplus.lib
psapi.lib
shlwapi.lib
On the Configuration Properties->Linker->Input dialog box, leave the "inherit from parent or project defaults" option checked.
In Configuration Properties->C/C++->Code Generation->Runtime Library, set that to "/MT" (or "/MTd" for the Debug configuration).
In Configuration Properties->C/C++->Preprocessor->Preprocessor Definitions, add ALLEGRO_STATICLINK to the list.
Alternately, add #define ALLEGRO_STATICLINK to the top of your main file, before you include anything Allegro-related.
This option is sometimes preferred, given that with dynamic linking, you'll have to distribute the dlls with the executable. This isn't normally a problem, but given that there are 2 versions of MSVCR100.dll, the 32-bit and 64-bit one, you can't distribute them both (as they have the same name).
*/