waitUntil {!(isNull player)};
waitUntil {player==player};

if (!isServer OR !isMultiplayer) exitWith{};

  skipTime (paramsArray select 0);  // SKIP TIME TO DESIRED START HOUR

if (true) exitWith{};