// ACE_SYS_SA (Contains all current sight settings and the list of previously used launchers with their last range setting)

#define ACE_SYS_SA_NEW [false, objNull, "", 0, 0, 0, 0, 0, 0, 0, [], []]

#define ACE_SYS_SA_INDEX_ENABLED                    	0
#define ACE_SYS_SA_INDEX_CURUNIT                    	1
#define ACE_SYS_SA_INDEX_CURWEAPON                  	2
#define ACE_SYS_SA_INDEX_CURELEVATION               	3
#define ACE_SYS_SA_INDEX_CURELEVATION_DEG               4
#define ACE_SYS_SA_INDEX_FIREDEH                  	5
#define ACE_SYS_SA_INDEX_DEFAULTELEVATION        	6
#define ACE_SYS_SA_INDEX_MINELEVATION			7
#define ACE_SYS_SA_INDEX_MAXELEVATION          		8
#define ACE_SYS_SA_INDEX_ADJELEVATION              	9
#define ACE_SYS_SA_INDEX_AT_LIST              		10
#define ACE_SYS_SA_INDEX_TABLE              		11


#define ACE_SYS_SA_ENABLED                          	(ACE_SYS_SA_AT select ACE_SYS_SA_INDEX_ENABLED)
#define ACE_SYS_SA_CURUNIT                          	(ACE_SYS_SA_AT select ACE_SYS_SA_INDEX_CURUNIT)
#define ACE_SYS_SA_CURWEAPON                        	(ACE_SYS_SA_AT select ACE_SYS_SA_INDEX_CURWEAPON)
#define ACE_SYS_SA_CURELEVATION                     	(ACE_SYS_SA_AT select ACE_SYS_SA_INDEX_CURELEVATION)
#define ACE_SYS_SA_CURELEVATION_DEG                     (ACE_SYS_SA_AT select ACE_SYS_SA_INDEX_CURELEVATION_DEG)
#define ACE_SYS_SA_FIREDEH                          	(ACE_SYS_SA_AT select ACE_SYS_SA_INDEX_FIREDEH)
#define ACE_SYS_SA_DEFAULTELEVATION                     (ACE_SYS_SA_AT select ACE_SYS_SA_INDEX_DEFAULTELEVATION)
#define ACE_SYS_SA_MINELEVATION                         (ACE_SYS_SA_AT select ACE_SYS_SA_INDEX_MINELEVATION)
#define ACE_SYS_SA_MAXELEVATION                     	(ACE_SYS_SA_AT select ACE_SYS_SA_INDEX_MAXELEVATION)
#define ACE_SYS_SA_ADJELEVATION                     	(ACE_SYS_SA_AT select ACE_SYS_SA_INDEX_ADJELEVATION)
#define ACE_SYS_SA_AT_LIST                         	(ACE_SYS_SA_AT select ACE_SYS_SA_INDEX_AT_LIST)
#define ACE_SYS_SA_TABLE                         	(ACE_SYS_SA_AT select ACE_SYS_SA_INDEX_TABLE)

#define ACE_SYS_SA_SET_ENABLED(value)               	ACE_SYS_SA_AT set [ACE_SYS_SA_INDEX_ENABLED, ##value]
#define ACE_SYS_SA_SET_CURUNIT(value)              	ACE_SYS_SA_AT set [ACE_SYS_SA_INDEX_CURUNIT, ##value]
#define ACE_SYS_SA_SET_CURWEAPON(value)             	ACE_SYS_SA_AT set [ACE_SYS_SA_INDEX_CURWEAPON, ##value]
#define ACE_SYS_SA_SET_CURELEVATION(value)          	ACE_SYS_SA_AT set [ACE_SYS_SA_INDEX_CURELEVATION, ##value]
#define ACE_SYS_SA_SET_CURELEVATION_DEG(value)          ACE_SYS_SA_AT set [ACE_SYS_SA_INDEX_CURELEVATION_DEG, ##value]
#define ACE_SYS_SA_SET_FIREDEH(value)              	ACE_SYS_SA_AT set [ACE_SYS_SA_INDEX_FIREDEH, ##value]
#define ACE_SYS_SA_SET_DEFAULTELEVATION(value)          ACE_SYS_SA_AT set [ACE_SYS_SA_INDEX_DEFAULTELEVATION, ##value]
#define ACE_SYS_SA_SET_MINELEVATION(value)              ACE_SYS_SA_AT set [ACE_SYS_SA_INDEX_MINELEVATION, ##value]
#define ACE_SYS_SA_SET_MAXELEVATION(value)              ACE_SYS_SA_AT set [ACE_SYS_SA_INDEX_MAXELEVATION, ##value]
#define ACE_SYS_SA_SET_ADJELEVATION(value)              ACE_SYS_SA_AT set [ACE_SYS_SA_INDEX_ADJELEVATION, ##value]
#define ACE_SYS_SA_SET_AT_LIST(value)              	ACE_SYS_SA_AT set [ACE_SYS_SA_INDEX_AT_LIST, ##value]
#define ACE_SYS_SA_SET_TABLE(value)              	ACE_SYS_SA_AT set [ACE_SYS_SA_INDEX_TABLE, ##value]
