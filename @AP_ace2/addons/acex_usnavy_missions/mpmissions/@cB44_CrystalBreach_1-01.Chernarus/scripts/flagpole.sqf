[] execVM "scripts\viewdis\otfgfx_scripts.sqf";
_this addAction ["Settings", "scripts\settings.sqf", [], 0];
_this addAction ["Team Status", "scripts\TeamStatusDialog\TeamStatusDialog.sqf",
    [
      ["Page", "Team"], // Page to show initially (only include 1 of these 4 "Page" options)
      //["Page", "Group"],
      //["Page", "Vehicle"],
      //["Page", "Opposition"],
      "ShowAIGroups", // AI are excluded by default, but can be included with this option.
      "AllowAIRecruitment", // Place-holder code: Allow AI players to be recruited into your group from other AI groups
      "AllowPlayerInvites", // Place-holder code: Invite another real player into your group. Currently only sends a chat message.
      /*
      ['VehicleObject', _vehicle], // usually use this with ["Page", "Vehicle"] option, good for use when in/outside of vehicle
      // you can include 1 or more of these "Hide" options to hide a particular page & button
      "HideTeam", // hide 'team' page & button
      "HideGroup", // hide 'group' page & button
      "HideVehicle", // hide 'vehicle' page & button*/
      "HideOpposition", // hide 'opposition' page & button
      /*"HideIcons", // hide icons used for vehicles & weapons lists
      "DeleteRemovedAI", // Upon removing an AI player from your group, delete the AI player
      "AllowAILeaderSelect", // Allow player to select an AI player as new leader, otherwise only real players can be selected*/
      "CloseOnKeyPress" // Close the dialog upon pressing any key.
    ],
    0];