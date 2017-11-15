# Dotel 
[![License](https://img.shields.io/badge/License-BSD%203--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause) [![c++](https://img.shields.io/badge/C%2B%2B-17-red.svg)]() [![clion](https://img.shields.io/badge/CLion-Supported-green.svg)]() 

Dotel is a 2D and 3D game engine implemented in C++ 17 and released under the BSD-3-Clause license.

## Documentation
Here is a simple example program
```C++

#include <Dotel.h>

using namespace Dotel;

int main(int argc, char* argv[])
{
	Window window(800, 600, "Dotel Example!");
  
 	while(!window.shouldClose())
  	{
    		window.clear();
    		window.update();
  	}
  	return 0;
}

```

### Windows
Please use CLion with (https://nuwen.net/mingw.html) or install [Boost 1.65.1](http://www.boost.org/users/history/version_1_65_1.html) for your self

## Credits
Dotel developed by:
- Keir Davis (https://github.com/Hexeption)
- Arthur Williams (https://github.com/DabatoIsCool)

Dotel uses the following third-party libraries:
- GLFW 3.2.1 (https://github.com/glfw/glfw)
- GLAD 0.1.14A0 (https://github.com/Dav1dde/glad)
- GLM 0.9.6.3 (https://glm.g-truc.net/0.9.6/index.html)
- Boost 1.65.1 (http://www.boost.org/users/history/version_1_65_1.html)

## License

Licensed under the BSD-3-Clause license, see [LICENSE](https://github.com/Hexeption/Dotel/blob/master/LICENSE) for details.


