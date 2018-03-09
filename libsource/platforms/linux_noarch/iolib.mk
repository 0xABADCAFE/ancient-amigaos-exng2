OBJDIR   = obj/iolib/
LIB			 = libexng2io.so
VER			 = 1
REV			 = 0.1
OBJ      =	$(OBJDIR)inputdevices.o \
						$(OBJDIR)streamio_error.o \
						$(OBJDIR)stream_buffer_native.o \
						$(OBJDIR)stream_in_native.o \
						$(OBJDIR)stream_out_native.o \
						$(OBJDIR)socket_native.o \
					 	$(OBJDIR)xsfio.o \
						$(OBJDIR)xsfio_error.o \
						$(OBJDIR)xsf_headers.o \
						$(OBJDIR)xsf_stream.o

$(LIB): $(OBJ) Makefile_iolib
	$(CXX) -shared -Wl,-soname,$(LIB).$(VER) -o $(LIBDIR)$(LIB).$(VER).$(REV) $(OBJ); \
	cd $(LIBDIR); \
	$(LN) $(LIB).$(VER).$(REV) $(LIB); \
	$(LN) $(LIB).$(VER).$(REV) $(LIB).$(VER); \
	cd ../

$(OBJDIR)inputdevices.o: $(SRCDIR)iolib/inputdevices.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJDIR)streamio_error.o: $(SRCDIR)iolib/streamio_error.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJDIR)stream_buffer_native.o: $(SRCDIR)platforms/linux_noarch/iolib/stream_buffer_native.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJDIR)stream_in_native.o: $(SRCDIR)platforms/linux_noarch/iolib/stream_in_native.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJDIR)stream_out_native.o: $(SRCDIR)platforms/linux_noarch/iolib/stream_out_native.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJDIR)socket_native.o: $(SRCDIR)platforms/linux_noarch/iolib/socket_native.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJDIR)xsfio.o: $(SRCDIR)iolib/xsfio.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJDIR)xsfio_error.o: $(SRCDIR)iolib/xsfio_error.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJDIR)xsf_headers.o: $(SRCDIR)iolib/xsf_headers.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJDIR)xsf_stream.o: $(SRCDIR)iolib/xsf_stream.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJDIR)*.o; \
	$(RM) $(LIBDIR)$(LIB)*
