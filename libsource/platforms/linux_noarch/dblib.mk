OBJDIR   = obj/dblib/
LIB			 = libexng2db.so
VER			 = 1
REV			 = 0.1
OBJ      =	$(OBJDIR)db_abstract.o \
						$(OBJDIR)db_error.o \
						$(OBJDIR)db_mysql.o


$(LIB): $(OBJ) Makefile_dblib
	$(CXX) -shared -Wl,-soname,$(LIB).$(VER) -o $(LIBDIR)$(LIB).$(VER).$(REV) $(OBJ); \
	cd $(LIBDIR); \
	$(LN) $(LIB).$(VER).$(REV) $(LIB); \
	$(LN) $(LIB).$(VER).$(REV) $(LIB).$(VER); \
	cd ../

$(OBJDIR)db_abstract.o: $(SRCDIR)dblib/db_abstract.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ -c $<

$(OBJDIR)db_error.o: $(SRCDIR)dblib/db_error.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJDIR)db_mysql.o: $(SRCDIR)dblib/db_mysql.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<


clean:
	$(RM) $(OBJDIR)*.o; \
	$(RM) $(LIBDIR)$(LIB)*