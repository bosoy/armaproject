================================================================================
Team Status Dialog - v1.3 for ArmA
================================================================================

--------------------------------------------------------------------------------
FEATURES
--------------------------------------------------------------------------------

- Group joining
- Team Leader selection
- Grid of statistics for team/group/vehicle/opposition

--------------------------------------------------------------------------------
PURPOSE
--------------------------------------------------------------------------------

Team Status Dialog for Armed Assault mission designers.

Group joining:
--------------
- You may join another group
- You may start a new empty group with yourself as TL (team leader)

Team Leader selection:
----------------------
- As TL, you may select a replacement TL
- If the current group's TL is an A.I. player, then you may become the new TL

Grid of statistics:
-------------------
The dialog displays your team's group information in 4 formats:
- Team: displays all groups in your team
- Group: displays all members of your group
- Vehicle: displays all groups in your occupied vehicle plus spare seats
- Opposition Team: displays a list of all opposition players but no tactical 
  details, (which you can hide if you don't want it)

These 4 formats are accessed via the 4 buttons: "My team", "My group", 
"My vehicle" & "Opposition".

The columns displayed include:
- Group expand/collapse button
- Group count & player ID
- Group name, player name or vehicle position info
- Vehicle name, vehicle stats (ammo, fuel, etc), vehicle armaments and vehicle ammo
- Seat
- Role/Gear - list of Weapons, equipment & ammo
- MP Score
- Currently issued commands
- Current target
- Requiments - list of requirements for player and/or vehicle
- Current map position grid coordinates
- My proximity - is the player's proximity to you
- Buttons to join/leave group or assign team leaders or invite player/recruit AI or kick player/remove AI

Functionality:
--------------
- The first column has buttons to collapse/expand the group's details.
- The last column has buttons. Group rows allow you to join/leave a group and 
  player rows allow you to assign new team leaders.
- Some columns have drop down lists for extra detail, marked with a "+" in their 
title.
- The base line has buttons to 'Collapse All'/'Expand All' rows.

--------------------------------------------------------------------------------
USAGE
--------------------------------------------------------------------------------

To use the Team Status Dialog in your mission, you can simply access it via the 
Action menu, the Radio menu or any other way. 
To access it via the Action menu, do the following:

- in stringtable.csv file, add a line with:
  #include "Scripts\TeamStatusDialog\stringtable.csv"
Validate that your language columns match: Language,English,German. Adjust/pad as needed.

- copy the "Scripts\TeamStatusDialog" folder to your mission folder

- in your description.ext file, add a line with:
  #include "Scripts\TeamStatusDialog\TeamStatusDialog.hpp"

- in your init.sqf file, add a line with:
  _Action = player addAction [
    "Team Status", 
    "Scripts\TeamStatusDialog\TeamStatusDialog.sqf", 
    [
      ["Page", "Team"], // Page to show initially (only include 1 of these 4 "Page" options)
      //["Page", "Group"],
      //["Page", "Vehicle"],
      //["Page", "Opposition"],
      "ShowAIGroups", // AI are excluded by default, but can be included with this option.
      "AllowAIRecruitment", // Place-holder code: Allow AI players to be recruited into your group from other AI groups
      "AllowPlayerInvites" // Place-holder code: Invite another real player into your group. Currently only sends a chat message.
      /*
      ['VehicleObject', _vehicle], // usually use this with ["Page", "Vehicle"] option, good for use when in/outside of vehicle
      // you can include 1 or more of these "Hide" options to hide a particular page & button
      "HideTeam", // hide 'team' page & button
      "HideGroup", // hide 'group' page & button
      "HideVehicle", // hide 'vehicle' page & button
      "HideOpposition", // hide 'opposition' page & button
      "HideIcons", // hide icons used for vehicles & weapons lists
      "DeleteRemovedAI", // Upon removing an AI player from your group, delete the AI player
      "AllowAILeaderSelect", // Allow player to select an AI player as new leader, otherwise only real players can be selected
      "CloseOnKeyPress", // Close the dialog upon pressing any key.
      */ 
    ], 
    0, false, true, "" ];

  - The "Page" parameter can be left out or used with "Team", "Group", "Vehicle" or 
    "Opposition" to force the default view to the specified page.

  - The "HideOpposition" parameter will hide the Opposition button to prevent 
    viewing the Opposition page.

Other examples are included in the sample mission.

The dialog should now appear whenever you select the "Team Status" option from 
the Action menu.

--------------------------------------------------------------------------------
MODIFYING THE FILES
--------------------------------------------------------------------------------

Note! If you need to do any modifications to the Team Status Dialog files 
included with your mission, please mark the modified files as modified by you to 
avoid confusing them with the originals and note them as "modified" in your 
release documentation.

--------------------------------------------------------------------------------
VERSION HISTORY
--------------------------------------------------------------------------------

Version | Date | Notes

0.1 | 19 Mar 2007 | First beta release - mostly functional but requires a cosmetic tidy up.
1.0 | 23 Mar 2007 | First full release - added group joining, TL selection, Opp Team page, Targets column, colour scheme, fix comboList transparency, some new parameters
1.1 | 10 Jun 2007 | new params, multiple language support, vehicle armaments and status stats, new icons, altered & new group joining actions, rank, clear BG, combined/deleted columns, new addAction syntax, expand/collapse all groups
1.2 |  2007/2008  | included German string table, new param: "ShowAIGroups", switched to pos2grid.cpp, used fn_groupChat, #defines used for all constants (instead of variables)
1.3 | 06 Nov 2008 | isolated functionality into one single folder, no external calls, deleted all 'common functions', scripts and unused functions, tagged all internal functions (TSD9_/ICE_).

--------------------------------------------------------------------------------
LIMITATIONS
--------------------------------------------------------------------------------
- pos2grid.cpp needs to be updated for each new island.

--------------------------------------------------------------------------------
CREDITS
--------------------------------------------------------------------------------

Contributors: Dr_Eyeball
Schwab - for German string table translations
Spinor & other CoC CEX developers - for pos2grid.cpp (modified)

--------------------------------------------------------------------------------
BIS Forum Topic
--------------------------------------------------------------------------------
http://www.flashpoint1985.com/cgi-bin/ikonboard311/ikonboard.cgi?act=ST;f=71;t=60075
