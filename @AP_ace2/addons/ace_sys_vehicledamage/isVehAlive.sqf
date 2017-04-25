//returns true if vehicle is fully functional
//returns false if vehicle is destroyed or partially disabled

(alive _this) && {(_this getvariable ["ace_canmove", true])} && {(_this getvariable ["ace_canshoot", true])} && {!(_this getvariable ["ace_onfire", false])}

