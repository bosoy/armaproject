mando_rearm_target = _this select 0;
_ok = createDialog "MandoMissileRearmDlg";
if (!_ok) then
{
   hint "Dialog failed";
};