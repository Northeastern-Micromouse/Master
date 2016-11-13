#ifndef CC_UTIL_LOCATION_H_
#define CC_UTIL_LOCATION_H_


class Location {
 public:
  Location(int x, int y);

  int GetXLocation();
  int GetYLocation();

  bool isEqual(Location that);

 private:
  int x_;
  int y_;
};

#endif  // CC_UTIL_LOCATION_H_
