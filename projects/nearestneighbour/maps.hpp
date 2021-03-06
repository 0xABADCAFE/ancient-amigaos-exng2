#ifndef _MAPS_HPP_
#define _MAPS_HPP_

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Map {

  public:
    enum {
      MAP_DIMENSION = 8
    };
    uint32 getSize() { return 1UL<<MAP_DIMENSION; }
    Map::Map();
    virtual Map::~Map();
  protected:
    uint8* data;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class LinearMap : public Map {

  public:
    uint8& point(uint32 x, uint32 y);
    LinearMap();
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class SubPatch16Map : public Map {

  enum {
    MASK_LOWER = 3,
    MASK_UPPER = ((1<<(MAP_DIMENSION-2))-1)<<2,
  };

  public:
    uint8& point(uint32 x, uint32 y);
    SubPatch16Map();

};




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif