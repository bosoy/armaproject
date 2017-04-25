//#define __DEBUG__
#define __COMPXR xr
#define __COMPXRstr #__COMPXR

#define FUNCXR(funcname) __COMPXR##_fnc_##funcname
#define GVARXR(varname) __COMPXR##_##varname
#define QUOTE(qtext) #qtext
#define QGVARXR(varname) QUOTE(GVARXR(varname))
#define __GV(obje,varname) (obje getVariable #varname)
#define __GV2(obje,varname) (obje getVariable varname)
#define __PRA(actionnr) player removeAction actionnr
#define __SV(obje,varname,val) (obje setVariable [#varname, val])
#define __SV2(obje,varname,val,public) (obje setVariable [#varname, val,public])

#define PARAMS_1(param1) param1 = _this select 0
#define PARAMS_2(param1,param2) PARAMS_1(param1); param2 = _this select 1
#define PARAMS_3(param1,param2,param3) PARAMS_2(param1,param2); param3 = _this select 2
#define PARAMS_4(param1,param2,param3,param4) PARAMS_3(param1,param2,param3); param4 = _this select 3
#define PARAMS_5(param1,param2,param3,param4,param5) PARAMS_4(param1,param2,param3,param4); param5 = _this select 4

#define __getMNsVar(mvarname) (missionNamespace getVariable #mvarname)
#define __getMNsVar2(mvarname) (missionNamespace getVariable mvarname)
#define __mNsSetVar missionNamespace setVariable
#define __pGetVar(pvarname) (player getVariable #pvarname)
#define __pSetVar player setVariable
#define __XJIPGetVar(jvarname) (X_JIPH getVariable #jvarname)
#define __XJIPSetVar X_JIPH setVariable
#define __uiGetVar(uvarname) (uiNamespace getVariable #uvarname)
#define __ccppfln(xfile1) call compile preprocessFileLineNumbers #xfile1
#define __cppfln(xdfunc,xfile2) xdfunc = compile preprocessFileLineNumbers #xfile2
#define __INC(vari) vari = vari + 1
#define __DEC(vard) vard = vard - 1
#define __MPCheck if (X_MP) then {waitUntil {sleep (1.012 + random 1);(call XPlayersNumber) > 0}}
#define __xrdead #_xr_dead

// to add backpack support, new commands
#define __OAXR__
//#define __TT__

#ifdef THIS_FILE
#define THIS_FILE_ 'THIS_FILE'
#else
#define THIS_FILE_ __FILE__
#endif

#ifdef __DEBUG__
#define __TRACE(tmsg) diag_log format ["T%1,DT%2,F%3,%4,%5,'%6'", time, diag_tickTime, diag_frameno, THIS_FILE_, __LINE__, tmsg];
#define __TRACE_1(tmsg,parame1) diag_log format ["T%1,DT%2,F%3,%4,%5,'%6',%7: %8", time, diag_tickTime, diag_frameno, THIS_FILE_, __LINE__, tmsg, parame1, call compile format ["%1", parame1]];
#define __TRACE_2(tmsg,parame1,parame2) diag_log format ["T%1,DT%2,F%3,%4,%5,'%6',%7: %8,%9: %10", time, diag_tickTime, diag_frameno, THIS_FILE_, __LINE__, tmsg, parame1, call compile format ["%1", parame1], parame2, call compile format ["%1", parame2]];
#define __TRACE_3(tmsg,parame1,parame2,parame3) diag_log format ["T%1,DT%2,F%3,%4,%5,'%6',%7: %8,%9: %10,%11: %12", time, diag_tickTime, diag_frameno, THIS_FILE_, __LINE__, tmsg, parame1, call compile format ["%1", parame1], parame2, call compile format ["%1", parame2], parame3, call compile format ["%1", parame3]];
#else
#define __TRACE(tmsg)
#define __TRACE_1(tmsg,parame1)
#define __TRACE_2(tmsg,parame1,parame2)
#define __TRACE_3(tmsg,parame1,parame2,parame3)
#endif