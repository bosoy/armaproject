player createDiaryRecord ["Diary", ["Intel Report", "After initial attack the Takistani Army retreated East of Zargabad , but shortly after they were replaced by Militiamen , now HQ wants your unit to push trough the town securing three objectives :<br/><br/>
ALPHA - Secure the airfield for our air force<br/>
BRAVO - Find and destroy ordnance stash , used to build improvised explosive devices.<br/>
CHARLIE - Collect high value intel and secure the villa for new HQ.<br/><br/>
We have reports of radio controlled explosive devices used by militiamen in the past so any unusual sounds/noises can be an evidence of activation of such a device. "]];







////obj charlie

tskcharlie = player createSimpleTask["Secure Intel"];
tskcharlie setSimpleTaskDescription ["Search and collect high value files and clear the villa of enemy units", "Secure Intel", "Objective CHARLIE"];
tskcharlie setSimpleTaskDestination (getMarkerPos "charlie");

////obj bravo

tskbravo = player createSimpleTask["Destroy Ordnance Stash"];
tskbravo setSimpleTaskDescription ["Search and destroy ordnance stash used to create IEDs", "Destroy Ordnance Stash", "Objective BRAVO"];
tskbravo setSimpleTaskDestination (getMarkerPos "bravo");

////obj alpha

tskalpha = player createSimpleTask["Secure Airfield"];
tskalpha setSimpleTaskDescription ["Clear the airfield area of any enemy units.", "Secure The Airfield", "Objective ALPHA"];
tskalpha setSimpleTaskDestination (getMarkerPos "alpha");
