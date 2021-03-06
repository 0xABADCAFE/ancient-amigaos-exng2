OBJDIR   = obj/utilitylib/
LIB			 = libexng2utility.so
VER			 = 1
REV			 = 0.1
OBJ      =	$(OBJDIR)hashkeys.o \
						$(OBJDIR)debug.o \
						$(OBJDIR)poll.o

$(LIB): $(OBJ) Makefile_utilitylib
	$(CXX) -shared -Wl,-soname,$(LIB).$(VER) -o $(LIBDIR)$(LIB).$(VER).$(REV) $(OBJ); \
	cd $(LIBDIR); \
  $(LN) $(LIB).$(VER).$(REV) $(LIB); \
  $(LN) $(LIB).$(VER).$(REV) $(LIB).$(VER); \
	cd ../

$(OBJDIR)hashkeys.o: $(SRCDIR)utilitylib/hashkeys.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJDIR)debug.o: $(SRCDIR)utilitylib/debug.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJDIR)poll.o: $(SRCDIR)utilitylib/poll.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJDIR)*.o
	$(RM) $(LIBDIR)$(LIB)*