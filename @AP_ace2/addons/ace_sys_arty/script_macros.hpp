// global define values for within this module

#define MILPREC 17.7777777777778
#define DEG2MIL(deg)	(((deg*MILPREC)) min 6400)
#define MIL2DEG(mil)	mil/MILPREC

#define GETELEV(T,I) ((##T## select ##I##) select 0)
#define GETMAXHEIGHT(T,I) ((##T## select ##I##) select 1)
#define GETSLICES(T,I) ((##T## select ##I##) select 2)

// Rocket ballistics values
#define GETOFFSETH(T,I) ((##T## select ##I##) select 3)
#define GETOFFSETV(T,I) ((##T## select ##I##) select 4)
#define GETDECAYELEV(T,I) ((##T## select ##I##) select 5)
#define GETDECAYSPD(T,I) ((##T## select ##I##) select 6)

// fnc_firingSolution used
#define ELEVATION(sol)	(floor DEG2MIL((sol select 0)))
#define TOF(sol)		((sol select 2))
