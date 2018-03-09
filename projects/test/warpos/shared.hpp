
struct SharedStruct {
  int   foo;
  float bar;
};

#ifdef __PPC__

void init(SharedStruct* s);

extern "C" {
  void init68K(SharedStruct* s);
};

#else

void init68K(struct SharedStruct* s);

#endif
