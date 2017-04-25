/*
mando_remote_commands.sqf v1.0
July 2007 Mandoble

DO NOT EXECUTE THIS SCRIPT MANUALLY
*/

mando_remote_command = "";

while {true} do
{
   waitUntil {mando_remote_command != ""};
//   hint format["COMMAND:%1", mando_remote_command];
   call compile mando_remote_command;     
   mando_remote_command = "";
};

