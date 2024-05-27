#ifndef CALCULATOR_H
#define CALCULATOR_H

#ifdef _WIN32
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif

extern "C" {
    namespace ACTION_NEW
    {
        void test();
    }
}

#endif