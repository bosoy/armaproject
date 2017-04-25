hostage setCaptive false;
hostage stop false;
hostage setUnitPos "AUTO";
sleep 1;
pilot globalChat "Pilot: I owe you guys!";
[hostage] joinSilent Leader alpha;
addSwitchableUnit hostage;