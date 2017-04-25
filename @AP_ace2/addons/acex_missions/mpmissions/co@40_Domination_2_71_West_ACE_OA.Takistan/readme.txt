(remarks about editing see end of file)

What's new in 2.71 ?

* Fixed: Domination action menus (teamswitch key) now really fixed!

What's new in 2.70 ?

* Fixed: Typo prevented base kick script to work
* Fixed: Commanding Menu was eating up mouse wheel movement in dialogs (map zooming for example), corresponding commanding menu dialogs are now created when the commanding menu is gone
* Fixed: Some chopper kills were written to plane kills in the database
* Fixed: Dropped ammo box handling was counting used boxes wrong
* Removed: Old ammobox handling

What's new in 2.69 ?

* Fixed various bugs which weren't found when testing 2.68 (for example chopper lift)
  Please update @Arma2NET with the one found in this package

What's new in 2.68 ?

* Changed: DomDatabase does need @Arma2Net 2.0 now. Please use the @Arma2NET folder found in the DOM268 download. Simply copy the @Arma2NET folder to your server game folder and start your server with -mod=@Arma2NET
  Please make sure that the user who starts the arma2oaserver.exe has enough rights to write to the @Arma2NET folder. @Arma2NET needs .NET client profile 4.0 installed on the server, clients DO NOT NEED @Arma2NET
  
  The DomDatabase plugin for @Arma2NET creates a SQlite database in your %LocalAppData%\DomDatabase folder. Various stats are saved per player in this database.
  You can also place a simple text file inside your server Arma2 folder called dservername.txt and add your server name in there, it will be used in the mission.
  PLEASE NOTE THAT @Arma2NET is only available on Windows!!! So you can't run this on a Linux server!
  PLEASE ALSO NOTE THAT THIS IS OPTIONAL! THE MISSION DOES ALSO WORK WITHOUT IT!
	
* Added: ACR DLC units, vehicles and weapons to the DLC version, does need the ACR DLC (DLC lite) as soon as it is available!
* Added: If ACRE is activated move player into "dead" channel when he is unconscious

What's new in 2.67 ?

* Fixed: Problem with Squad Mgmt, owner command, like the local command, does not like groups as parameter

What's new in 2.66 ?

* Fixed: Revive did not work anymore
* Fixed: Squad Management was broken

What's new in 2.65 ?

* Fixed: Box marker from dropped ammo boxes (MHQ for example) did not appear anymore
* Fixed: Admin Dialog is now really only available for admins

What's new in 2.64 ?

* Fixed a problem that only logged in admins could open "Show Status"


What's new in 2.63 ?

* Chopper lift fixed (all types work again)

* Player stats upgrade
(Please remove %LocalAppData%\DomDatabase\Dom.db before using the new version
and copy the new DomDatabase Addin files to your @Arma2NET Addins folder!!!)

Extra Player Stats dialog added, available via "Show Status" when the Arma2NET DomDatabase pluggin is available
See What's new in 2.62 on how to add Dom Arma2NET support!

* Some more optimizations and internal fixes

###########################################################################

What's new in 2.62 ?

* ArmA 2 standalone support dropped!!!!!!! Sorry!
OA build 94444 or higher is needed to run Dom now!!!

* The Domination network event system now uses publicVariableServer and publicVariableClient plus other network optimizations

* Some action menu entries are now only available via teamswitch key (OA default is key "T"), for example "Show Status", "Place MGNest", etc).

* Player numbers for the OA only version increased to 40 like the CO version

* Other optimizations

* Optional player stats save (needs ArmA2NET by Scott_NZ, http://forums.bistudio.com/showthread.php?131325-Arma2NET)
Copy the @Arma2NET folder in the Dom download file into your server @Arma2NET folder, edit the Settings.yaml file with a text editor in the @Arma2NET folder and add the following to
PublicKeyTokens:    - 430dbdb37cbe02a2 # DomDatabase
Add @Arma2NET to your server mod line.
It creates a SQlite database in your %LocalAppData%\DomDatabase folder. Currently only # times played, score total and time played is saved.
You can also place a simple text file inside your server Arma2 folder called dservername.txt and add your server name in there.

PLEASE NOTE THAT @Arma2NET is only available on Windows!!! So you can't run this on a Linux server!

###########################################################################

What's new in 2.61 ?

* New server lobby paramaeter: "Sidemissions random:". Default "Yes", if set to "No" the sidemission array won't get shuffeled.
(Makes only sense to set it to "No" if you plan to edit x_missionsetup and change the order of the side missions yourself).


* Main target bonus vehicles can also be set by adding the following to a target location object (d_target_x in the editor) init line:

Normal version:
this setVariable ["d_bonusvec", "A10_US_EP1"];

TT version:
this setVariable ["d_bonusvec_w", "A10_US_EP1"];this setVariable ["d_bonusvec_e", "Su25_TK_EP1"];

In this case no random bonus vehicle is chosen for the target but the one(s) added by setVariable in the location variable space.


* The same works for sidemissions too. But instead of a setVariable you have to add the following to your sidemission sqf file or to one of the common mission files:
GVAR(current_sm_bonus_vec) = "M1A1_US_DES_EP1";
TT version:
GVAR(current_sm_bonus_vec) = ["M1A1_US_DES_EP1", "T72_TK_EP1"];

If defined in a sidemission file those are chosen instead of random sidemission vehicles.

###########################################################################

Some remarks regarding editing...

If you want to place new targets just add another location logic with var name d_target_x where x has to be the next number after the last logic already placed.
x starts with 0 and ends with number of logics - 1. Don't forget a number in between otherwise the algorithm which reads in the targets stops at that position.

The algorithm will search automatically for the next city.
If there is no city nearby or you want to place the logic somewhere else simply add the following into the init line of the logic:
this setVariable ["d_cityname", "Whatevernameyoulike"]
This hinders the algo to search for a nearby city and simply uses the location position and as target name the variable d_cityname.

Changing the radius of a target is also easy, simply use:
this setVariable ["d_cityradius", 400]
in the init line of the logic. Default value is 300.

Bonus vehicle positions uses the same concept. But instead of logics it uses markers and x starts with 1 and not with 0.
d_bonus_vec_positions_1 - d_bonus_vec_positions_x
d_bonus_air_positions_1 - d_bonus_air_positions_x
The direction of the markers is also the spawn direction for the bonus vehicles.

The direction of other markers also determines spawn direction for other objects:
d_pos_aihut
d_player_ammobox_pos
d_base_chopper_fac
d_base_wreck_fac
d_base_jet_fac
d_bonus_create_pos
(the ACE version has some position markers more for the various boxes)

d_base_marker determines the base. Dom will create the base triggers at the position and direction and size of this marker.

d_island_marker is needed as most of the islands are a way of concerning center positions. AI units which have waypoints outside the normal 0,0 - islandsizex, islandsizey won't move. So this marker helps to find the correct dimensions of the island.

d_isledefense_marker determines the area in which enemy patrols will be created and do their patrol job.

Alpha of all the non empty markers is set to 0 at mission start.


* Added possibility to reserve whatever slots you like for members, based on UIDs.
Check GVAR(uid_reserved_slots) = []; and GVAR(uids_for_reserved_slots) = []; in i_client.sqf

* Infantry groups are reduced now if no players are nearby. Only the leader stays and will do his duties.
The reduce distance can be adjusted in i_server.sqf, GVAR(reduce_distance)
