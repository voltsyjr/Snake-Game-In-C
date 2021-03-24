						CSB PROJECT:: SNAKE GAME
					  STEPS TO BE FOLLOWED TO RUN THE GAME:
**********************************************************************************************************************************

---> STEP 1: Download the codeblocks from the link given below.
              https://sourceforge.net/projects/codeblocks/files/Binaries/20.03/Windows/codeblocks-20.03-setup.exe/download

---> STEP 2: Download the mingw 32 bit compiler from the link given below.
                        https://jmeubank.github.io/tdm-gcc/

---> STEP 3: Download the graphics header file for codeblocks library from the link given below.
                        https://drive.google.com/file/d/16xZBvFXf7yFjxwTpuyevK1KPuLgUeZFh/view

---> STEP 4: Unzip the graphics.h file and copy the "winbgim" and "graphics.h" file.

---> STEP 5: Paste the two files in C: --> TDM-GCC-32 --> include.

---> STEP 6: Again go to graphics header file for codeblocks and copy "libbgi.a" and paste it in C:\TDM-GCC-32\lib.

---> STEP 7: Open the codeblocks and go to the Settings-->compiler-->Toolchain Executables.

---> STEP 8: In toolchain executables add the address of the compiler mingw32 which was downloaded in STEP 2.

---> STEP 9: Then go to linker settings --> other linker options. Add the address given below and click on OK.
                 -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32

---> STEP 10: Now create a empty file and save it with extension(.cpp). Copy the code in the Empty file.

---> STEP 11: Save the code and go to Build and select Build & Run option. The game will run!!! 

						Enjoy the Game!!
********************************************************************************************************************************
           **************************************************************************************************