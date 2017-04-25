Private["_object"];

_object = _this select 0;

([_object,towns] Call SortByDistance) select 0;