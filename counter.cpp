#include <iostream>
;

class Object {

  static size_t count;
public:
  Object() { ++count; }
  ~Object() { --count; }

  static size_t f_count()
  { return count; }

};

size_t Object::count = 0;

int main(int argc, char const *argv[])
{
    std::cout<< Object::f_count()<<std::endl;
    Object Ob1;
    std::cout<< Object::f_count()<<std::endl;
    Object Ob2[3];
    std::cout<< Object::f_count()<<std::endl;
    
    
    return 0;
}

;