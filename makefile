vpath %.h header
vpath %.c src
vpath %.o obj
vpath main bin

CC = gcc
CFLAGS = -g -Wall -Wextra
IFLAGS = -Iinclude
LDLIBS = -lSDL -lSDL_image

ALL = all
LABYRINTHE = labyrinthe
OBJFILES = obj/display.o obj/editeur.o obj/grille.o obj/jeu.o obj/joueur.o obj/monstre.o obj/load_elements.o obj/main.o
OPATH = obj
CPATH = src
BPATH = bin

$(ALL) : $(LABYRINTHE)

$(LABYRINTHE) : $(OBJFILES)
	$(CC) -o $@ $^ $(LDLIBS)
	mv $@ $(BPATH)

$(OPATH)/%.o : $(CPATH)/%.c
	$(CC) $(CFLAGS) -c $< $(IFLAGS) -o $@
	

exedoc :
	doxygen doxyfile

gendoc : 
	doxygen -g doxyfile
	echo "RECURSIVE = YES" >> doxyfile
	echo "EXTRACT_ALL = YES" >> doxyfile
	echo "GENERATE_LATEX = NO" >> doxyfile
	echo "OPTIMIZE_OUTPUT_FOR_C  = YES" >> doxyfile
	echo "PROJECT_NAME = Jeu_du_Labyrinthe_Titouan_RABU_JeanRomain_LUTTRINGER" >> doxyfile

clean :
	rm -r $(OPATH)/* $(BPATH)/* 
archive :
	tar czvf Projet_JRO_LUTTRINGER_TITOUAN_RABU.tar.gz .
# DO NOT DELETE

src/main.o: /usr/include/stdlib.h /usr/include/features.h
src/main.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
src/main.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
src/main.o: /usr/include/gnu/stubs-64.h /usr/include/sys/types.h
src/main.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
src/main.o: /usr/include/time.h /usr/include/endian.h
src/main.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
src/main.o: /usr/include/sys/select.h /usr/include/bits/select.h
src/main.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
src/main.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
src/main.o: /usr/include/alloca.h /usr/include/stdio.h /usr/include/libio.h
src/main.o: /usr/include/_G_config.h /usr/include/wchar.h
src/main.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
src/main.o: /usr/include/SDL/SDL.h /usr/include/SDL/SDL_main.h
src/main.o: /usr/include/SDL/SDL_stdinc.h /usr/include/SDL/SDL_config.h
src/main.o: /usr/include/SDL/SDL_platform.h /usr/include/string.h
src/main.o: /usr/include/xlocale.h /usr/include/strings.h
src/main.o: /usr/include/inttypes.h /usr/include/stdint.h
src/main.o: /usr/include/bits/wchar.h /usr/include/ctype.h
src/main.o: /usr/include/iconv.h /usr/include/SDL/begin_code.h
src/main.o: /usr/include/SDL/close_code.h /usr/include/SDL/SDL_audio.h
src/main.o: /usr/include/SDL/SDL_error.h /usr/include/SDL/SDL_endian.h
src/main.o: /usr/include/SDL/SDL_mutex.h /usr/include/SDL/SDL_thread.h
src/main.o: /usr/include/SDL/SDL_rwops.h /usr/include/SDL/SDL_cdrom.h
src/main.o: /usr/include/SDL/SDL_cpuinfo.h /usr/include/SDL/SDL_events.h
src/main.o: /usr/include/SDL/SDL_active.h /usr/include/SDL/SDL_keyboard.h
src/main.o: /usr/include/SDL/SDL_keysym.h /usr/include/SDL/SDL_mouse.h
src/main.o: /usr/include/SDL/SDL_video.h /usr/include/SDL/SDL_joystick.h
src/main.o: /usr/include/SDL/SDL_quit.h /usr/include/SDL/SDL_loadso.h
src/main.o: /usr/include/SDL/SDL_timer.h /usr/include/SDL/SDL_version.h
src/main.o: /usr/include/SDL/SDL_image.h /usr/include/SDL/SDL.h
