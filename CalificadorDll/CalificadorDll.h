
#ifdef CALIFICADORDLL_EXPORTS
#define CALIFICADORDLL_API __declspec(dllexport) 
#else
#define CALIFICADORDLL_API __declspec(dllimport) 
#endif