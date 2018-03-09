EXNG2		 = /extropia/exng2
PLATFORM = linux_x86
SRCDIR	 = $(EXNG2)/libsource/
INCDIR   = $(EXNG2)/include/
LIBDIR	 = $(EXNG2)/lib/$(PLATFORM)/
LN			 = ln -s
CXXFLAGS = -O3 -Wall -W -Wno-unused-parameter -I$(INCDIR) -I$(INCDIR)platforms/$(PLATFORM) -m32 -fPIC -DXP_PLATFORM="$(PLATFORM)/"
