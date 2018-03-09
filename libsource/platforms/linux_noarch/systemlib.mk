OBJDIR   = obj/systemlib/
LIB			 = libexng2system.so
VER			 = 1
REV			 = 0.1
OBJ      =	$(OBJDIR)main.o \
						$(OBJDIR)application.o \
					 	$(OBJDIR)error.o \
						$(OBJDIR)reflistbase.o \
						$(OBJDIR)runnable.o \
						$(OBJDIR)startup.o \
						$(OBJDIR)time.o \
						$(OBJDIR)cpu_native.o \
						$(OBJDIR)logger_native.o \
						$(OBJDIR)memory.o \
						$(OBJDIR)memory_error.o \
						$(OBJDIR)memory_native.o \
						$(OBJDIR)procfsparser_native.o \
						$(OBJDIR)time_native.o
#						$(OBJDIR)thread.o \
#						$(OBJDIR)thread_native.o \
#						$(OBJDIR)thread_error_native.o \
#						$(OBJDIR)lockable_native.o
#						$(OBJDIR)thread_sleeper_native.o \

$(LIB): $(OBJ) Makefile_systemlib
	$(CXX) -shared -Wl,-soname,$(LIB).$(VER) -o $(LIBDIR)$(LIB).$(VER).$(REV) $(OBJ); \
	cd $(LIBDIR); \
  $(LN) $(LIB).$(VER).$(REV) $(LIB); \
  $(LN) $(LIB).$(VER).$(REV) $(LIB).$(VER); \
	cd ../

$(OBJDIR)main.o: $(SRCDIR)systemlib/main.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJDIR)application.o: $(SRCDIR)systemlib/application.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJDIR)error.o: $(SRCDIR)systemlib/error.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJDIR)reflistbase.o: $(SRCDIR)systemlib/reflistbase.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJDIR)runnable.o: $(SRCDIR)systemlib/runnable.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJDIR)startup.o: $(SRCDIR)systemlib/startup.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJDIR)time.o: $(SRCDIR)systemlib/time.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJDIR)cpu_native.o: $(SRCDIR)platforms/linux_noarch/systemlib/cpu_native.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJDIR)logger_native.o: $(SRCDIR)platforms/linux_noarch/systemlib/logger_native.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJDIR)memory.o: $(SRCDIR)systemlib/memory.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJDIR)memory_error.o: $(SRCDIR)systemlib/memory_error.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJDIR)memory_native.o: $(SRCDIR)platforms/linux_noarch/systemlib/memory_native.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJDIR)procfsparser_native.o: $(SRCDIR)platforms/linux_noarch/systemlib/procfsparser_native.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJDIR)time_native.o: $(SRCDIR)platforms/linux_noarch/systemlib/time_native.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

#$(OBJDIR)thread.o: $(SRCDIR)systemlib/thread.cpp
#	$(CXX) $(CXXFLAGS) -o $@ -c $<

#$(OBJDIR)thread_native.o: $(SRCDIR)platforms/linux_noarch/systemlib/thread_native.cpp
#	$(CXX) $(CXXFLAGS) -o $@ -c $<

#$(OBJDIR)thread_error_native.o: $(SRCDIR)platforms/linux_noarch/systemlib/thread_error_native.cpp
#	$(CXX) $(CXXFLAGS) -o $@ -c $<

#$(OBJDIR)lockable_native.o: $(SRCDIR)platforms/linux_noarch/systemlib/lockable_native.cpp
#	$(CXX) $(CXXFLAGS) -o $@ -c $<

#$(OBJDIR)thread_sleeper_native.o: $(SRCDIR)platforms/linux_noarch/systemlib/thread_sleeper_native.cpp
#	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJDIR)*.o \
	$(RM) $(LIBDIR)$(LIB)*