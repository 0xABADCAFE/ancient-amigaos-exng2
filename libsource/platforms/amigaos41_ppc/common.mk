EXNG2		 = ////exng2/
PLATFORM = amigaos41_ppc
SRCDIR	 = $(EXNG2)libsource/
INCDIR   = $(EXNG2)include/
LIBDIR	 = $(EXNG2)lib/$(PLATFORM)/
LN			 = ln -s
CXXFLAGS = -O3 -Wall -W -Wno-unused-parameter -fomit-frame-pointer -I$(INCDIR) -I$(INCDIR)platforms/$(PLATFORM) -fPIC -DXP_PLATFORM="$(PLATFORM)/"
