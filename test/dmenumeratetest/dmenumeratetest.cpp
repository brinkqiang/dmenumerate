
#include "dmenumerate.h"

int main( int argc, char* argv[] ) {

    Idmenumerate* module = dmenumerateGetModule();
    if (module)
    {
        module->Test();
        module->Release();
    }
    return 0;
}
